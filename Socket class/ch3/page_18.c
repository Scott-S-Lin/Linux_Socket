#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void ouch(int sig)
{
    printf("got signal %d\n", sig);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, ouch);
    
    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }
    
	exit(0);
}

