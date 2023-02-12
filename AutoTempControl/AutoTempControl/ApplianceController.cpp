#include "ApplianceController.h"
#include <iostream>
int currentApplianceState = 0;
enum MyEnum
{
	CONTROLLER_INIT, 
	CONTROLLER_START,
	CONTROLLER_RUN
};
using namespace std;
void handler_1Sec() {
	switch (currentApplianceState)
	{
	case CONTROLLER_INIT:
		// Init Appliance
		cout << "Appliance State" << currentApplianceState <<endl;
		currentApplianceState++;
		break;
	case CONTROLLER_START:
		// Init Appliance
		cout << "Appliance State" << currentApplianceState << endl;
		currentApplianceState++;
		break;
	case CONTROLLER_RUN:
		// Init Appliance
		cout << "Appliance State" << currentApplianceState << endl;
		break;
	default:
		break;
	}
}