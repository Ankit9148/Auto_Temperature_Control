#pragma once

void setHeaterTemperature(int startTemp, int stopTemp);
void setCoolerTemperature(int startTemp, int stopTemp);
void setSeason(int seasonSetting);
int getSeason();
int getHeaterStartTemp();
int getHeaterStopTemp();
int getCoolerStartTemp();
int getCoolerStopTemp();
void blockMainController();
void unblockMainController();
bool isMainControllerBlocked();