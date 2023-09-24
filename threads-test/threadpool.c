#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define THREAD_NUM 4


typedef struct Task {
	int a,b; /* Add two varibales as task */
}Task;

Task taskqueue[256];

int taskCount = 0;

pthread_mutex_t mutexQueue;

void executeTask(Task* task)
{
	int result = task -> a + task -> b;
	printf("%d + %d = %d\n", task -> a, task -> b, result);
}

void submitTask()
{
	pthread_mutex_lock(&mutexQueue);
	taskqueue[taskCount] = task;
	taskCount++;
	pthread_mutex_unlock(&mutexQueue);
}

void* start_thread(void* arg)
{
	while(1){
		Task task;
		int found = 0;
		pthread_mutex_lock(&mutexQueue);
		task = taskqueue[0];
		if (taskCount > 0) {
			found = 1;
			for (int i = 0; i < taskCount - 1; i++) {
				taskqueue[i] = taskqueue[i + 1];
			}
			taskCount--;
		}
		pthread_mutex_unlock(&mutexQueue);
		if(found == 1)
			executeTask(&task);
	}
}

int main(int argc, char *argv[])
{


	Task t1 = {
		.a = 5,
		.b = 10,
	};
	/* Similar to t1.a = 5 and t1.b = 5 */

	executeTask(&t1);

	pthread_t th[THREAD_NUM];
	pthread_mutex_init(&mutexQueue, NULL);
	for(int i = 0; i < THREAD_NUM; ++i){
		if(pthread_create(&th[i], NULL, start_thread,NULL) != 0)
			perror("Failed to create thread");
	}

	for (int i = 0; i < THREAD_NUM; ++i) {
		if(pthread_join(th[i], NULL) !=0)
			perror("Failed to join thread\n");
	}
	pthread_mutex_destroy(&mutexQueue);
	return 0;
}
