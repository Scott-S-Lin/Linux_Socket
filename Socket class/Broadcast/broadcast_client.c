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
    struct sockaddr_in sa;
    char buffer[100];
    int ret;

    if( (sock=socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
    {
        perror("socket()");
        return -1;
    }
    
    optval = 1;
    if( setsockopt(sock, SOL_SOCKET, SO_BROADCAST,
                   &optval, sizeof(optval)) != 0 )
    {
        perror("setsockopt()");
        return -1;
    }

    sa.sin_family = AF_INET;
    sa.sin_port = htons(12345);
    sa.sin_addr.s_addr = inet_addr("255.255.255.255");

    fgets(buffer, sizeof(buffer), stdin);
    if ( sendto(sock, buffer, strlen(buffer), 0,
                (struct sockaddr*)&sa, sizeof(sa)) != strlen(buffer) )
    {
        perror("sendto()");
        return -1;
    }

    ret = recvfrom(sock, (void*)buffer, sizeof(buffer)-1, 0, NULL, NULL);
    buffer[ret] = '\0';
    printf("echo: %s\n", buffer);

    close(sock);    
    return 0;
}

