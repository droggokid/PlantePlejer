#pragma once
#include "SettingsMenuForm.h"
#include <Windows.h>


namespace PlantUI {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    //ref class SettingsMenuForm; // Forward declaration

    public ref class LoginMenu : public System::Windows::Forms::Form
    {

    private:




        System::ComponentModel::Container^ components;
        SettingsMenuForm^ settingsMenuForm;
    public:
        BackgroundWorker^ uartWorker;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    public:
    private: System::Windows::Forms::TextBox^ passwordTextBox;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label1;
           bool codeReceived = false;

    public:
        LoginMenu(SettingsMenuForm^ settingsMenuForm)
        {
            InitializeComponent();
            this->settingsMenuForm = settingsMenuForm;
            uartWorker = gcnew BackgroundWorker();
            uartWorker->DoWork += gcnew DoWorkEventHandler(this, &LoginMenu::uartWorker_DoWork);
        }

    protected:
        ~LoginMenu()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Handle the picture box click event
        }

        System::Void passwordTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            // Handle the password text box text changed event
        }

        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

    public:
        void receiveUARTdata();
        void LoginMenu::HideLoginFormAndShowSettingsMenuForm();

        void uartWorker_DoWork(Object^ sender, DoWorkEventArgs^ e)
        {
            // Perform UART data receiving in the background
            receiveUARTdata();
        }
       

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginMenu::typeid));
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(187, 41);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(270, 159);
            this->pictureBox1->TabIndex = 1;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &LoginMenu::pictureBox1_Click);
            // 
            // passwordTextBox
            // 
            this->passwordTextBox->Location = System::Drawing::Point(245, 281);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->Size = System::Drawing::Size(164, 20);
            this->passwordTextBox->TabIndex = 0;
            this->passwordTextBox->TextChanged += gcnew System::EventHandler(this, &LoginMenu::passwordTextBox_TextChanged);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(425, 281);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(32, 20);
            this->button1->TabIndex = 2;
            this->button1->Text = L"button1";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &LoginMenu::button1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(518, 80);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(35, 13);
            this->label1->TabIndex = 3;
            this->label1->Text = L"label1";
            // 
            // LoginMenu
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            //this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(639, 396);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->passwordTextBox);
            this->Name = L"LoginMenu";
            this->Text = L"LoginMenu";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

#pragma endregion
    };
}