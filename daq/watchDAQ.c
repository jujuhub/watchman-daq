/* This script contains functions used to automate the CAEN DT5742 digitizer
 * used to test 100 WATCHMAN PMTs at Boulby. Based on Morgan Askins's scripts
 * for SCOUT.
 *
 * Written by: Julie He <juhe@ucdavis.edu>
 * Started July 31, 2018; last updated July 31, 2018
 */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIX
#include <CAENDigitizer.h>
#include <CAENDigitizerType.h>

int handle = -50;

int initCAEN()
{
	if (handle == -50)
	{
		CAEN_DGTZ_ConnectionType linkType = CAEN_DGTZ_USB;
		int linkNum = 0;
		int conetNode = 0;
		uint32_t VMEBaseAddr = 0;

		CAEN_DGTZ_ErrorCode res = CAEN_DGTZ_OpenDigitizer( linkType, linkNum, conetNode, VMEBaseAddr, &handle ); 

		return res;
	}
}

int main()
{
	int res = initCAEN();
	printf("Handle returned: %d\n", res);

	return 0;
}
