#include "ParameterInputDialog.h"

System::Void PlantUI::ParameterInputDialog::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    this->Close();
}
