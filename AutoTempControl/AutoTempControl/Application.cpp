#include "Application.h"
using namespace std;

static void initialize_userSetting();

void userOption()
{
    int userInput;
    cout << "Press Anytime 1: to Config, 2: to Exit\n";
    while (!(cin >> userInput))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n"
             << "Press Anytime 1: to Config, 2: to Exit\n";
    }
    switch (userInput)
    {
    case 1:
        initialize_userSetting();
        break;
    case 2:
        exit(0);
        break;
    default:
        cout << "Invalid Input\n";
        break;
    }
}

static void initialize_userSetting()
{
    blockMainController();
    int heaterStartTemp, heaterStopTemp, coolerStartTemp, coolerStopTemp, seasonSetting;

    /* Heater Parameters Setting*/
    cout << "Heater Temperature Setting\n"
         << "1. Set Heater Start Temperature\n";
    cin >> heaterStartTemp;
    while (!cin.good() || !(( - 10 <= heaterStartTemp) && (heaterStartTemp <= 100)))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Temperature should be i)integer, ii)in the range of [-10 to 100]\n"
             << "1. Set Heater Start Temperature\n";
        cin >> heaterStartTemp;
    }
    cout << "2. Set Heater Stop Temperature\n";
    cin >> heaterStopTemp;
    while (!cin.good() || !((-10 <= heaterStopTemp) && (heaterStopTemp <= 100)) || (heaterStartTemp > heaterStopTemp))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Temperature should be i)integer, ii)in the range of [-10 to 100], iii)greater than heater start temperature \n"
             << "2. Set Heater Stop Temperature\n";
        cin >> heaterStopTemp;
    }

    /* Cooler Parameters Setting*/
    cout << "Cooler Temperature Setting\n"
         << "3. Set Cooler Start Temperature\n";
    cin >> coolerStartTemp;
    while (!cin.good() || !((-10 <= coolerStartTemp) && (coolerStartTemp <= 100)))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Temperature should be i)integer, ii)in the range of [-10 to 100]\n"
             << "3. Set Cooler Start Temperature\n";
        cin >> coolerStartTemp;
    }

    cout << "4. Set Cooler Stop Temperature\n";
    cin >> coolerStopTemp;
    while (!cin.good() || !((-10 <= coolerStopTemp) && (coolerStopTemp <= 100)) || (coolerStartTemp < coolerStopTemp))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Temperature Temperature should be i)integer, ii)in the range of [-10 to 100], iii)lesser than cooler start temperature \n"
             << "2. Set Cooler Stop Temperature\n";
        cin >> coolerStopTemp;
    }

    /* Additional Parameters Setting*/
    cout << "In Winter temperature decreases by 1 degree a second, In summer, temperature increases 1 degree a second\n"
         << "6. what is the season? Press 0 for Summer, 1 for Winter\n";
    cin >> seasonSetting;
    while (!cin.good() || !((seasonSetting == 0) || (seasonSetting == 1)))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n"
             << "6. Press 0 for Summer, 1 for Winter\n";
    }
    system("cls");
    setHeaterTemperature(heaterStartTemp, heaterStopTemp);
    setCoolerTemperature(coolerStartTemp, coolerStopTemp);
    setSeason(seasonSetting);
    setRunnerState(STATE_USER_INPUT_END);
    unblockMainController();
    // applicationRunningState = STATE_USER_INPUT_END;
}
