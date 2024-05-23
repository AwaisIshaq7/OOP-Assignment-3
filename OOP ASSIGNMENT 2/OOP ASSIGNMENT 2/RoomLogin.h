#pragma once
#include"RoomTimeTable.h"
namespace OOPASSIGNMENT2 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Room
	/// </summary>
	public ref class RoomLogin : public System::Windows::Forms::Form
	{
	public:
		RoomLogin(void)
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
		~RoomLogin()
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
			this->button1->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(503, 134);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 51);
			this->button1->TabIndex = 45;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RoomLogin::button1_Click);
			// 
			// ok
			// 
			this->ok->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->ok->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ok->Location = System::Drawing::Point(35, 134);
			this->ok->Name = L"ok";
			this->ok->Size = System::Drawing::Size(99, 51);
			this->ok->TabIndex = 41;
			this->ok->Text = L"Login";
			this->ok->UseVisualStyleBackColor = true;
			this->ok->Click += gcnew System::EventHandler(this, &RoomLogin::ok_Click);
			// 
			// name
			// 
			this->name->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(373, 52);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(236, 35);
			this->name->TabIndex = 44;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(366, 28);
			this->label1->TabIndex = 42;
			this->label1->Text = L"Enter Room ( 4-17, 4-18,etc ):";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// RoomLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(621, 213);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ok);
			this->Controls->Add(this->name);
			this->Controls->Add(this->label1);
			this->Name = L"RoomLogin";
			this->Text = L"Room";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void ok_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		String^ room = name->Text;
		RoomTimeTable^ timetable = gcnew RoomTimeTable(room);
		timetable->Show();
	}
	private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e) {
		name->Text = "";
	}
	};
}
