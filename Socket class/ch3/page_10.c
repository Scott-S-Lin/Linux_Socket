#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    char message[100];
    int n;

    printf("fork starting\n");
    pid = fork();

    switch(pid)
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        sprintf(message, "This is the child %d", getpid());
        n = 5;
        break;
    default:
        sprintf(message, "This is the parent %d", getpid());
        n = 3;
        break;
    }

    for( ; n > 0; n--) {
        puts(message);
        sleep(1);
    }

	printf("process %d end\n", getpid());
	
    exit(0);
}

