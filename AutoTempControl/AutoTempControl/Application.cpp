#include "Application.h"
using namespace std;

static void initialize_userSetting();

void userOption() {
    int userInput;
    cout << "Press 1: Config, 2: Exit\n";
    cin >> userInput;
    switch (userInput) {
    case 1:
        initialize_userSetting();
        break;
    case 2:
        exit(0);
        break;
    default:
        cout << "Invalid Input\n";
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

    setRunnerState(STATE_USER_INPUT_END);
    //applicationRunningState = STATE_USER_INPUT_END;
}
