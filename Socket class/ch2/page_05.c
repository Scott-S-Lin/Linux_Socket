#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
    int fp = open("no_this_file", 0);

    if(fp<0)
        perror("open() 7st");

    return 0;
}

