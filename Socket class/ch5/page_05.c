#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadA(void *arg);

int main(int argc, char *argv[])
{
	int i;
	pthread_t idA, idB;
	
	pthread_create(&idA, NULL, threadA, NULL);
	pthread_create(&idB, NULL, threadA, NULL);
    
	for(i=0; i<5; i++){
		printf("I am main thread. i=%d\n", i);
		sleep(2);
	}

    pthread_exit(NULL);
    //pthread_join(idA, NULL); 
    //exit(0);
	//return 0;
}


void *threadA(void *arg)
{
	int i;

	for(i=0; i<5; i++){
		printf("\tI am threadA. i=%d\n", i);
		sleep(1);
	}

    printf("\tthreadA ends\n");
    pthread_exit(NULL);
}


