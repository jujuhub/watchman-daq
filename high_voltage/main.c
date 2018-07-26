#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIX
#include <CAENHVWrapper.h>
#include <watchHV.h>

int main()
{
//	int ret0 = initCAEN();
//	printf("Handle (ret0) = %d\n", ret0); // handle is seen in this script

//	int ret1 = setVolt(0, 0);
//	printf("Return value of setVolt = %d\n", ret1);

//	char *ret2 = getChParamList();

//	int ret3 = testBdPres();
//	printf("\n%d\n", ret3);

//	initCAEN();
//	CAENHVRESULT res = CAENHV_DeinitSystem(handle);
//	printf("%d\n", res);

	ushort chNum = 0;
	int pwONOFF = 0;
	int pStat = togglePower(chNum, pwONOFF);
	printf("Power status: %d\n", pStat);

	return 0;
}
