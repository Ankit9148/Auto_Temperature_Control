// AutoTempControl.cpp : Defines the entry point for the application.
//

#include "AutoTempControlMain.h"

using namespace std;

int main()
{
	timer_start(intitMianThread, 1000);

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
	handler_1Sec();
}

