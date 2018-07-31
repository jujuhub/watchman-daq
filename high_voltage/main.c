#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIX
#include <CAENHVWrapper.h>
#include <watchHV.h>

int main()
{
//	int ret0 = initCAEN();
//	printf("Handle (ret0) = %d\n", ret0); // handle is seen in this script if extern

	int ret = getChParamList();

//	int ret3 = testBdPres();
//	printf("\n%d\n", ret3);

//	initCAEN();
//	CAENHVRESULT res = CAENHV_DeinitSystem(handle);

	ushort chNum = 0;
	int pwONOFF = 0; // 0: OFF; 1: ON
	int pwStatus = togglePower(chNum, pwONOFF);

	sleep(2);

	if ( pwStatus == 1 ) printf("Ch %d is ON\n", chNum);
    else if ( pwStatus == 0 ) printf("Ch %d is OFF\n", chNum);
    else printf("Invalid power status\n");

	printf("VMon: %.2f\n", getChVoltage(chNum));
	printf("VMon: %.2f\n", getChVoltage(chNum));

	float VSet = 0.;
	ret = setChVoltage(chNum, VSet);

	sleep(5);

	if (ret == CAENHV_OK)
	{
		printf("Successfully set VSet!\n");
	}

	printf("VMon: %.2f\n", getChVoltage(chNum));
	printf("VMon: %.2f\n", getChVoltage(chNum));
	printf("VMon: %.2f\n", getChVoltage(chNum));
	sleep(2);
	printf("VMon: %.2f\n", getChVoltage(chNum));
	printf("VMon: %.2f\n", getChVoltage(chNum));

	return 0;
}
