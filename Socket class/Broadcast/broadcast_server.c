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
    int optval;
    struct sockaddr_in sa, saFrom;
    char buffer[100];
    int ret;
    socklen_t saFromLen;

    if( (sock=socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
    {
        perror("socket()");
        return -1;
    }

    optval = 1;
    if( setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,
                   &optval, sizeof(optval)) != 0 )
    {
        perror("setsockopt()");
        return -1;
    }

    sa.sin_family = AF_INET;
    sa.sin_port = htons(12345);
    sa.sin_addr.s_addr = inet_addr("0.0.0.0");

    if( bind(sock, (struct sockaddr*)&sa, sizeof(sa)) < 0 )
    {
        perror("bind()");
        return -1;
    }

    while(1)
    {
        saFromLen = sizeof(saFrom);
        if( (ret=recvfrom(sock, (void*)buffer, sizeof(buffer)-1, 0,
                          (struct sockaddr*)&saFrom, &saFromLen)) < 0 )
        {
            perror("recvfrom()");
            return -1;
        }
        buffer[ret] = '\0';
		
        printf("client = 0x%08x, %s\n", saFrom.sin_addr.s_addr, inet_ntoa(saFrom.sin_addr));
        printf("data = %s\n", buffer);

        sendto(sock, buffer, strlen(buffer)+1, 0,
                (struct sockaddr*)&saFrom, sizeof(saFrom));
    }
    
    close(sock);    
    return 0;
}

