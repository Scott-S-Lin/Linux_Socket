#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

int open_port(char *portname)
{
    int fd;
    struct termios term;

	if( (fd=open(portname, O_RDWR|O_NOCTTY)) < 0 ){
   		perror("open()");
   		return -1;
	}
	
	memset(&term, 0, sizeof(term));
	
    term.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
    term.c_cc[VMIN] = 1;
	
	if( tcsetattr(fd,TCSAFLUSH,&term) == -1 ){
        perror("tcsetattr()");
   		return -1;
	}

    return fd;
}

int main(int argc, char *argv)
{
    int fd;
    int c;
    int ret;

    if( (fd=open_port("/dev/ttyUSB0")) < 0 )
        return -1;
        
    while(1)
    {
    	if( read(fd, &c, 1) == 1 )
        	write(1, &c, 1);        	
    }

    return 0;
}


