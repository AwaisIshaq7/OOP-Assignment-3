
#include "StudentTimeTable.h"

namespace OOPASSIGNMENT2
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for loginstudent
	/// </summary>
	public ref class StudentLogin : public System::Windows::Forms::Form
	{
	public:
		StudentLogin(void)
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
		~StudentLogin()
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
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(465, 254);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 44);
			this->button1->TabIndex = 38;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StudentLogin::button1_Click);
			// 
			// ok
			// 
			this->ok->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ok->Location = System::Drawing::Point(29, 254);
			this->ok->Name = L"ok";
			this->ok->Size = System::Drawing::Size(122, 44);
			this->ok->TabIndex = 34;
			this->ok->Text = L"Login";
			this->ok->UseVisualStyleBackColor = true;
			this->ok->Click += gcnew System::EventHandler(this, &StudentLogin::ok_Click);
			// 
			// name
			// 
			this->name->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(29, 168);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(561, 35);
			this->name->TabIndex = 37;
			this->name->TextChanged += gcnew System::EventHandler(this, &StudentLogin::name_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(282, 28);
			this->label1->TabIndex = 35;
			this->label1->Text = L"Enter Enrollment ID :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// StudentLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(629, 347);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ok);
			this->Controls->Add(this->name);
			this->Controls->Add(this->label1);
			this->Name = L"StudentLogin";
			this->Text = L"loginstudent";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void ok_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ enrollmentID = name->Text->Trim(); // Get the entered enrollment ID
		bool found = false; // Flag to track if the enrollment ID is found
		String^ studentName;
		String^ section;

		// Read the students.txt file
		StreamReader^ reader = gcnew StreamReader("students.txt");
		String^ line;
		while ((line = reader->ReadLine()) != nullptr)
		{
			// Check if the current line contains the enrollment ID
			if (line == enrollmentID)
			{
				// If found, parse the student's name and section
				studentName = reader->ReadLine(); // Read the next line for student's name
				section = reader->ReadLine(); // Read the next line for the section
				found = true;
				break;
			}
			// Skip the next two lines since we're not interested in them
			reader->ReadLine(); // Skip student's name
			reader->ReadLine(); // Skip section
		}
		reader->Close();

		if (found)
		{
			

			// Open the timetable form for the section
			this->Hide();
			StudentTimeTable^ timetableForm = gcnew StudentTimeTable(section,studentName,enrollmentID);
			timetableForm->Show();
		}
		else
		{
			// If the enrollment ID is not found, display an error message
			MessageBox::Show("Enrollment ID not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}



	private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e) {
		name->Text = "";

	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void name_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
