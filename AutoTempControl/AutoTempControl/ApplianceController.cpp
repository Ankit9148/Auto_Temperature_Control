#include "ApplianceController.h"
#include "Runner.h"
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
		applianceRunningState = CONTROLLER_NORMAL_OPERATION;
		break;
	case CONTROLLER_CONFIGURATION:
		// Configure specific appliance
		applianceRunningState++;
		break;
	case CONTROLLER_MODULE_INIT:
		// Initialize Peripherals
		applianceRunningState++;
		break;
	case CONTROLLER_NORMAL_OPERATION:
		// Init Appliance
		runHandler();
		break;
	default:
		break;
	}
}