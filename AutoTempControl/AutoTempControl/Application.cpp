#include "Application.h"
using namespace std;

int applianceControllerRunningState = 0;
static void initialize_userSetting();

void applicationHandler()
{
    switch (applianceControllerRunningState)
    {
    case STATE_INIT:
        // Init Appliance
        cout << "Appliance State" << applianceControllerRunningState << endl;
        applianceControllerRunningState++;
        break;
    case STATE_OFF:
    {
        if (getSeason() == SEASON_SUMMER)
        {
            int roomTemp = getTemperature();
            roomTemp++;
            setTemperatureSensor(roomTemp);
        }
        else if (getSeason() == SEASON_WINTER)
        {
            int roomTemp = getTemperature();
            roomTemp--;
            setTemperatureSensor(roomTemp);
        }
    }
    break;
    case STATE_USER_INPUT_START:
        applianceControllerRunningState = STATE_USER_INPUT_WAIT;
        // Configure specific appliance
        initialize_userSetting();
        break;
    case STATE_USER_INPUT_WAIT:
        // wiat in this state until user input finishes
        break;
    case STATE_USER_INPUT_END:
        // Initialize Peripherals
        if (getSeason() == SEASON_SUMMER)
        {
            applianceControllerRunningState = STATE_SUMMER_RUN;
        }
        else if (getSeason() == SEASON_WINTER)
        {
            applianceControllerRunningState = STATE_WINTER_RUN;
        }
        break;
    case STATE_WINTER_RUN:
    {
        int roomTemp = getTemperature();
        if (roomTemp < getHeaterStartTemp())
        {
            cout << "Start Heater" << endl;
            roomTemp++;
            setTemperatureSensor(roomTemp);
            if (roomTemp >= getHeaterStopTemp())
            {
                cout << "Room Temperature Has reached: " << roomTemp << endl;
                applianceControllerRunningState = STATE_OFF;
            }
        }
    }
    break;
    case STATE_SUMMER_RUN:
    {
        int roomTemp = getTemperature();
        if (roomTemp > getCoolerStartTemp())
        {
            cout << "Started Cooling" << endl;
            roomTemp--;
            setTemperatureSensor(roomTemp);
            if (roomTemp <= getCoolerStopTemp())
            {
                cout << "Room Temperature Has reached: " << roomTemp << endl;
                applianceControllerRunningState = STATE_OFF;
            }
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
    setHeaterTemperature(startTemp, stopTemp);

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
    setCoolerTemperature(startTemp, stopTemp);

    cout << "Current Temperature Setting" << endl;
    cout << "What is current room Temperature" << endl;
    cin >> roomTemp;
    setTemperatureSensor(roomTemp);

    cout << "In Winter temperature decreases by 1 degree a second, In summer, temperature increases 1 degree a second" << endl;
    cout << "what is the season? Press 1 for Winter, 2 for Summer" << endl;
    cin >> seasonSetting;
    setSeason(seasonSetting);

    applianceControllerRunningState = STATE_USER_INPUT_END;
}
