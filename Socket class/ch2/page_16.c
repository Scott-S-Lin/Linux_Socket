#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct tm *tm_ptr, tm_my;
    time_t the_time;

    time(&the_time);
    tm_ptr = localtime(&the_time);
    
    printf("Raw time is %ld\n", the_time);
    printf("Broken-down time is %d-%02d-%02d %02d:%02d:%02d\n",
			 tm_ptr->tm_year+1900, tm_ptr->tm_mon+1, tm_ptr->tm_mday,
			 tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

    time(&the_time);
    localtime_r(&the_time, &tm_my);
	printf("sec=%d\n", tm_my.tm_sec);
				 
    exit(0);
}

