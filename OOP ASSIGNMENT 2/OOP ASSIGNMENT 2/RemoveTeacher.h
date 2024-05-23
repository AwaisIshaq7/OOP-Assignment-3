#pragma once

#include <algorithm>
#include <cliext/list>

namespace OOPASSIGNMENT2
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for RemoveStudentForm
	/// </summary>
	public ref class RemoveTeacher : public System::Windows::Forms::Form
	{
	public:
		RemoveTeacher(void)
		{
			InitializeComponent();
		}

	protected:
		~RemoveTeacher()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ ApplicationIDTextBox;
	protected:
	private: System::Windows::Forms::Button^ removeButton;
	private: System::Windows::Forms::Button^ cancelButton;



	private: System::Windows::Forms::Label^ label1;


	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->ApplicationIDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->removeButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ApplicationIDTextBox
			// 
			this->ApplicationIDTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ApplicationIDTextBox->Location = System::Drawing::Point(41, 112);
			this->ApplicationIDTextBox->Name = L"ApplicationIDTextBox";
			this->ApplicationIDTextBox->Size = System::Drawing::Size(466, 35);
			this->ApplicationIDTextBox->TabIndex = 0;
			this->ApplicationIDTextBox->TextChanged += gcnew System::EventHandler(this, &RemoveTeacher::ApplicationIDTextBox_TextChanged);
			// 
			// removeButton
			// 
			this->removeButton->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->removeButton->Location = System::Drawing::Point(41, 176);
			this->removeButton->Name = L"removeButton";
			this->removeButton->Size = System::Drawing::Size(117, 38);
			this->removeButton->TabIndex = 1;
			this->removeButton->Text = L"Remove";
			this->removeButton->UseVisualStyleBackColor = true;
			this->removeButton->Click += gcnew System::EventHandler(this, &RemoveTeacher::removeButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(379, 176);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(107, 38);
			this->cancelButton->TabIndex = 2;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &RemoveTeacher::cancelButton_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Menu;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(416, 28);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Enter Application ID to Remove :";
			this->label1->Click += gcnew System::EventHandler(this, &RemoveTeacher::label1_Click);
			// 
			// RemoveTeacher
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(540, 279);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->removeButton);
			this->Controls->Add(this->ApplicationIDTextBox);
			this->Name = L"RemoveTeacher";
			this->Text = L"Remove Teacher";
			this->Load += gcnew System::EventHandler(this, &RemoveTeacher::RemoveTeacher_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void removeButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Get the application ID from the textbox
		String^ ApplicationID = ApplicationIDTextBox->Text;

		// Check if the application ID is empty
		if (ApplicationID == "")
		{
			MessageBox::Show("Please enter the application ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try
		{
			// Read all lines from the teachers.txt file
			array<String^>^ lines = File::ReadAllLines("teachers.txt");

			// Create a list to store the updated lines
			List<String^>^ updatedLines = gcnew List<String^>();

			// Flag to check if the application ID exists
			bool found = false;

			// Iterate through the lines in pairs (application ID followed by name)
			for (int i = 0; i < lines->Length; i += 2)
			{
				// Check if there are enough lines to form a complete pair
				if (i + 1 < lines->Length)
				{
					// Extract application ID from the current line
					String^ currentApplicationID = lines[i]->Trim(); // Trim whitespace

					// Check if the current application ID matches the one to be removed
					if (currentApplicationID == ApplicationID)
					{
						// Set the flag to true to indicate the ID was found
						found = true;
						// Skip this pair (i.e., don't add it to updatedLines)
						continue;
					}

					// Add both lines in the pair to updatedLines
					updatedLines->Add(lines[i]);     // Application ID
					updatedLines->Add(lines[i + 1]); // Name
				}
			}

			// If the application ID was not found, display a message
			if (!found)
			{
				MessageBox::Show("Application ID not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Write the updated lines back to the teachers.txt file
			File::WriteAllLines("teachers.txt", updatedLines);

			// Show a success message
			MessageBox::Show("Teacher removed successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex)
		{
			// Show an error message if an exception occurs
			MessageBox::Show("An error occurred while removing the teacher: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}






	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ClearButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ApplicationIDTextBox->Clear();
	}
	private: System::Void RemoveTeacher_Load(System::Object^ sender, System::EventArgs^ e) 
	{
	}
private: System::Void ApplicationIDTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cancelButton_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
};
}
