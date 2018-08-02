#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIX
#include <CAENHVWrapper.h>
#include <watchHV.h>

int main(int argc, char *argv[])
{
	// turn each channel ON or OFF

	int res = -1, toggle = 0;

	if (argc != 2) { printf("Number of arguments given does not match number of arguments expected (2).\n"); }
	else { toggle = (int)argv[1]; } // #TODO need to figure out how to properly cast or incorporate passing arg into shell script or 2 if statements

	for (ushort chNum = 0; chNum <= 3; chNum++)
	{
		res = togglePower(chNum, toggle);
		if (res == 0 && toggle = 1) { printf("Successfully turned ON Ch %d\n", chNum); }
		else if (res == 0 && toggle = 0) { printf("Successfully turned OFF Ch %d\n", chNum); }
		else
		{ 
			printf("ERROR: Unsuccessful communication with power supply");
			return -1;
		}
	}

	return res;
}
