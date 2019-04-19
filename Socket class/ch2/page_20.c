#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define A_MEGABYTE (1024 * 1024)

int main(int argc, char *argv[])
{
    char *some_memory;
    int i;
    
    some_memory = (char*)malloc(A_MEGABYTE);
    	
    if (some_memory) {
        sprintf(some_memory, "Hello World\n");
        printf("%s", some_memory);
    }
    free(some_memory);
    
    exit(0);
}

