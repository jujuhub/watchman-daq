#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIX
#include <CAENHVWrapper.h>
#include <watchHV.h>

int main(int argc, char *argv[])
{
	// sets voltage of a channel

	int res = -1;
	float VSet = 0.;

	if (argc != 3)
	{
		printf("ERROR: Invalid voltage input \nSYNTAX: program chNum VSet\n");
		exit(0);
	}
	else { VSet = strtod(argv[2]); } // TODO work with shell scripts? or if conditions?

	res = setChVoltage(argv[1], VSet);
	return res;
}
