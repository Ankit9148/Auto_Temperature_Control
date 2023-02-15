// AutoTempControl.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <functional>
#include "ApplianceController.h"
#include "Application.h"

void timer_start(std::function<void(void)> func, unsigned int interval);
void intitMianThread();
void initUiThread();
// TODO: Reference additional headers your program requires here.
