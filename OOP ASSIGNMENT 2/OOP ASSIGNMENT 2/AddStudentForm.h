#pragma once

#include <fstream>
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

	/// <summary>
	/// Summary for Room
	/// </summary>
	public ref class AddStudentForm : public System::Windows::Forms::Form
	{
	public:
		AddStudentForm(void)
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
		~AddStudentForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ ok;

	private: System::Windows::Forms::TextBox^ name;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->ok = (gcnew System::Windows::Forms::Button());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Century", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(100, 39);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox1->Size = System::Drawing::Size(420, 44);
			this->textBox1->TabIndex = 47;
			this->textBox1->Text = L"     Add Student";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &AddStudentForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(465, 333);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 51);
			this->button1->TabIndex = 45;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddStudentForm::button1_Click);
			// 
			// ok
			// 
			this->ok->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->ok->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ok->Location = System::Drawing::Point(187, 343);
			this->ok->Name = L"ok";
			this->ok->Size = System::Drawing::Size(131, 51);
			this->ok->TabIndex = 41;
			this->ok->Text = L"Add";
			this->ok->UseVisualStyleBackColor = true;
			this->ok->Click += gcnew System::EventHandler(this, &AddStudentForm::ok_Click);
			// 
			// name
			// 
			this->name->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(187, 117);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(399, 35);
			this->name->TabIndex = 44;
			this->name->TextChanged += gcnew System::EventHandler(this, &AddStudentForm::name_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(7, 117);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 28);
			this->label1->TabIndex = 42;
			this->label1->Text = L"Full Name :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &AddStudentForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(7, 198);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(166, 28);
			this->label2->TabIndex = 48;
			this->label2->Text = L"Enrollment :";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(187, 197);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(404, 35);
			this->textBox2->TabIndex = 49;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 273);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 28);
			this->label3->TabIndex = 50;
			this->label3->Text = L" Section :";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label3->Click += gcnew System::EventHandler(this, &AddStudentForm::label3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(187, 266);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(399, 35);
			this->textBox3->TabIndex = 51;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &AddStudentForm::textBox3_TextChanged);
			// 
			// AddStudentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(622, 445);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ok);
			this->Controls->Add(this->name);
			this->Controls->Add(this->label1);
			this->Name = L"AddStudentForm";
			this->Text = L"Add Student";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void ok_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Get the student details from the textboxes
		String^ studentName = name->Text;
		String^ enrollmentID = textBox2->Text;
		String^ sectionName = textBox3->Text;

		// Check if any of the fields are empty
		if (studentName == "" || enrollmentID == "" || sectionName == "") {
			MessageBox::Show("Please fill in all the fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try {
			// Write the student details to the file
			WriteToFile("students.txt", studentName, enrollmentID, sectionName);

			// Show a success message
			MessageBox::Show("Student added successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) {
			// Show an error message if an exception occurs
			MessageBox::Show("An error occurred while adding the student: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e)
	{
		name->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
	}

		   // Function to write student details to a file
		   void WriteToFile(String^ filePath, String^ studentName, String^ enrollmentID, String^ sectionName)
		   {
			   // Open the file in append mode
			   StreamWriter^ sw = gcnew StreamWriter(filePath, true);

			   // Write each piece of information on a separate line
			   sw->WriteLine(enrollmentID);
			   sw->WriteLine(studentName);
			   sw->WriteLine(sectionName);

			   // Close the StreamWriter
			   sw->Close();
		   }

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void name_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
