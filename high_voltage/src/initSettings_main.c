#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIX
#include <CAENHVWrapper.h>
#include <watchHV.h>

int main()
{
	// set params to default values
	// options: ISet, MaxV, RUp, RDwn, Trip, VSet

	int res = -1;
	float ISet = 200., MaxV = 1800., RUp = 100., RDwn = 150., VSet = 10.;

	for (ushort chNum = 0; chNum <= 3; chNum++)
	{
		// ISet; default: 200. uA
		res = initSettings(chNum, "ISet", ISet);
		sleep(2);
		if (res == CAENHV_OK) {	printf("Ch %d: Successfully set ISet to %.2f uA\n", chNum, ISet); }
		else { printf("Ch %d: ERROR. Could not set ISet\n", chNum); }

		// MaxV; default: 1800. V
		res = initSettings(chNum, "MaxV", MaxV);
		sleep(2);
		if (res == CAENHV_OK) {	printf("Ch %d: Successfully set MaxV to %.2f V\n", chNum, MaxV); }
		else { printf("Ch %d: ERROR. Could not set MaxV\n", chNum); }

		// RUp; default: 100. V/s
		res = initSettings(chNum, "RUp", RUp);
		sleep(2);
		if (res == CAENHV_OK) {	printf("Ch %d: Successfully set RUp to %.2f V/s\n", chNum, RUp); }
		else { printf("Ch %d: ERROR. Could not set RUp\n", chNum); }

		// RDwn; default: 150. V/s
		res = initSettings(chNum, "RDwn", RDwn);
		sleep(2);
		if (res == CAENHV_OK) {	printf("Ch %d: Successfully set RDwn to %.2f V/s\n", chNum, RDwn); }
		else { printf("Ch %d: ERROR. Could not set RDwn\n", chNum); }

		// VSet; default: 10. V (to avoid Ovv when turned on)
		res = initSettings(chNum, "VSet", VSet);
		sleep(2);
		if (res == CAENHV_OK) {	printf("Ch %d: Successfully set VSet to %.2f V\n", chNum, VSet); }
		else { printf("Ch %d: ERROR. Could not set VSet\n", chNum); }
	}

	return res;
}
