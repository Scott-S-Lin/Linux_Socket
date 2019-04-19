#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int debug=0;

void MySIGUSR1(int sig)
{
    //printf("got signal %d\n", sig);
	debug = !debug;
}

int main(int argc, char *argv[])
{
    signal(SIGUSR1, MySIGUSR1);
    
    while(1) {
		if(debug)
        	printf("Hello World!\n");

        sleep(1);
    }

	exit(0);
}

