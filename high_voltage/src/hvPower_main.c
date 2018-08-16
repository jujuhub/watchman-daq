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
		printf("Number of args given does not match number expected [2].\n");
		exit(1);
	}
	else if (strcmp(argv[1], "ON") == 0) { toggle = 1; }
	else if (strcmp(argv[1], "OFF") == 0) { toggle = 0; }

	printf("toggle = %d\n", toggle);

	for (ushort chNum = 0; chNum <= 3; chNum++)
	{
		res = togglePower(chNum, toggle);
		sleep(2);
//		printf("res = %d\n", res);
		if (res == CAENHV_OK && toggle == 1) { printf("CH %d: Successfully turned ON\n", chNum); }
		else if (res == CAENHV_OK && toggle == 0) { printf("CH %d: Successfully turned OFF\n", chNum); }
		else { printf("ERROR: Unsuccessful communication with power supply\n"); }
	}

	return res;
}
