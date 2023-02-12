// AutoTempControl.cpp : Defines the entry point for the application.
//

#include "AutoTempControlMain.h"

using namespace std;
#define COOLER_START_TEMP 35
#define COOLER_STOP_TEMP 25
#define HEATER_START_TEMP 15
#define HEATER_STOP_TEMP 20
int main()
{

	timer_start(intitMianThread, 1000);

	while (true);
	/*
	UserTemperatureSetting myTempSetting;
	TempSensor mySensorTemp;
	int startTemp, stopTemp = 0;

	cout << "Heater Temperature Setting" << endl;
	cout << "Set Heater Start Temperature" << endl;
	cin >> startTemp;
	cout << "Set Heater Stop Temperature" << endl;
	cin >> stopTemp;
	while (startTemp > stopTemp)
	{
		cout << "Stop Temperature should be greater than start temperature" << endl;
		cout << "Set Heater Stop Temperature" << endl;
		cin >> stopTemp;
	}
	myTempSetting.setHeaterTemperature(startTemp, stopTemp);

	cout << "Cooler Temperature Setting" << endl;
	cout << "Set Cooler Start Temperature" << endl;
	cin >> startTemp;
	cout << "Set Cooler Stop Temperature" << endl;
	cin >> stopTemp;
	while (startTemp < stopTemp)
	{
		cout << "Start temperature should be greater than stop temperature" << endl;
		cout << "Set Cooler Stop Temperature" << endl;
		cin >> stopTemp;
	}
	myTempSetting.setCoolerTemperature(startTemp, stopTemp);

	int roomTemp = mySensorTemp.getTemperature();

	if (roomTemp < HEATER_START_TEMP)
	{
		cout << "Start Heater" << endl;
		while (roomTemp <= HEATER_STOP_TEMP)
		{
			roomTemp++;
			Sleep(1000);
		}
		cout << "Room Temperature Has reached: " << roomTemp << endl;
	}
	else if (roomTemp > COOLER_START_TEMP)
	{
		cout << "Started Cooling" << endl;
		while (roomTemp >= COOLER_STOP_TEMP)
		{
			roomTemp--;
			Sleep(1000);
		}
		cout << "Room Temperature Has reached: " << roomTemp << endl;
	}*/

	return 0;
}

void timer_start(std::function<void(void)> func, unsigned int interval)
{
	std::thread([func, interval]()
				{
        while (true)
        {
            func();
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        } })
		.detach();
}

void intitMianThread()
{
	handler_1Sec();
}
