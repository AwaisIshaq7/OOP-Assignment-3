#pragma once

#include <msclr\marshal_cppstd.h>

namespace OOPASSIGNMENT2
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class AddTimeslotForm : public System::Windows::Forms::Form
	{
	public:
		AddTimeslotForm(void)
		{
			InitializeComponent();
		}

	protected:
		~AddTimeslotForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: // Public properties to access timeslot details
		property String^ Course;
		property String^ Teacher;
		property String^ Room;
		property String^ Day;
		property String^ Timeslot;

	private: System::Windows::Forms::TextBox^ courseTextBox;
	private: System::Windows::Forms::TextBox^ teacherTextBox;
	private: System::Windows::Forms::TextBox^ roomTextBox;
	private: System::Windows::Forms::TextBox^ dayTextBox;
	private: System::Windows::Forms::TextBox^ timeslotTextBox;
	private: System::Windows::Forms::Button^ submitButton;
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::Label^ courseLabel;
	private: System::Windows::Forms::Label^ teacherLabel;
	private: System::Windows::Forms::Label^ roomLabel;
	private: System::Windows::Forms::Label^ dayLabel;
	private: System::Windows::Forms::Label^ timeslotLabel;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->courseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->teacherTextBox = (gcnew System::Windows::Forms::TextBox());
			this->roomTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dayTextBox = (gcnew System::Windows::Forms::TextBox());
			this->timeslotTextBox = (gcnew System::Windows::Forms::TextBox());
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->courseLabel = (gcnew System::Windows::Forms::Label());
			this->teacherLabel = (gcnew System::Windows::Forms::Label());
			this->roomLabel = (gcnew System::Windows::Forms::Label());
			this->dayLabel = (gcnew System::Windows::Forms::Label());
			this->timeslotLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// courseTextBox
			// 
			this->courseTextBox->Location = System::Drawing::Point(169, 62);
			this->courseTextBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->courseTextBox->Name = L"courseTextBox";
			this->courseTextBox->Size = System::Drawing::Size(239, 26);
			this->courseTextBox->TabIndex = 0;
			// 
			// teacherTextBox
			// 
			this->teacherTextBox->Location = System::Drawing::Point(169, 125);
			this->teacherTextBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->teacherTextBox->Name = L"teacherTextBox";
			this->teacherTextBox->Size = System::Drawing::Size(239, 26);
			this->teacherTextBox->TabIndex = 1;
			// 
			// roomTextBox
			// 
			this->roomTextBox->Location = System::Drawing::Point(169, 188);
			this->roomTextBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->roomTextBox->Name = L"roomTextBox";
			this->roomTextBox->Size = System::Drawing::Size(239, 26);
			this->roomTextBox->TabIndex = 2;
			// 
			// dayTextBox
			// 
			this->dayTextBox->Location = System::Drawing::Point(169, 254);
			this->dayTextBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dayTextBox->Name = L"dayTextBox";
			this->dayTextBox->Size = System::Drawing::Size(239, 26);
			this->dayTextBox->TabIndex = 3;
			// 
			// timeslotTextBox
			// 
			this->timeslotTextBox->Location = System::Drawing::Point(169, 312);
			this->timeslotTextBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->timeslotTextBox->Name = L"timeslotTextBox";
			this->timeslotTextBox->Size = System::Drawing::Size(239, 26);
			this->timeslotTextBox->TabIndex = 4;
			// 
			// submitButton
			// 
			this->submitButton->Location = System::Drawing::Point(56, 375);
			this->submitButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(112, 38);
			this->submitButton->TabIndex = 5;
			this->submitButton->Text = L"Submit";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &AddTimeslotForm::OnSubmitClicked);
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(296, 375);
			this->exitButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(112, 38);
			this->exitButton->TabIndex = 6;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &AddTimeslotForm::OnExitClicked);
			// 
			// courseLabel
			// 
			this->courseLabel->AutoSize = true;
			this->courseLabel->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->courseLabel->Location = System::Drawing::Point(56, 62);
			this->courseLabel->Name = L"courseLabel";
			this->courseLabel->Size = System::Drawing::Size(104, 28);
			this->courseLabel->TabIndex = 7;
			this->courseLabel->Text = L"Course:";
			// 
			// teacherLabel
			// 
			this->teacherLabel->AutoSize = true;
			this->teacherLabel->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->teacherLabel->Location = System::Drawing::Point(56, 125);
			this->teacherLabel->Name = L"teacherLabel";
			this->teacherLabel->Size = System::Drawing::Size(117, 28);
			this->teacherLabel->TabIndex = 8;
			this->teacherLabel->Text = L"Teacher:";
			// 
			// roomLabel
			// 
			this->roomLabel->AutoSize = true;
			this->roomLabel->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->roomLabel->Location = System::Drawing::Point(56, 188);
			this->roomLabel->Name = L"roomLabel";
			this->roomLabel->Size = System::Drawing::Size(86, 28);
			this->roomLabel->TabIndex = 9;
			this->roomLabel->Text = L"Room:";
			// 
			// dayLabel
			// 
			this->dayLabel->AutoSize = true;
			this->dayLabel->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dayLabel->Location = System::Drawing::Point(56, 250);
			this->dayLabel->Name = L"dayLabel";
			this->dayLabel->Size = System::Drawing::Size(68, 28);
			this->dayLabel->TabIndex = 10;
			this->dayLabel->Text = L"Day:";
			// 
			// timeslotLabel
			// 
			this->timeslotLabel->AutoSize = true;
			this->timeslotLabel->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeslotLabel->Location = System::Drawing::Point(56, 312);
			this->timeslotLabel->Name = L"timeslotLabel";
			this->timeslotLabel->Size = System::Drawing::Size(125, 28);
			this->timeslotLabel->TabIndex = 11;
			this->timeslotLabel->Text = L"Timeslot:";
			// 
			// AddTimeslotForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 500);
			this->Controls->Add(this->timeslotLabel);
			this->Controls->Add(this->dayLabel);
			this->Controls->Add(this->roomLabel);
			this->Controls->Add(this->teacherLabel);
			this->Controls->Add(this->courseLabel);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->submitButton);
			this->Controls->Add(this->timeslotTextBox);
			this->Controls->Add(this->dayTextBox);
			this->Controls->Add(this->roomTextBox);
			this->Controls->Add(this->teacherTextBox);
			this->Controls->Add(this->courseTextBox);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"AddTimeslotForm";
			this->Text = L"Add Timeslot";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void OnSubmitClicked(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OnExitClicked(System::Object^ sender, System::EventArgs^ e);
	};
}
