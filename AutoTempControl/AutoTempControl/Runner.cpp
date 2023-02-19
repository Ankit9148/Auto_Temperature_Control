#include "Runner.h"
using namespace std;

int applicationRunningState = 0;
bool isHeaterRunning, isCoolerRunning = false;

void runHandler()
{
    int roomTemp = getTemperature();
    if (!isMainControllerBlocked()) {
        cout << "\r" << std::flush << "Current room Temperature " + std::to_string(roomTemp) + " Insert Your Choice: ";
    }
    switch (applicationRunningState)
    {
    case STATE_INIT:
        // Init Appliance
        applicationRunningState = STATE_USER_INPUT_WAIT;
        break;
    case STATE_OFF:
    {
        if (getSeason() == SEASON_SUMMER)
        {
            roomTemp++;
            setTemperatureSensor(roomTemp);
            if (roomTemp > getCoolerStartTemp())
            {
                showUser("\nRoom Temperature Has Gone UP: Staring Cooler....");
                applicationRunningState = STATE_SUMMER_RUN;
            }
        }
        else if (getSeason() == SEASON_WINTER)
        {
            roomTemp--;
            setTemperatureSensor(roomTemp);
            if (roomTemp < getHeaterStartTemp())
            {
                showUser("\nRoom Temperature Has Fallen Down: Staring Heater....");
                applicationRunningState = STATE_WINTER_RUN;
            }
        }
    }
    break;
    case STATE_USER_INPUT_WAIT:
        // wiat in this state until user input finishes
        break;
    case STATE_USER_INPUT_END:
    {
        // Initialize Peripherals
        if (getSeason() == SEASON_SUMMER)
        {
            if (roomTemp > getCoolerStartTemp())
            {
                showUser("\nRoom Temperature Has Gone UP: Staring Cooler....");
                applicationRunningState = STATE_SUMMER_RUN;
            }
            else
            {
                showUser("\nRoom temperature is moderate");
                applicationRunningState = STATE_OFF;
            }
        }
        else if (getSeason() == SEASON_WINTER)
        {
            if (roomTemp < getHeaterStartTemp())
            {
                showUser("\nRoom Temperature Has Fallen Down: Staring Heater....");
                applicationRunningState = STATE_WINTER_RUN;
            }
            else
            {
                showUser("\nRoom temperature is moderate");
                applicationRunningState = STATE_OFF;
            }
        }
    }
    break;
    case STATE_WINTER_RUN:
    {
        roomTemp++;
        setTemperatureSensor(roomTemp);
        if (roomTemp >= getHeaterStopTemp())
        {
            showUser("\nRoom Temperature Has reached: " + std::to_string(roomTemp) + ". Turning OFF Heater");
            applicationRunningState = STATE_OFF;
        }
    }
    break;
    case STATE_SUMMER_RUN:
    {
        roomTemp--;
        setTemperatureSensor(roomTemp);
        if (roomTemp <= getCoolerStopTemp())
        {
            showUser("\nRoom Temperature Has reached: " + std::to_string(roomTemp) + ". Turning OFF Cooler");
            applicationRunningState = STATE_OFF;
        }
    }
    break;
    default:
        break;
    }
}

void setRunnerState(int newState)
{
    applicationRunningState = newState;
}

void showUser(std::string message)
{
    if (!isMainControllerBlocked()) {
        cout << message << endl;
    }
}