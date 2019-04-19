#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    time_t timeA, timeB;
    
    timeA = time(NULL);
    printf("The time is %ld\n", timeA);

    sleep(2);

    time(&timeB);
    printf("The time is %ld\n", timeB);

    exit(0);
}

