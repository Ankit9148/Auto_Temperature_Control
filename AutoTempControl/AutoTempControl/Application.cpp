#include "Application.h"
using namespace std;

int applicationRunningState = 0;
bool isHeaterRunning, isCoolerRunning = false;
static void initialize_userSetting();

void applicationHandler()
{
    int roomTemp = getTemperature();
    switch (applicationRunningState)
    {
    case STATE_INIT:
        // Init Appliance
        // cout << "Appliance State" << applianceControllerRunningState << endl;
        applicationRunningState = STATE_USER_INPUT_START;
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
    case STATE_USER_INPUT_START:
        applicationRunningState = STATE_USER_INPUT_WAIT;
        // Configure specific appliance
        initialize_userSetting();
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

static void initialize_userSetting()
{
    int startTemp, stopTemp, roomTemp, seasonSetting;

    /* Heater Parameters Setting*/
    cout << "Heater Temperature Setting\n"
         << "1. Set Heater Start Temperature\n";
    cin >> startTemp;
    cout << "2. Set Heater Stop Temperature\n";
    cin >> stopTemp;
    while (startTemp > stopTemp)
    {
        cout << "Stop Temperature should be greater than start temperature\n"
             << "2. Set Heater Stop Temperature\n";
        cin >> stopTemp;
    }
    setHeaterTemperature(startTemp, stopTemp);
    /* Cooler Parameters Setting*/
    cout << "Cooler Temperature Setting\n"
         << "3. Set Cooler Start Temperature\n";
    cin >> startTemp;
    cout << "4. Set Cooler Stop Temperature\n";
    cin >> stopTemp;
    while (startTemp < stopTemp)
    {
        cout << "Start temperature should be greater than stop temperature\n"
             << "4. Set Cooler Stop Temperature\n";
        cin >> stopTemp;
    }
    setCoolerTemperature(startTemp, stopTemp);
    /* Additional Parameters Setting*/
    cout << "Current Temperature Setting\n"
            "5. What is current room Temperature\n";
    cin >> roomTemp;
    setTemperatureSensor(roomTemp);

    cout << "In Winter temperature decreases by 1 degree a second, In summer, temperature increases 1 degree a second\n"
         << "6. what is the season? Press 1 for Winter, 0 for Summer\n";
    cin >> seasonSetting;
    setSeason(seasonSetting);

    applicationRunningState = STATE_USER_INPUT_END;
}
