#include "UserSetting.h"
int heaterStartTemp = 0;
int heaterStopTemp = 0;
int coolerStartTemp = 0;
int coolerStopTemp = 0;
int seasonSetting = 0;

void setHeaterTemperature(int startTemp, int stopTemp)
{
	heaterStartTemp = startTemp;
	heaterStopTemp = stopTemp;
}

void setCoolerTemperature(int startTemp, int stopTemp)
{
	coolerStartTemp = startTemp;
	coolerStopTemp = stopTemp;
}

void setSeason(int seasonSetting)
{
	seasonSetting = seasonSetting;
}

int getSeason()
{
	return seasonSetting;
}

int getHeaterStartTemp()
{
	return heaterStartTemp;
}

int getHeaterStopTemp()
{
	return heaterStopTemp;
}
int getCoolerStartTemp()
{
	return coolerStartTemp;
}
int getCoolerStopTemp()
{
	return coolerStopTemp;
}