#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    printf("start: ppid=%d \t pid=%d \n", getppid(), getpid());

    if(argc>1){
        int n = atoi(argv[1]);
        
        while( --n )
            if( !(fork()>0) ) //or if( !(fork()==0) )
                break;
    }

    while(1){
        sleep(1);
        printf("ppid=%d \t pid=%d \n", getppid(), getpid());
    }

    exit(0);
}

