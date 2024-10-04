#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>



void your_turn()
{
	for(int i = 0; i < 3; ++i) {
		sleep(2);
		printf("Your Turn %d\n",i);
	}
}
// For using threads, functions must return a void pointer and
// must take a void pointer as an argument
void* my_turn(void* arg)
{
	int* iptr = (int*)arg;
	for(int i = 0; i < 8; ++i) {
		sleep(1);
		printf("My Turn %d %d\n",i, *iptr);
		(*iptr)++;
	}
	return NULL;
}



int main(int argc, char *argv[])
{
	int v = 0;
	pthread_t newthread;
	pthread_create(&newthread, NULL, my_turn, &v); // Runs on seperate thread
	your_turn();
	pthread_join(newthread, NULL);
	printf("Thread job done\nValue of v: %d\n",v);
	return 0;
}
