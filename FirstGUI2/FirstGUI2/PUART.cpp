#include "PUART.h"

PUART::PUART(CSerial* sp, int dataLength)
{
	sp_ = sp;
	dataLength_ = dataLength;
}


void PUART::receiveData(char* dataArray, int& dataAmountStorage) {
	for (int i = 0; i < 8; i++)
	{
		while (!sp_->ReadDataWaiting()) {}
		dataAmountStorage += sp_->ReadData(&dataArray[i], 1);
	}

}

void PUART::printData(char* dataArray)
{
	//for (int i = 0; i < dataLength_; i++) {
		//std::cout << "Element " << i << " = " << dataArray[i] << std::endl;
	//}
}

int PUART::convertData(char* dataArray, int dataLength)
{
	int value = 0;
	for (int i = 0; i < dataLength; i++)
	{
		int bitValue = dataArray[i] - '0';
		value = ((value << 1) | bitValue);
	}
	return value;
}
