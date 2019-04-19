#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char buf[100];
    int flags;

    flags = fcntl(0, F_GETFL);  /* 0:stdin */
    flags |= O_NONBLOCK;	  /* Enable O_NONBLOCK bit */
    fcntl(0, F_SETFL, flags);

    while(1)
    {
        sleep(1);

        if(read(0, buf, 100)>0)
            printf("got input\n");
        else
        {
			//perror("read() else");
            printf("no input\n");
		}
    }

    return 0;
}

