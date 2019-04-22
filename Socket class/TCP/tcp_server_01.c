#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockServer, sockClient;
    struct sockaddr_in sa;
    char c;

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
		if( (sockClient=accept(sockServer, NULL, NULL)) < 0 )
		{
		    perror("accept()");
		    return -1;
		}
   
		if( recv(sockClient, &c, sizeof(c), 0) == sizeof(c) )
		    printf("%d\n", c);
		else
		{
		    perror("recv()");
		    return -1;
		}

		c++;
		send(sockClient, &c, sizeof(c), 0);
		
    	close(sockClient);
    }

    close(sockServer);    
    return 0;
}

