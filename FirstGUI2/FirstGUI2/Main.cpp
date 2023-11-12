#include "SettingsMenuForm.h"
#include "SettingsManager.h"
#include "Plant.h"
#include "LoginMenu.h"
#include "Serial.h"
#include "PUART.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace PlantUI;


int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    // Create instances of LoginMenu and SettingsMenuForm
    LoginMenu^ loginForm = gcnew LoginMenu(gcnew SettingsMenuForm());
    loginForm->uartWorker->RunWorkerAsync();
    //loginForm->showPlantUI->RunWorkerAsync();
    // Run the application with the LoginMenu as the main form
    Application::Run(loginForm);
    return 0;
}