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
	int* iptr = (int*)malloc(sizeof(int));
	*iptr = 0; /*Setting initial value */
	for(int i = 0; i < 8; ++i) {
		sleep(1);
		printf("My Turn %d %d\n",i, *iptr);
		(*iptr)++;
	}
	return iptr; //Implicit cast to void since the function returns void
}



int main(int argc, char *argv[])
{
	// int v = 0;
	int* result; // This will be pointer to the the returned value which is a pointer

	pthread_t newthread;
	pthread_create(&newthread, NULL, my_turn, NULL); // Runs on seperate thread
	your_turn();
	// pthread_join(newthread, (void *)&result); // &result thus creating a pointer to pointer
	printf("Thread job done\nReturn value is: %d\n",*result);
	return 0;
}
