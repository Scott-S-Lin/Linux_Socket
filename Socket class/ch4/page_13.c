#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	FILE *fin;
	int i, value;

    if( mkfifo("/tmp/my_fifo", 0777) != 0 )
        perror("mkfifo()");

	if( (fin=fopen("/tmp/my_fifo", "r")) == NULL ){
        perror("fopen()");
        exit(0);
	}

	for(i=0; i<1000; i++){
	    fscanf(fin,"%d",&value);
	    printf("%d\n", value);
	    sleep(1);
	}
		    
	fclose(fin);
    exit(0);
}

