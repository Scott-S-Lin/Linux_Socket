#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	FILE *fp;
    int sock;
    struct sockaddr_in sa;
    unsigned char block[1000];
    int ret, nread;

    fp = fopen(argv[1], "r");
    
    if( (sock=socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("socket()");
        return -1;
    }

    sa.sin_family = AF_INET;
    sa.sin_port = htons(12345);
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");

    if ( connect(sock, (struct sockaddr*)&sa, sizeof(sa)) < 0 )
    {
        perror("connect()");
        return -1;
    }

    while( (nread = fread(block,1,sizeof(block),fp)) > 0 )
    {
		ret = send(sock, block, nread, 0);
		printf("%d\n", ret);
	}	

    close(sock);    
    return 0;
}

