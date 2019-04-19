#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[ ])
{
    FILE *read_fp;
    char buffer[1000];
    int chars_read;
    
    read_fp = popen("uname -a", "r");
    if (read_fp != NULL) {
        chars_read = fread(buffer, sizeof(char), sizeof(buffer)-1, read_fp);
        if (chars_read > 0) {
            buffer[chars_read] = '\0';
            printf("Output was:-\n%s\n", buffer);
        }
        pclose(read_fp);
    }
    exit(0);
}

