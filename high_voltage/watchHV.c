/* This script contains functions used to automate the CAEN 
 * DT5533EP power supply to test 100 PMTs for WATCHMAN at 
 * Boulby. Based on Morgan Askins's scripts for SCOUT.
 * 
 * Written by: Julie He <juhe@ucdavis.edu>
 * Started July 23, 2018; last updated July 24, 2018
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIX
#include <CAENHVWrapper.h>

int handle = -1;

int initCAEN()
{
	// always need to call when connection to device is performed

	if (handle == -1)
	{
		// Init the system; see CAENHVWrapper.h/PDF for some values
		CAENHV_SYSTEM_TYPE_t system = DT55XXE;
		int linkType = LINKTYPE_USB_VCP;
		char *argStr = "ttyACM0_9600_8_1_0_0"; // "commport_baudrate_commdata_commstop_commparity_lbusaddress" for USB_VCP
		char *username = "", *passwd = "";

		// Connect to HV power supply; returns int
		CAENHVRESULT cRes = CAENHV_InitSystem( system, linkType, argStr, 
							username, passwd, &handle );

//		printf("Handle status: %d\n", handle); // handle changes, in other functions too

		return cRes;
	}
}

int force_initCAEN()
{
	handle = -1;
	initCAEN();
}

int testBdPres()
{
	// returns board info; #TODO may have declared variables incorrectly

	initCAEN();

	ushort slot = 0, numChs = 0;
	char *bdModel = (char *)NULL;
	char *description = (char *)NULL;
	ushort serNum = 0;
	uchar fmwRelMin = 0, fmwRelMax = 0;

	CAENHVRESULT cRes = CAENHV_TestBdPresence( handle, slot, &numChs, &bdModel, &description, &serNum, &fmwRelMin, &fmwRelMax );

	printf("Number of channels: %d | Board model: %s | Description: %s | Serial number: %d\n", numChs, bdModel, description, serNum);
	
	return cRes;
}

char *getChParamList()
{
	// list names and number of parameters for chNum; returns str

	initCAEN();

	ushort slot = 0;
	ushort chNum = 3;
	char *paramNameList = (char *)NULL;
	char (*param)[MAX_PARAM_NAME]; // ptr to MAX_PARAM_NAME size array of strs
	int numParam = 0;

	CAENHVRESULT cRes = CAENHV_GetChParamInfo( handle, slot, chNum, &paramNameList, &numParam );

	printf("List of Parameters in Ch %d:\n", chNum);

	param = (char (*)[MAX_PARAM_NAME])paramNameList;

	for (size_t i = 0; i < MAX_PARAM_NAME; ++i)
	{
		printf("%s  ", param[i]);
	}
	printf("\n");

	// PDwn status
	const ushort chList[1] = {chNum};
	int pwDwn_status = 0;
	int status = 0;

	CAENHVRESULT res0 = CAENHV_GetChParam( handle, slot, "Pw", chNum, 
							chList, &pwDwn_status );
//	CAENHVRESULT res1 = CAENHV_SetChParam( handle, slot, "Pw", chNum, chList, &status );
	CAENHVRESULT res1 = CAENHV_SetChParam( handle, slot, "Pw", 1, chList, &status );
	res0 = CAENHV_GetChParam( handle, slot, "Pw", chNum, 
				chList, &pwDwn_status );
	printf("CAENHVRESULT: %d %d %d\n", cRes, res0, res1);
	printf("Power: %d\n", pwDwn_status);

	return param[0];
}

int setChParam(ushort chNum, const char *param, float paramVal)
{
	// change param to paramVal for chNum

	initCAEN();

	ushort slot = 0;
	const ushort chList[1] = {chNum};

	CAENHVRESULT cRes = CAENHV_SetChParam( handle, slot, param, chNum, chList, &paramVal );

	return cRes;
}

int togglePower(ushort chNum, int pwONOFF)
{
	// toggle power status for chNum; 0 is OFF, 1 is ON

	initCAEN();

	ushort slot = 0;
	const ushort chList[1]  = {chNum};
	int pwStatus = 0;

	CAENHVRESULT cRes = CAENHV_SetChParam( handle, slot, "Pw", 1, chList, &pwONOFF );
	CAENHVRESULT cRes2 = CAENHV_GetChParam( handle, slot, "Pw", 1, chList, &pwStatus );

	if ( pwStatus == 1 ) printf("Ch %d is ON\n", chNum);
	else if ( pwStatus == 0 ) printf("Ch %d is OFF\n", chNum);
	else printf("Invalid power status\n");

	return pwStatus;
}
