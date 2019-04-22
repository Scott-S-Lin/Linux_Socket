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
    struct sockaddr_in sa, saClient;
    char data[100];
    socklen_t saLength;
    int ret;

    if( (sock=socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
    {
        perror("socket()");
        return -1;
    }

    memset(&sa, 0, sizeof(sa));
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
        saLength = sizeof(saClient);
        ret = recvfrom(sock, data, sizeof(data)-1, 0,
                        (struct sockaddr*)&saClient, &saLength);
        data[ret] = '\0';
        printf("%s: %s\n", inet_ntoa(saClient.sin_addr), data);
    }
    
    close(sock);    
    return 0;
}

