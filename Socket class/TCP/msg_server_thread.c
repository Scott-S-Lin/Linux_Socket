#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

void* mythread(void*);

int main(int argc, char *argv[])
{
    int sockServer, sockClient;
    struct sockaddr_in sa;

    if( (sockServer=socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("socket()");
        return -1;
    }
    
    sa.sin_family = AF_INET;
    sa.sin_port = htons(12345);
    sa.sin_addr.s_addr = inet_addr("0.0.0.0");

    if( bind(sockServer, (struct sockaddr*)&sa, sizeof(sa)) < 0 )
    {
        perror("bind()");
        return -1;
    }

    if ( listen(sockServer, 5) < 0 )
    {
        perror("listen()");
        return -1;
    }

    while(1)
    {
        pthread_t pth;

        if( (sockClient=accept(sockServer, NULL, NULL)) < 0 )
        {
            perror("accept()");
            return -1;
        }
       
        pthread_create(&pth, NULL, mythread, (void*)&sockClient);
    }

    close(sockServer);    
    return 0;
}

void* mythread(void *arg)
{
    char data[100];
    int newSock = *((int*)arg);

    while(1)
    {
        if( recv(newSock, data, sizeof(data), 0) != sizeof(data) )
        {
            perror("recv()");
            pthread_exit(NULL);
        }

        printf("%s", data);
    }

    close(newSock);
    pthread_exit(NULL);
}

