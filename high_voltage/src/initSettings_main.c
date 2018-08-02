#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIX
#include <CAENHVWrapper.h>
#include <watchHV.h>

int main()
{
	// set params to default values
	// options: ISet, MaxV, RUp, RDwn, Trip

	int res = -1;

	for (ushort chNum = 0; chNum <= 3; chNum++)
	{
		// ISet; default: 200. uA
		res = initSettings(chNum, "ISet", 200.);
		sleep(2);
		if (res == 0)
		{ 
			printf("Successfully set ISet to 200. uA for Ch %d\n", chNum);
		}
	}

	for (ushort chNum = 0; chNum <= 3; chNum++)
	{
		// MaxV; default: 1800. V
		res = initSettings(chNum, "MaxV", 1800.);
		sleep(2);
		if (res == 0)
		{ 
			printf("Successfully set MaxV to 1800. V for Ch %d\n", chNum);
		}
	}

	for (ushort chNum = 0; chNum <= 3; chNum++)
	{
		// RUp; default: 100. V/s
		res = initSettings(chNum, "RUp", 100.);
		sleep(2);
		if (res == 0)
		{ 
			printf("Successfully set RUp to 100. V/s for Ch %d\n", chNum);
		}
	}

	for (ushort chNum = 0; chNum <= 3; chNum++)
	{
		// RDwn; default: 150. V/s
		res = initSettings(chNum, "RDwn", 150.);
		sleep(2);
		if (res == 0)
		{ 
			printf("Successfully set RDwn to 150. V/s for Ch %d\n", chNum);
		}
	}

	return res;
}
