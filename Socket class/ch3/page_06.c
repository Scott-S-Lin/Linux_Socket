#include <stdlib.h>

int main()
{
    //system("xterm &");	//system("xterm &");
    
    system("xterm -e ping -c 5 192.168.6.1 &");
    
    exit(0);
}

