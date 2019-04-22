#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in sa;
    unsigned char buf[1000000];
    int ret;

    if( (sock=socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("socket()");
        return -1;
    }

    sa.sin_family = AF_INET;
    sa.sin_port = htons(12345);
    sa.sin_addr.s_addr = inet_addr(argv[1]);

    if ( connect(sock, (struct sockaddr*)&sa, sizeof(sa)) < 0 )
    {
        perror("connect()");
        return -1;
    }

    while(1)
    {
    	ret = send(sock, buf, 100, 0);
        printf("%d\n", ret);
    }

    close(sock);    
    return 0;
}

