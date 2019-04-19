#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	
	fp = fopen("/etc/wpa_supplicant/wpa_supplicant.conf", "a");
	fprintf(fp, "\nnetwork={\n ssid=\"%s\"\n psk=\"%s\"\n}\n", argv[1], argv[2]);
	fclose(fp);	
		
	system("wpa_cli -i wlan0 reconfigure");
	
	return 0;
}

