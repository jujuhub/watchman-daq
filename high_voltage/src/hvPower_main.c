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
	else { toggle = (int)argv[1]; } // #TODO need to figure out how to properly cast / incorporate passing str arg into shell script / 2 if statements with or conditions

	for (ushort chNum = 0; chNum <= 3; chNum++)
	{
		res = togglePower(chNum, toggle);
		if (res == 0 && toggle = 1) { printf("CH %d: Successfully turned ON\n", chNum); }
		else if (res == 0 && toggle = 0) { printf("CH %d: Successfully turned OFF\n", chNum); }
		else { printf("ERROR: Unsuccessful communication with power supply"); }
	}

	return res;
}
