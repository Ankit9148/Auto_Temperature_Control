// AutoTempControl.cpp : Defines the entry point for the application.
//

#include "AutoTempControlMain.h"

using namespace std;

int main()
{
	std::thread mainApplication(initMianThread);
    std::thread uiApplication(initUiThread);
	while (true);
	return 0;
}

void initMianThread()
{
	while (true)
        {
            handler_1Sec();
            std::this_thread::sleep_for(1000ms);
        }
}

void initUiThread()
{
    while (true)
    {
        userOption();
    }
}


