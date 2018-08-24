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
	char *ptr = NULL;
//	ushort chNum = 0;

	if (argc != 3)
	{
		printf("ERROR: Invalid voltage input \nSYNTAX: sudo ./program chNum VSet\n");
		exit(0);
	}
	else
	{
		VSet = strtod(argv[2], &ptr);
	}
	printf("Setting Ch %d VSet to %fV\n", atoi(argv[1]), VSet);

	res = setChVoltage((ushort)atoi(argv[1]), VSet);
	return res;
}
