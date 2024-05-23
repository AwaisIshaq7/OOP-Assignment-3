#pragma once

#include "TeacherTimeTableForm.h"
#include<fstream>




namespace OOPASSIGNMENT2
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System;
	using namespace System::IO;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Summary for Teacher
	/// </summary>
	/// 


	public ref class TeacherLogin : public System::Windows::Forms::Form
	{
	public:
		TeacherLogin(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TeacherLogin()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ ok;

	private: System::Windows::Forms::TextBox^ name;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->ok = (gcnew System::Windows::Forms::Button());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(458, 209);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 49);
			this->button1->TabIndex = 31;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TeacherLogin::button1_Click);
			// 
			// ok
			// 
			this->ok->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ok->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ok->Location = System::Drawing::Point(40, 209);
			this->ok->Name = L"ok";
			this->ok->Size = System::Drawing::Size(100, 49);
			this->ok->TabIndex = 27;
			this->ok->Text = L"Login";
			this->ok->UseVisualStyleBackColor = true;
			this->ok->Click += gcnew System::EventHandler(this, &TeacherLogin::ok_Click);
			// 
			// name
			// 
			this->name->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->name->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(40, 145);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(527, 35);
			this->name->TabIndex = 30;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(35, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(284, 28);
			this->label1->TabIndex = 28;
			this->label1->Text = L"Enter Application ID :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// TeacherLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(579, 327);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ok);
			this->Controls->Add(this->name);
			this->Controls->Add(this->label1);
			this->Name = L"TeacherLogin";
			this->Text = L"Teacher";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
		
	}

	private: System::Void ok_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Read the application ID provided by the user
		String^ appId = name->Text->Trim();

		// Check if the application ID is empty
		if (String::IsNullOrEmpty(appId))
		{
			MessageBox::Show("Please enter an application ID.");
			return;
		}

		// Check if the teachers.txt file exists
		if (!File::Exists("teachers.txt"))
		{
			MessageBox::Show("Teachers file not found.");
			return;
		}

		// Read the teachers.txt file
		StreamReader^ reader = gcnew StreamReader("teachers.txt");
		String^ line;
		bool found = false;
		String^ teacherName;
		while ((line = reader->ReadLine()) != nullptr)
		{
			// Check if the current line contains the provided application ID
			if (line->Trim() == appId)
			{
				// If found, extract the teacher's name
				teacherName = reader->ReadLine();
				found = true;
				break;
			}
		}
		reader->Close();

		// If the application ID was not found, display an error message
		if (!found)
		{
			MessageBox::Show("Invalid application ID.");
			return;
		}
		this->Hide();
		TeacherTimeTableForm^ form = gcnew TeacherTimeTableForm(teacherName,appId);
		form->Show();
	}

		   // Event handler for Reset button click
		private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e) {
			name->Text = "";
		}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
