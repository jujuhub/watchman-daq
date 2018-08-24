#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIX
#include <CAENHVWrapper.h>
#include <watchHV.h>

int main(int argc, char *argv[])
{
	// turn each channel ON or OFF

	int res = -1, toggle = 0;

	if (argc != 2)
	{
		printf("ERROR: Please provide power status [ON/OFF].\n");
		exit(1);
	}
	else if (strcmp(argv[1], "ON") == 0) { toggle = 1; }
	else if (strcmp(argv[1], "OFF") == 0) { toggle = 0; }
	else
	{
		printf("ERROR: Invalid input. Please input \"ON\" or \"OFF\".\n");
		exit(1);
	}

//	printf("toggle = %d\n", toggle);

	for (ushort chNum = 0; chNum <= 3; chNum++)
	{
		res = togglePower(chNum, toggle);
		sleep(2);
//		printf("res = %d\n", res);
		if (res == 1 && toggle == 1) { printf("CH %d: Successfully turned ON\n", chNum); }
		else if (res == 1 && toggle == 0) { printf("CH %d: Successfully turned OFF\n", chNum); }
		else { printf("ERROR: Unsuccessful communication with power supply\n"); }
	}

	return res;
}
