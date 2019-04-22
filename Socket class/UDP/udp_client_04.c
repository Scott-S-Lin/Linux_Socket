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
    struct sockaddr_in sa, sa2;
    char data[100];
    int ret;

    if( (sock=socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) /* PF_INET */
    {
        perror("socket()");
        return -1;
    }

    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(12345);
    sa.sin_addr.s_addr = inet_addr(argv[1]);

	sprintf(data, "This is a test message.");
	sendto(sock, data, strlen(data)+1, 0,
		            (struct sockaddr*)&sa, sizeof(sa));
		
    close(sock);    
    return 0;
}

