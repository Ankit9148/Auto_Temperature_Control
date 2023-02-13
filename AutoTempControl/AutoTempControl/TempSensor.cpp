#include "TempSensor.h"
int currentSensorTemp;
/*
 *Initialize temperature sensor
 */
void initTemperatureSensor()
{
	// Initialize the temepreature sensor
	// Add a temperature sensor change listener
}

/*
 *get temperature sensor data
 *@return {int}
 */
int getTemperature()
{
	return currentSensorTemp;
}

/*
 *sets temperature sensor data. Only for project purpose
 *@return {int}
 */
void setTemperatureSensor(int value)
{
	currentSensorTemp = value;
}