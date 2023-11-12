// SettingsMenuForm.cpp

#include "SettingsMenuForm.h"
#include "Plant.h"
#include "SettingsManager.h"
#include "ParameterInputDialog.h"



namespace PlantUI
{

    System::Void SettingsMenuForm::waterup_Click(System::Object^ sender, System::EventArgs^ e)
    {
        int w = settings->getStoredWater();
        if (w < 5) {
            settings->setStoredWater(w + 1);
            //a = settings->getStoredWater();
        }
        else {
            System::Windows::Forms::MessageBox::Show("Maximum water level reached", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);

        }
        UpdateWaterLevelLabel();
        switch (settings->getStoredWater()) 
        {
            case 0: 
                minData[2] = '0';
                minData[3] = '0';
                minData[4] = '0';
                break;
            case 1:
                minData[2] = '0';
                minData[3] = '0';
                minData[4] = '1';
                break;
            case 2:
                minData[2] = '0';
                minData[3] = '1';
                minData[4] = '0';
                break;
            case 3:
                minData[2] = '0';
                minData[3] = '1';
                minData[4] = '1';
                break;
            case 4:
                minData[2] = '1';
                minData[3] = '0';
                minData[4] = '0';
                break;
            case 5:
                minData[2] = '1';
                minData[3] = '0';
                minData[4] = '1';
                break;
        }
    }

    System::Void SettingsMenuForm::waterdown_Click(System::Object^ sender, System::EventArgs^ e)
    {
        int w = settings->getStoredWater();
        if (w > 0) {
            settings->setStoredWater(w - 1);
            //a = settings->getStoredWater();
        }
        else {
            System::Windows::Forms::MessageBox::Show("Minimal water level reached", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);

        }
        UpdateWaterLevelLabel();
        switch (settings->getStoredWater())
        {
        case 0:
            minData[2] = '0';
            minData[3] = '0';
            minData[4] = '0';
            break;
        case 1:
            minData[2] = '0';
            minData[3] = '0';
            minData[4] = '1';
            break;
        case 2:
            minData[2] = '0';
            minData[3] = '1';
            minData[4] = '0';
            break;
        case 3:
            minData[2] = '0';
            minData[3] = '1';
            minData[4] = '1';
            break;
        case 4:
            minData[2] = '1';
            minData[3] = '0';
            minData[4] = '0';
            break;
        case 5:
            minData[2] = '1';
            minData[3] = '0';
            minData[4] = '1';
            break;
        }

    }

    System::Void SettingsMenuForm::rotation1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        settings->setStoredRotations(1);
        UpdateRotationsLabel();
        minData[0] = '0';
        minData[1] = '1';
    }

    System::Void SettingsMenuForm::rotation2_Click(System::Object^ sender, System::EventArgs^ e)
    {
        settings->setStoredRotations(2);
        UpdateRotationsLabel();
        minData[0] = '1';
        minData[1] = '0';
    }

    System::Void SettingsMenuForm::rotation3_Click(System::Object^ sender, System::EventArgs^ e)
    {
        settings->setStoredRotations(3);
        UpdateRotationsLabel();
        minData[0] = '1';
        minData[1] = '1';
    }

    System::Void SettingsMenuForm::commitButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (plantList->Count > 0) {
            currentPlant->setWater(settings->getStoredWater());
            currentPlant->setRotations(settings->getStoredRotations());
            currentPlantRotations->Text = "" + currentPlant->getRotations();
            currentPlantWater->Text = "" + currentPlant->getWater();
            Array::Copy(minData, currentPlant->plantData, minData->Length);
            sendUARTdata();
        }
        else {
            System::Windows::Forms::MessageBox::Show("There are no active plant objects", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);

        }
    }


    System::Void SettingsMenuForm::newPlant_Click(System::Object^ sender, System::EventArgs^ e)
    {
        System::String^ name = "";
        ParameterInputDialog^ inputDialog = gcnew ParameterInputDialog();

        if (inputDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            // Retrieve the entered parameter values
            String^ parameter1 = inputDialog->Name;

            // Create an instance of the class using the entered parameters
            name = parameter1;
            Plant^ plant = gcnew Plant;
            plant->setName(name);
            plant->setAddress(address);
            address++;
            plantList->Add(plant);
            UpdatePlantNameLabel(name);
            currentPlant = plant;
            currentPlant->setAddress(address);
            switch (currentPlant->getAddress())
            {
                case 1:
                    minData[5] = '0';
                    minData[6] = '0';
                    minData[7] = '1';
                    break;
                case 2:
                    minData[5] = '0';
                    minData[6] = '1';
                    minData[7] = '0';
                    break;
                case 3:
                    minData[5] = '0';
                    minData[6] = '1';
                    minData[7] = '1';
                    break;
                case 4:
                    minData[5] = '1';
                    minData[6] = '0';
                    minData[7] = '0';
                    break;
                case 5:
                    minData[5] = '1';
                    minData[6] = '0';
                    minData[7] = '1';
                    break;
                case 6:
                    minData[5] = '1';
                    minData[6] = '1';
                    minData[7] = '0';
                    break;
            }
        }

    }
    
    System::Void SettingsMenuForm::nextPlant_Click(System::Object^ sender, System::EventArgs^ e) {
        if (plantList->Count > 0) {

            currentPlantIndex++;

            if (currentPlantIndex >= plantList->Count) {
                currentPlantIndex = 0;
            }

            currentPlant = plantList[currentPlantIndex];

            UpdatePlantNameLabel(currentPlant->getName());
            //UpdateCurrentPlantRotations();
            //UpdateCurrentPlantWater();
            currentPlantRotations->Text = "" + currentPlant->getRotations();
            currentPlantWater->Text = "" + currentPlant->getWater();
            sendUARTdata();

        }
    }

    System::Void SettingsMenuForm::previousPlant_Click(System::Object^ sender, System::EventArgs^ e) {
        if (plantList->Count > 0) {

            currentPlantIndex--;

            if (currentPlantIndex < 0) {
                currentPlantIndex = plantList->Count - 1;
            }

            currentPlant = plantList[currentPlantIndex];

            UpdatePlantNameLabel(currentPlant->getName());
            //UpdateCurrentPlantRotations();
            //UpdateCurrentPlantWater();
            currentPlantRotations->Text = "" + currentPlant->getRotations();
            currentPlantWater->Text = "" + currentPlant->getWater();
            sendUARTdata();
        }
    }
    

    void SettingsMenuForm::UpdatePlantNameLabel(String^ name)
    {
        planteNavnLabel->Text = name;
    }

    void SettingsMenuForm::sendUARTdata()
    {
        CSerial* s = new CSerial();
        int port = 3;
        int baudRate = 9600;
        const int length = minData->Length;

        if (!s->Open(port, baudRate))
        {
            System::Windows::Forms::MessageBox::Show("Could not open COM", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
        }
        else
        {
            char* nativeCharArray = new char[length];

            for (int i = 0; i < length; i++)
            {
                nativeCharArray[i] = static_cast<char>(currentPlant->plantData[i]);
            }

            Sleep(1000);
            s->SendData(nativeCharArray, length);
            //System::Windows::Forms::MessageBox::Show("Data sent successfully", "Information", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
            PUART pu(s, 8);
            char dataRec[8] = { 0, 0, 0, 0, 0, 0, 0, 0, };
            int dataAmount = 0;
            pu.receiveData(dataRec, dataAmount);
            System::String^ charArrayString = gcnew System::String(dataRec);
            label1->Text = charArrayString;
            delete[] nativeCharArray;
            s->Close();
            

        }
        //s->Open(port, baudRate);
        

        delete s;
    }

        

}


