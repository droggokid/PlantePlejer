#pragma once

ref class SettingsManager
{
private:
	int storedWaterLevel = 0;
	int storedRotationLevel = 0;

public:
	SettingsManager();
	void setStoredWater(int);
	int getStoredWater();

	void setStoredRotations(int);
	int getStoredRotations();

	//void commitChanges(Plant^% plant);
};

