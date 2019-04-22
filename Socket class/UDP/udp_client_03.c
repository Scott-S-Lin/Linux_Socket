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
    int i;
    unsigned char data[100];
      
    if( (sock=socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) /* PF_INET */
    {
        perror("socket()");
        return -1;
    }

    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(12345);
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");

    for(i=0; i<100; i++)
    	data[i] = i;
    	
    if ( sendto(sock, data, sizeof(data), 0,
                (struct sockaddr*)&sa, sizeof(sa)) != sizeof(data) )
    {
        perror("sendto()");
        return -1;
    }
		
    close(sock);    
    return 0;
}

