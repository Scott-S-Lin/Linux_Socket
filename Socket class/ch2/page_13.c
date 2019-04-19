#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
	struct timeval tv;
    
	gettimeofday(&tv, NULL);
	printf ("%ld.%06ld\n", tv.tv_sec, tv.tv_usec);

	exit(0);
}

