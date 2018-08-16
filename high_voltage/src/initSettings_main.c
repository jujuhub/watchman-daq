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
	float ISet = 200., MaxV = 1800., RUp = 100., RDwn = 150.;

	for (ushort chNum = 0; chNum <= 3; chNum++)
	{
		// ISet; default: 200. uA
		res = initSettings(chNum, "ISet", ISet);
		sleep(2);
		if (res == CAENHV_OK) {	printf("CH %d: Successfully set ISet to %.2f uA\n", chNum, ISet); }
		else { printf("CH %d: ERROR. COULD NOT SET ISet\n", chNum); }

		// MaxV; default: 1800. V
		res = initSettings(chNum, "MaxV", MaxV);
		sleep(2);
		if (res == CAENHV_OK) {	printf("CH %d: Successfully set MaxV to %.2f V\n", chNum, MaxV); }
		else { printf("CH %d: ERROR. COULD NOT SET MaxV\n", chNum); }

		// RUp; default: 100. V/s
		res = initSettings(chNum, "RUp", RUp);
		sleep(2);
		if (res == CAENHV_OK) {	printf("CH %d: Successfully set RUp to %.2f V/s\n", chNum, RUp); }
		else { printf("CH %d: ERROR. COULD NOT SET RUp\n", chNum); }

		// RDwn; default: 150. V/s
		res = initSettings(chNum, "RDwn", RDwn);
		sleep(2);
		if (res == CAENHV_OK) {	printf("CH %d: Successfully set RDwn to %.2f V/s\n", chNum, RDwn); }
		else { printf("CH %d: ERROR. COULD NOT SET RDwn\n", chNum); }
	}

	return res;
}
