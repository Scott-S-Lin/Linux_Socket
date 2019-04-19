#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[ ])
{
    FILE *read_fp;
    char buffer[1000];
    int chars_read;
    char mac[20], ip[20];
    
    read_fp = popen("ifconfig ens33", "r");
    if (read_fp != NULL) {
        /*chars_read = fread(buffer, sizeof(char), sizeof(buffer)-1, read_fp);
        buffer[chars_read] = '\0';        
        sscanf(buffer, "%*s %*s %*s %*s %s %*s addr:%s", mac, ip);*/
        
        fscanf(read_fp, "%*s %*s %*s %*s %s %*s addr:%s", mac, ip);
        
        printf(" ip = %s \n mac = %s \n", ip, mac);
        
        pclose(read_fp);
    }
    exit(0);
}

