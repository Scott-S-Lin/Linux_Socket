#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	FILE *fout;
	int i;

    if( mkfifo("/tmp/my_fifo", 0777) != 0 )
        perror("mkfifo()");

	if( (fout=fopen("/tmp/my_fifo", "w")) == NULL ){
        perror("fopen()");
        exit(0);
	}

	for(i=0; i<1000; i++){
		fprintf(fout,"%d\n",i);
		//fflush(fout);
		//sleep(1);
		printf("%d\n", i);
	}

	fclose(fout);
    exit(0);
}

