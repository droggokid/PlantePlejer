#include "LoginMenu.h"
#include "SettingsMenuForm.h"
#include "PUART.h"
#include "Serial.h"

namespace PlantUI
{
	void LoginMenu::button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Validate the entered password
		System::String^ enteredPassword = passwordTextBox->Text;
		System::String^ correctPassword = "1234"; // Replace with the actual correct password

		if (enteredPassword == correctPassword)
		{
			 //If the password is correct, hide the login form and show the settings menu form
			this->Hide();
			settingsMenuForm->Show();
		}
		else
		{
			// If the password is incorrect, show an error message or take appropriate action
			// For example, display a MessageBox
			System::Windows::Forms::MessageBox::Show("Incorrect password. Please try again.", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		}
	}

    void LoginMenu::receiveUARTdata()
    {
        System::Windows::Forms::MessageBox::Show("Starting application", "Information", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
        char charArray1[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        int receivedBitsAmount = 0;
        int baudRate = 9600;
        int port = 3;
        int code = 42;

        CSerial* s = new CSerial;
        if (!s->Open(port, baudRate))
        {
            System::Windows::Forms::MessageBox::Show("COM could not be opened", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
        }

        PUART pu(s, 8);


        while (!codeReceived)
        {
            int convertedData = 0;
            pu.receiveData(charArray1, receivedBitsAmount);
            convertedData = pu.convertData(charArray1, 8);
            if (convertedData == code)
            {
                System::Windows::Forms::MessageBox::Show("Code received", "Information", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
                codeReceived = true;
                this->Invoke(gcnew MethodInvoker(this, &LoginMenu::HideLoginFormAndShowSettingsMenuForm));
            }
            else
            {
                System::Windows::Forms::MessageBox::Show("Wrong code, try again", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
            }
        }
        s->Close();
        delete s;
    }
  
    void LoginMenu::HideLoginFormAndShowSettingsMenuForm()
    {
        this->Hide();
        settingsMenuForm->Show();
    }

}


