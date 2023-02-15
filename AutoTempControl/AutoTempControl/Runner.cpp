#include "Runner.h"
using namespace std;

int applicationRunningState = 0;
bool isHeaterRunning, isCoolerRunning = false;

void runHandler()
{
    int roomTemp = getTemperature();
    switch (applicationRunningState)
    {
    case STATE_INIT:
        // Init Appliance
        cout << "Appliance State INIT\n";
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
                cout << "Room Temperature Has Gone UP: Staring Cooler....\n";
                applicationRunningState = STATE_SUMMER_RUN;
            }
        }
        else if (getSeason() == SEASON_WINTER)
        {
            roomTemp--;
            setTemperatureSensor(roomTemp);
            if (roomTemp < getHeaterStartTemp())
            {
                cout << "Room Temperature Has Fallen Down: Staring Heater....\n";
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
                cout << "Room Temperature Has Gone UP: Staring Cooler....\n";
                applicationRunningState = STATE_SUMMER_RUN;
            }
            else
            {
                cout << "Room temperature is moderate\n";
                applicationRunningState = STATE_OFF;
            }
        }
        else if (getSeason() == SEASON_WINTER)
        {
            if (roomTemp < getHeaterStartTemp())
            {
                cout << "Room Temperature Has Fallen Down: Staring Heater....\n";
                applicationRunningState = STATE_WINTER_RUN;
            }
            else
            {
                cout << "Room temperature is moderate\n";
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
            cout << "Room Temperature Has reached: " << roomTemp << ". Turning OFF Heater\n";
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
            cout << "Room Temperature Has reached: " << roomTemp << ". Turning OFF Cooler\n";
            applicationRunningState = STATE_OFF;
        }
    }
    break;
    default:
        break;
    }
}

void setRunnerState(int newState) {
    applicationRunningState = newState;
}