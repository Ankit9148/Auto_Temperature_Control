#include "UserSetting.h"

void UserTemperatureSetting::setHeaterTemperature(int startTemp, int stopTemp)
{
	heaterStartTemp = startTemp;
	heaterStopTemp = stopTemp;
}

void UserTemperatureSetting::setCoolerTemperature(int startTemp, int stopTemp)
{
	coolerStartTemp  = startTemp;
	coolerStopTemp = stopTemp;
}

