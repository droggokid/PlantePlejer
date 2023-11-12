#include "SettingsManager.h"
#include "LoginMenu.h"

SettingsManager::SettingsManager()
{
	storedWaterLevel = 0;
	storedRotationLevel = 0;
}

void SettingsManager::setStoredWater(int water)
{
	storedWaterLevel = water;
}

int SettingsManager::getStoredWater()
{
	return storedWaterLevel;
}

void SettingsManager::setStoredRotations(int rotations)
{
	storedRotationLevel = rotations;
}

int SettingsManager::getStoredRotations()
{
	return storedRotationLevel;
}

/*
void SettingsManager::commitChanges(Plant^% plant)
{
	plant->setWater(storedWaterLevel);
	plant->setRotations(storedRotationLevel);
}
*/