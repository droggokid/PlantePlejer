#pragma once
#include "Plant.h"
#include "SettingsManager.h"
#include "Serial.h"
#include "PUART.h"



ref class Plant;

namespace PlantUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;

	public ref class SettingsMenuForm : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::Label^ planteNavnLabel;
		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::PictureBox^ pictureBox2;
		System::Windows::Forms::PictureBox^ pictureBox3;
		System::Windows::Forms::PictureBox^ pictureBox4;
		System::Windows::Forms::PictureBox^ pictureBox5;
		System::Windows::Forms::Button^ nextPlant;
		System::Windows::Forms::Button^ previousPlant;
		System::Windows::Forms::Button^ rotation1;
		System::Windows::Forms::Button^ rotation2;
		System::Windows::Forms::Button^ rotation3;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Label^ Background;
		System::Windows::Forms::Button^ waterup;
		System::Windows::Forms::Button^ waterdown;
		System::Windows::Forms::Button^ newPlant;
		System::Windows::Forms::Label^ vandstandLabel;
		System::Windows::Forms::Label^ RotationLabel;
		System::Windows::Forms::Button^ commitButton;
		System::Windows::Forms::Label^ currentPlantRotations;
		System::Windows::Forms::Label^ currentPlantWater;
		System::Windows::Forms::PictureBox^ pictureBox6;
		System::Windows::Forms::PictureBox^ pictureBox7;
		System::Windows::Forms::Label^ label1;
	private: 
		int currentPlantIndex = 0;
		int address = 1;
		SettingsManager^ settings;
		Plant^ currentPlant;
		
	public:
		List<Plant^>^ plantList;
		array<char>^ minData;
		

	public:
		SettingsMenuForm()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			settings = gcnew SettingsManager;
			plantList = gcnew List<Plant^>();
			minData = gcnew array<char>(8);
			Array::Clear(minData, 0, minData->Length);
			
		}

	protected:

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingsMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Background = (gcnew System::Windows::Forms::Label());
			this->waterup = (gcnew System::Windows::Forms::Button());
			this->waterdown = (gcnew System::Windows::Forms::Button());
			this->vandstandLabel = (gcnew System::Windows::Forms::Label());
			this->planteNavnLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->nextPlant = (gcnew System::Windows::Forms::Button());
			this->previousPlant = (gcnew System::Windows::Forms::Button());
			this->rotation1 = (gcnew System::Windows::Forms::Button());
			this->rotation2 = (gcnew System::Windows::Forms::Button());
			this->rotation3 = (gcnew System::Windows::Forms::Button());
			this->newPlant = (gcnew System::Windows::Forms::Button());
			this->RotationLabel = (gcnew System::Windows::Forms::Label());
			this->commitButton = (gcnew System::Windows::Forms::Button());
			this->currentPlantRotations = (gcnew System::Windows::Forms::Label());
			this->currentPlantWater = (gcnew System::Windows::Forms::Label());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(232, 232);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 55);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// Background
			// 
			this->Background->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Background->Location = System::Drawing::Point(0, 0);
			this->Background->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Background->Name = L"Background";
			this->Background->Size = System::Drawing::Size(639, 396);
			this->Background->TabIndex = 1;
			// 
			// waterup
			// 
			this->waterup->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->waterup->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->waterup->Location = System::Drawing::Point(572, 11);
			this->waterup->Margin = System::Windows::Forms::Padding(2);
			this->waterup->Name = L"waterup";
			this->waterup->Size = System::Drawing::Size(59, 52);
			this->waterup->TabIndex = 2;
			this->waterup->Text = L"+";
			this->waterup->UseVisualStyleBackColor = true;
			this->waterup->Click += gcnew System::EventHandler(this, &SettingsMenuForm::waterup_Click);
			// 
			// waterdown
			// 
			this->waterdown->Location = System::Drawing::Point(571, 241);
			this->waterdown->Margin = System::Windows::Forms::Padding(2);
			this->waterdown->Name = L"waterdown";
			this->waterdown->Size = System::Drawing::Size(59, 55);
			this->waterdown->TabIndex = 3;
			this->waterdown->Text = L"-";
			this->waterdown->UseVisualStyleBackColor = true;
			this->waterdown->Click += gcnew System::EventHandler(this, &SettingsMenuForm::waterdown_Click);
			// 
			// vandstandLabel
			// 
			this->vandstandLabel->AutoSize = true;
			this->vandstandLabel->BackColor = System::Drawing::Color::Transparent;
			this->vandstandLabel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->vandstandLabel->Location = System::Drawing::Point(501, 306);
			this->vandstandLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->vandstandLabel->Name = L"vandstandLabel";
			this->vandstandLabel->Size = System::Drawing::Size(111, 13);
			this->vandstandLabel->TabIndex = 5;
			this->vandstandLabel->Text = L"Current water Level: 0";
			// 
			// planteNavnLabel
			// 
			this->planteNavnLabel->AutoSize = true;
			this->planteNavnLabel->Location = System::Drawing::Point(86, 296);
			this->planteNavnLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->planteNavnLabel->Name = L"planteNavnLabel";
			this->planteNavnLabel->Size = System::Drawing::Size(59, 13);
			this->planteNavnLabel->TabIndex = 6;
			this->planteNavnLabel->Text = L"PlantName";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(571, 68);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(59, 168);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(504, 132);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(54, 81);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 8;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(276, 108);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(157, 128);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 9;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(12, 11);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(211, 50);
			this->pictureBox4->TabIndex = 10;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(66, 68);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(100, 219);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 11;
			this->pictureBox5->TabStop = false;
			// 
			// nextPlant
			// 
			this->nextPlant->Location = System::Drawing::Point(172, 286);
			this->nextPlant->Name = L"nextPlant";
			this->nextPlant->Size = System::Drawing::Size(38, 33);
			this->nextPlant->TabIndex = 13;
			this->nextPlant->Text = L">";
			this->nextPlant->UseVisualStyleBackColor = true;
			this->nextPlant->Click += gcnew System::EventHandler(this, &SettingsMenuForm::nextPlant_Click);
			// 
			// previousPlant
			// 
			this->previousPlant->Location = System::Drawing::Point(22, 286);
			this->previousPlant->Name = L"previousPlant";
			this->previousPlant->Size = System::Drawing::Size(38, 33);
			this->previousPlant->TabIndex = 14;
			this->previousPlant->Text = L"<";
			this->previousPlant->UseVisualStyleBackColor = true;
			this->previousPlant->Click += gcnew System::EventHandler(this, &SettingsMenuForm::previousPlant_Click);
			// 
			// rotation1
			// 
			this->rotation1->Location = System::Drawing::Point(449, 108);
			this->rotation1->Name = L"rotation1";
			this->rotation1->Size = System::Drawing::Size(42, 39);
			this->rotation1->TabIndex = 16;
			this->rotation1->Text = L"1";
			this->rotation1->UseVisualStyleBackColor = true;
			this->rotation1->Click += gcnew System::EventHandler(this, &SettingsMenuForm::rotation1_Click);
			// 
			// rotation2
			// 
			this->rotation2->Location = System::Drawing::Point(449, 153);
			this->rotation2->Name = L"rotation2";
			this->rotation2->Size = System::Drawing::Size(42, 39);
			this->rotation2->TabIndex = 17;
			this->rotation2->Text = L"2";
			this->rotation2->UseVisualStyleBackColor = true;
			this->rotation2->Click += gcnew System::EventHandler(this, &SettingsMenuForm::rotation2_Click);
			// 
			// rotation3
			// 
			this->rotation3->Location = System::Drawing::Point(449, 197);
			this->rotation3->Name = L"rotation3";
			this->rotation3->Size = System::Drawing::Size(42, 39);
			this->rotation3->TabIndex = 18;
			this->rotation3->Text = L"3";
			this->rotation3->UseVisualStyleBackColor = true;
			this->rotation3->Click += gcnew System::EventHandler(this, &SettingsMenuForm::rotation3_Click);
			// 
			// newPlant
			// 
			this->newPlant->Location = System::Drawing::Point(237, 11);
			this->newPlant->Name = L"newPlant";
			this->newPlant->Size = System::Drawing::Size(75, 23);
			this->newPlant->TabIndex = 19;
			this->newPlant->Text = L"New plant";
			this->newPlant->UseVisualStyleBackColor = true;
			this->newPlant->Click += gcnew System::EventHandler(this, &SettingsMenuForm::newPlant_Click);
			// 
			// RotationLabel
			// 
			this->RotationLabel->AutoSize = true;
			this->RotationLabel->Location = System::Drawing::Point(298, 306);
			this->RotationLabel->Name = L"RotationLabel";
			this->RotationLabel->Size = System::Drawing::Size(135, 13);
			this->RotationLabel->TabIndex = 20;
			this->RotationLabel->Text = L"Current rotations pr. hour: 0";
			// 
			// commitButton
			// 
			this->commitButton->Location = System::Drawing::Point(330, 11);
			this->commitButton->Name = L"commitButton";
			this->commitButton->Size = System::Drawing::Size(75, 23);
			this->commitButton->TabIndex = 21;
			this->commitButton->Text = L"Save";
			this->commitButton->UseVisualStyleBackColor = true;
			this->commitButton->Click += gcnew System::EventHandler(this, &SettingsMenuForm::commitButton_Click);
			// 
			// currentPlantRotations
			// 
			this->currentPlantRotations->AutoSize = true;
			this->currentPlantRotations->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->currentPlantRotations->Location = System::Drawing::Point(21, 22);
			this->currentPlantRotations->Name = L"currentPlantRotations";
			this->currentPlantRotations->Size = System::Drawing::Size(25, 30);
			this->currentPlantRotations->TabIndex = 22;
			this->currentPlantRotations->Text = L"0";
			// 
			// currentPlantWater
			// 
			this->currentPlantWater->AutoSize = true;
			this->currentPlantWater->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->currentPlantWater->Location = System::Drawing::Point(141, 22);
			this->currentPlantWater->Name = L"currentPlantWater";
			this->currentPlantWater->Size = System::Drawing::Size(25, 30);
			this->currentPlantWater->TabIndex = 23;
			this->currentPlantWater->Text = L"0";
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(54, 14);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(43, 45);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 24;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(172, 14);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(43, 45);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 25;
			this->pictureBox7->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(449, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 26;
			this->label1->Text = L"label1";
			// 
			// SettingsMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 396);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->currentPlantWater);
			this->Controls->Add(this->currentPlantRotations);
			this->Controls->Add(this->commitButton);
			this->Controls->Add(this->RotationLabel);
			this->Controls->Add(this->newPlant);
			this->Controls->Add(this->rotation3);
			this->Controls->Add(this->rotation2);
			this->Controls->Add(this->rotation1);
			this->Controls->Add(this->previousPlant);
			this->Controls->Add(this->nextPlant);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->planteNavnLabel);
			this->Controls->Add(this->vandstandLabel);
			this->Controls->Add(this->waterdown);
			this->Controls->Add(this->waterup);
			this->Controls->Add(this->Background);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"SettingsMenuForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &SettingsMenuForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
			System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
			System::Void waterup_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void waterdown_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void nextPlant_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void previousPlant_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void newPlant_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void rotation1_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void rotation2_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void rotation3_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void commitButton_Click(System::Object^ sender, System::EventArgs^ e);
			void sendUARTdata();
			

	public: 
			void UpdatePlantNameLabel(String^ name);

			void UpdateWaterLevelLabel()
			{
				vandstandLabel->Text = "Current water Level: " + settings->getStoredWater();
			}

			void UpdateRotationsLabel()
			{
				RotationLabel->Text = "Current rotations pr. hour: " + settings->getStoredRotations();
			}

			/*void UpdateCurrentPlantRotations()
			{
				currentPlantRotations->Text = "" + currentPlant->getRotations();
			}

			void UpdateCurrentPlantWater()
			{
				currentPlantWater->Text = "" + currentPlant->getWater();
			}*/



};
}

