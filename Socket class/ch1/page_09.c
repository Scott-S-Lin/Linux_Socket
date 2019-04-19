#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char buffer[128];
    int nread;
    
    nread = read(0, buffer, 128);
    write(1, buffer, nread);
    
    exit(0);
}

