class UserTemperatureSetting {

private:
	int heaterStartTemp = 0;
	int heaterStopTemp = 0;
	int coolerStartTemp = 0;
	int coolerStopTemp = 0;
public:
	void setHeaterTemperature(int startTemp, int stopTemp);
	void setCoolerTemperature(int startTemp, int stopTemp);
};