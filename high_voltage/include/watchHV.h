extern int handle;
int initCAEN();
int force_initCAEN();
int initSettings(ushort chNum, char *param, float paramVal);
int testBdPres();
int getChParamList();
int togglePower(ushort chNum, int pwONOFF);
int setChVoltage(ushort chNum, float newVSet);
float getFloatParameter(ushort chNum, char *param);
int setChParam(ushort chNum, const char *param, float paramVal);
