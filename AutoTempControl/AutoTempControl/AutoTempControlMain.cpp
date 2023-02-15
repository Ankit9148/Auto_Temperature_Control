// AutoTempControl.cpp : Defines the entry point for the application.
//

#include "AutoTempControlMain.h"

using namespace std;

int main()
{
	//timer_start(intitMianThread, 1000);
	std::thread mainApplication(intitMianThread);
    std::thread uiApplication(initUiThread);
	while (true);
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


