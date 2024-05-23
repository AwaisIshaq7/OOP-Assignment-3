#pragma once
#include "SectionTimeTable.h"


namespace OOPASSIGNMENT2 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Section
	/// </summary>
	public ref class SectionLogin : public System::Windows::Forms::Form
	{
	public:
		SectionLogin(void)
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
		~SectionLogin()
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
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(508, 231);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 45);
			this->button1->TabIndex = 38;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SectionLogin::button1_Click);
			// 
			// ok
			// 
			this->ok->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->ok->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ok->Location = System::Drawing::Point(26, 229);
			this->ok->Name = L"ok";
			this->ok->Size = System::Drawing::Size(99, 47);
			this->ok->TabIndex = 34;
			this->ok->Text = L"Login";
			this->ok->UseVisualStyleBackColor = true;
			this->ok->Click += gcnew System::EventHandler(this, &SectionLogin::ok_Click);
			// 
			// name
			// 
			this->name->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(26, 162);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(600, 35);
			this->name->TabIndex = 37;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(21, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(481, 28);
			this->label1->TabIndex = 35;
			this->label1->Text = L"Enter Section (2-A, 2-B, 4-A, 6-A, 8-A):";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// SectionLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(642, 359);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ok);
			this->Controls->Add(this->name);
			this->Controls->Add(this->label1);
			this->Name = L"SectionLogin";
			this->Text = L"Section";
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
		this->Hide();
		String^ section = name->Text;
		SectionTimeTable^ sectionTimeTable = gcnew SectionTimeTable(section);
		sectionTimeTable->Show();
	}

	private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e) {
		name->Text = "";
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
