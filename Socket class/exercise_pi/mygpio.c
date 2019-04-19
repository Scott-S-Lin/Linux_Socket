#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char ip[20] = "192.168.6.108";
	FILE *fp;
	int value;
	
	system("echo 22 > /sys/class/gpio/export");
	system("echo out > /sys/class/gpio/gpio22/direction");
	system("echo 1 > /sys/class/gpio/gpio22/value");
	
	system("echo 23 > /sys/class/gpio/export");
	system("echo in > /sys/class/gpio/gpio23/direction");
	
	system("echo 5 > /sys/class/gpio/export");
	system("echo out > /sys/class/gpio/gpio5/direction");
	
	/*while(1)
	{
		usleep(10000);
		
		fp = fopen("/sys/class/gpio/gpio23/value", "r");
		fscanf(fp, "%d", &value);
		fclose(fp);
	
		printf("%d\n", value);
	}*/
	
	/*value = 0;
	while(1)
	{
		usleep(500000);
		
		value = !value;
		
		fp = fopen("/sys/class/gpio/gpio5/value", "w");
		fprintf(fp, "%d", value);
		fclose(fp);
	}*/	
	
	return 0;
}
	
