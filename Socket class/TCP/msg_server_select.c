#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <pthread.h>

void* mythread(void*);
#define MAX_CLIENT 2
int sockClient[MAX_CLIENT];

int main(int argc, char *argv[])
{
    int sockServer, newSock;
    struct sockaddr_in sa;
    pthread_t pth;
    int i;

    for(i=0; i<MAX_CLIENT; i++)
        sockClient[i] = -1;

    if(pthread_create(&pth, NULL, mythread, NULL)!=0)
    {
        perror("pthread_create()");
        return -1;
    }

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

    while( (newSock=accept(sockServer, NULL, NULL)) >= 0)
    {
        for(i=0; i<MAX_CLIENT; i++)
            if( sockClient[i] < 0 )
            {
                sockClient[i] = newSock;
                printf("add sockClient[%d] %d\n", i, newSock);
                break;
            }
    }

    close(sockServer);    
    return 0;
}

void* mythread(void *arg)
{
    char data[100];
    int ready;
    fd_set readfds;
    struct timeval timeout;
    int i, maxID;

    while(1)
    {
        FD_ZERO(&readfds);
        maxID = sockClient[0];

        for(i=0; i<MAX_CLIENT; i++)
        {
            if( sockClient[i] < 0 )
               continue;

            FD_SET(sockClient[i], &readfds);

            if(sockClient[i]>maxID)
                maxID = sockClient[i];
        }

        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        switch((ready=select(maxID+1, &readfds, NULL, NULL, &timeout)))
        {
        case -1:
            perror("select()");
            goto Error_mythread;
        case 0:
            //printf("select() timeout\n");
            break;
        default:
            for(i=0; i<MAX_CLIENT; i++)
            {
                if( sockClient[i] < 0 )
                    continue;

                if( FD_ISSET(sockClient[i], &readfds) )
                {
                    if( recv(sockClient[i], data, sizeof(data), 0) == sizeof(data) )
                        printf("%s", data);
                    else
                    {
                        perror("recv()");
                        close(sockClient[i]);
                        sockClient[i] = -1;
                    }
            
                }
            }
            break;
        }//switch(select())
    }//while(1)

Error_mythread:
    pthread_exit(NULL);
}

