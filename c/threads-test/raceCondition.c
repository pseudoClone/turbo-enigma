#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define BIG 1000000UL


_Atomic uint64_t counter = 0;

void count_to_big()
{
	for (int i = 0; i < BIG; ++i) {
		counter+= i;
	}
}

void* threadfunc(void* arg)
{
	count_to_big();
	return NULL;
}


int main(int argc, char *argv[])
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,threadfunc,NULL);
	pthread_create(&t2, NULL, threadfunc, NULL);

	pthread_join(t1,NULL);
	pthread_join(t2, NULL);

	printf("The result is %lu\n", counter);
	return 0;
}
