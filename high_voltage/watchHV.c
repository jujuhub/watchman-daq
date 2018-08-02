/* This script contains functions used to automate the CAEN DT5533EP power 
 * supply used to test 100 WATCHMAN PMTs at Boulby. Based on Morgan Askins's 
 * scripts for SCOUT.
 * 
 * Written by: Julie He <juhe@ucdavis.edu>
 * Started July 23, 2018; last updated August 1, 2018
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
		char *argStr = "ttyACM0_9600_8_1_0_0"; // "commport_baudrate_commdata_commstop_commparity_lbusaddr" for USB_VCP
		char *username = "", *passwd = "";

		// Connect to HV power supply; returns int
		CAENHVRESULT res = CAENHV_InitSystem( system, linkType, argStr, 
							username, passwd, &handle );

//		printf("Handle status: %d\n", handle); // handle changes, in other functions too

		return res;
	}
}

int force_initCAEN()
{
	handle = -1;
	initCAEN();
}

int initSettings(ushort chNum, char *param, float paramVal)
{
	// set params to default/user-choice values
	// note: PS remembers prev settings
	// options: ISet, MaxV, RUp, RDwn, Trip

	initCAEN();

	ushort slot = 0;
	const ushort chList[1] = {chNum};
	
	CAENHVRESULT res = CAENHV_SetChParam( handle, slot, param, 1, chList, &paramVal );

	return res;
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

	CAENHVRESULT res = CAENHV_TestBdPresence( handle, slot, &numChs, &bdModel, &description, &serNum, &fmwRelMin, &fmwRelMax );

	printf("Number of channels: %d | Board model: %s | Description: %s | Serial number: %d\n", numChs, bdModel, description, serNum);
	
	return res;
}

int getChParamList()
{
	// list names and number of parameters for chNum; returns str

	initCAEN();

	ushort slot = 0;
	char *paramNameList = (char *)NULL; // cast
	char (*param)[MAX_PARAM_NAME]; // ptr to MAX_PARAM_NAME size array of strs
	int numParam = 0;

	CAENHVRESULT res = CAENHV_GetChParamInfo( handle, slot, 0, &paramNameList, &numParam );

	param = (char (*)[MAX_PARAM_NAME])paramNameList; // cast

	printf("Number of Parameters: %d\n", numParam); // may not be printing all?
	printf("List of Parameters To Set:\n");
	for (size_t i = 0; i < MAX_PARAM_NAME; ++i)
	{
		printf("%s  ", param[i]);
	}
	printf("\n");

	return res;
}

int togglePower(ushort chNum, int pwONOFF)
{
	// toggle power status for chNum; 0 is OFF, 1 is ON

	initCAEN();

	ushort slot = 0;
	const ushort chList[1]  = {chNum}; // makes 1-elem array with chNum as val
	int pwStatus = 0;

	CAENHVRESULT res = CAENHV_SetChParam( handle, slot, "Pw", 1, chList, &pwONOFF );
	res = CAENHV_GetChParam( handle, slot, "Pw", 1, chList, &pwStatus );

	return pwStatus;
}

int setChVoltage(ushort chNum, float newVSet)
{
	// set the voltage of a channel

	initCAEN();

	ushort slot = 0;
	const ushort chList[1] = {chNum};
	float currVSet = 0.;

	// print current VSet
	CAENHVRESULT res = CAENHV_GetChParam( handle, slot, "VSet", 1, chList, &currVSet );
	if (res == CAENHV_OK)
	{
		printf("Current VSet: %.2fV \n", currVSet);
	} else { printf("ERROR: FAILED to get current VSet.\n"); }

	// set new VSet
	res = CAENHV_SetChParam( handle, slot, "VSet", 1, chList, &newVSet );
	if (res == CAENHV_OK)
	{
		return 0;
	} else { printf("ERROR: FAILED to set new VSet.\n"); }
}

float getFloatParameter(ushort chNum, char *param)
{
	// get the current float type parameter value
	// IMon, Vmon, etc

	initCAEN();

	ushort slot = 0;
	const ushort chList[1] = {chNum};
	float *paramVal = (float *)malloc(sizeof(float)); // why?

	CAENHVRESULT res = CAENHV_GetChParam( handle, slot, param, 1, chList, paramVal );

	if (res == CAENHV_OK)
	{
		return paramVal[0];
	} else { printf("ERROR: FAILED to read current %s value.\n", param); }
}

int setChParam(ushort chNum, const char *param, float paramVal)
{
	// change param to paramVal for chNum

	initCAEN();

	ushort slot = 0;
	const ushort chList[1] = {chNum};

	CAENHVRESULT res = CAENHV_SetChParam( handle, slot, param, chNum, chList, &paramVal );

	return res;
}

