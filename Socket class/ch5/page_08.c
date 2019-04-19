#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadA(void *arg);
void *threadB(void *arg);

int value=1;

int main(int argc, char *argv[])
{
	int i;
    pthread_t thIDA, thIDB;

    pthread_create(&thIDA, NULL, threadA, NULL);
    pthread_create(&thIDB, NULL, threadB, NULL);
    
	pthread_join(thIDA, NULL);
	pthread_join(thIDB, NULL);

	printf("final value = %d\n", value);
    exit(0);
}

void *threadA(void *arg)
{
	int i;

	for(i=0; i<100000000; i++)
		value++;

    pthread_exit(NULL);
}

void *threadB(void *arg)
{
	int i;

	for(i=0; i<100000000; i++)
		value--;

    pthread_exit(NULL);
}

