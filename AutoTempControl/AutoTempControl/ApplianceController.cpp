#include "ApplianceController.h"
#include "Application.h"
#include <iostream>
int applianceRunningState = 0;
enum MyEnum
{
	CONTROLLER_INIT,
	CONTROLLER_CONFIGURATION,
	CONTROLLER_MODULE_INIT,
	CONTROLLER_NORMAL_OPERATION
};
using namespace std;
void handler_1Sec()
{
	switch (applianceRunningState)
	{
	case CONTROLLER_INIT:
		// Init Appliance
		cout << "Appliance State" << applianceRunningState << endl;
		applianceRunningState++;
		break;
	case CONTROLLER_CONFIGURATION:
		// Configure specific appliance
		cout << "Appliance State" << applianceRunningState << endl;
		applianceRunningState++;
		break;
	case CONTROLLER_MODULE_INIT:
		// Initialize Peripherals
		cout << "Appliance State" << applianceRunningState << endl;
		applianceRunningState++;
		break;
	case CONTROLLER_NORMAL_OPERATION:
		// Init Appliance
		applicationHandler();
		break;
	default:
		break;
	}
}