#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIX
#include "CAENHVWrapper.h"

int handle = -1;

int initCAEN()
{
	if (handle == -1)
	{
		// Init the system; see CAENHVWrapper.h/PDF for some values
		CAENHV_SYSTEM_TYPE_t system = DT55XXE;
		int linkType = LINKTYPE_USB;
		char* argStr = "0_0_0"; // "LinkNum_0_VMEBaseAddress" for USB
		char* username = "";
		char* passwd = "";

		// Connect to HV power supply; returns int
		CAENHVRESULT ret = CAENHV_InitSystem( system, linkType, argStr, username, passwd, &handle );

		return ret;
	}
}

int main()
{
	int ret = initCAEN();
	printf("Handle = %d\n", ret);
	return 0;
}
