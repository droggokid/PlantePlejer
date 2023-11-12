#pragma once
#include "Serial.h"

class PUART
{
private:
	int dataLength_ = 8;
	CSerial* sp_;
public:
	PUART(CSerial* s, int dataLength = 8);
	void receiveData(char* dataArray, int& amountRecieved);
	void printData(char* dataArray);
	int convertData(char* dataArray, int dataLength);

};

