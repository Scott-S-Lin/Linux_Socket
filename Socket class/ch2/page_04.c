#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    int fp = open("no_this_file", 0);

    if(fp<0)
        printf("%d, %d, %s\n", fp, errno, strerror(errno));

    return 0;
}

