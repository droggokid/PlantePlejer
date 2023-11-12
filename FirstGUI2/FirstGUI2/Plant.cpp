#include "Plant.h"
using namespace System;

Plant::Plant()
{
	waterlevel_ = 0;
	rotations_ = 0;
	address_ = 1;
	plantData = gcnew array<char>(8);
	Array::Clear(plantData, 0, plantData->Length);
}

Plant::Plant(System::String^ name, int address, int water, int rotations)
{
	setWater(water);
	setRotations(rotations);
	address_ = address;
	plantName_ = name;
	//Attempt1::SettingsMenuForm::setCurrentObject(this);
}

void Plant::setWater(int water)
{
	waterlevel_ = (water <= 5000 && water >= 0 ? water : 0);
}

void Plant::setRotations(int rotations)
{
	rotations_ = (rotations <= 3 && rotations >= 0 ? rotations : 0);
}

int Plant::getWater()
{
	return waterlevel_;
}

int Plant::getRotations()
{
	return rotations_;
}

int Plant::getAddress()
{
	return address_;
}

System::String^ Plant::getName()
{
	return plantName_;
}

void Plant::setAddress(int address)
{
	address_ = address;
}

void Plant::setName(System::String^ name)
{
	plantName_ = name;
}
