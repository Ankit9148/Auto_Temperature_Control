#include "UserSetting.h"
int heaterStartTemp = 0;
int heaterStopTemp = 0;
int coolerStartTemp = 0;
int coolerStopTemp = 0;
int seasonSetting = 0;
bool mainControllerState = false;

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

void setSeason(int season)
{
	seasonSetting = season;
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

void blockMainController()
{
	mainControllerState = true;
}

void unblockMainController()
{
	mainControllerState = false;
}

bool isMainControllerBlocked()
{
	return mainControllerState;
}