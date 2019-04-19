#include <stdio.h>
#include <sys/select.h>

int main(int argc, char *argv[])
{
    int nfds, ready;
    fd_set readfds;
    struct timeval timeout;

    while(1)
    {
        nfds = 0 + 1;           //0:stdin
        FD_ZERO(&readfds);
        FD_SET(0, &readfds);    //0:stdin

        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        ready = select(nfds, &readfds, NULL, NULL, &timeout);
        switch(ready){
        case -1:
            perror("select()");
            return -1;
        case 0:
            printf("select() timeout\n");
            break;
        default:
            if( FD_ISSET(0, &readfds) ){        //0:stdin
                printf("now can read stdin\n");
                while( getchar() != '\n' )
                    ;
            }
            break;
        }
    } //while(1)

    return 0;
}

