#pragma once
#include "SettingsMenuForm.h"
ref class Plant
{
private:
	unsigned int waterlevel_ = 0;	//Hvor mange ml vand planten for om dagen
	unsigned int rotations_ = 0;	//Hvor mange rotationer om dagen
	int address_ = 0;				//Addressen på slave arduinoen
	System::String^ plantName_ = "Plant1";

public:
	Plant();
	Plant(System::String^ name, int address, int water, int rotations);
	void setWater(int water);
	void setRotations(int rotations);
	void setAddress(int address);
	void setName(System::String^ name);
	int getWater();
	int getRotations();
	int getAddress();
	System::String^ getName();
	array<char>^ plantData;
};

