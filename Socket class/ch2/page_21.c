#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	char *block;
    int in, out;
	int nread, blockSize;
	time_t t1, t2;
	
	blockSize = atoi(argv[3]);
	//sscanf(argv[3], "%d", &blockSize);
	block = (char*)malloc(blockSize);
    
    in = open(argv[1], O_RDONLY);
    out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

    t1 = time(NULL);
    
    while( (nread=read(in,block,blockSize)) > 0 )
        write(out, block, nread);
        
    t2 = time(NULL);
    
    printf("t2-t1=%ld\n", t2-t1);
        
    close(in);
    close(out);        
    exit(0);
}

