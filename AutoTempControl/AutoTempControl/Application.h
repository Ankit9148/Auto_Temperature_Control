#pragma once
#include <iostream>
#include "TempSensor.h"
#include "UserSetting.h"

enum ApplianceState
{
    STATE_INIT,
    STATE_OFF,
    STATE_USER_INPUT_START,
    STATE_USER_INPUT_WAIT,
    STATE_USER_INPUT_END,
    STATE_WINTER_RUN,
    STATE_SUMMER_RUN
};

enum SeasonType
{
    SEASON_SUMMER,
    SEASON_WINTER
};

void applicationHandler();