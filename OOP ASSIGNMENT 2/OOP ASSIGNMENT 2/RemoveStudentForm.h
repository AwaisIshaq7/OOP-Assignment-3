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
	public ref class RemoveStudentForm : public System::Windows::Forms::Form
	{
	public:
		RemoveStudentForm(void)
		{
			InitializeComponent();
		}

	protected:
		~RemoveStudentForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ enrollmentIDTextBox;
	protected:
	private: System::Windows::Forms::Button^ removeButton;
	private: System::Windows::Forms::Button^ cancelButton;



	private: System::Windows::Forms::Label^ label1;


	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->enrollmentIDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->removeButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// enrollmentIDTextBox
			// 
			this->enrollmentIDTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->enrollmentIDTextBox->Location = System::Drawing::Point(78, 116);
			this->enrollmentIDTextBox->Name = L"enrollmentIDTextBox";
			this->enrollmentIDTextBox->Size = System::Drawing::Size(409, 35);
			this->enrollmentIDTextBox->TabIndex = 0;
			// 
			// removeButton
			// 
			this->removeButton->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->removeButton->Location = System::Drawing::Point(78, 173);
			this->removeButton->Name = L"removeButton";
			this->removeButton->Size = System::Drawing::Size(119, 48);
			this->removeButton->TabIndex = 1;
			this->removeButton->Text = L"Remove";
			this->removeButton->UseVisualStyleBackColor = true;
			this->removeButton->Click += gcnew System::EventHandler(this, &RemoveStudentForm::removeButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(358, 173);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(129, 48);
			this->cancelButton->TabIndex = 2;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(73, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(414, 28);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Enter Enrollment ID to Remove :\r\n";
			this->label1->Click += gcnew System::EventHandler(this, &RemoveStudentForm::label1_Click);
			// 
			// RemoveStudentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(528, 298);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->removeButton);
			this->Controls->Add(this->enrollmentIDTextBox);
			this->Name = L"RemoveStudentForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Remove Student";
			this->Load += gcnew System::EventHandler(this, &RemoveStudentForm::RemoveStudentForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void removeButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Get the enrollment ID from the textbox
		String^ enrollmentID = enrollmentIDTextBox->Text;

		// Check if the enrollment ID is empty
		if (enrollmentID == "")
		{
			MessageBox::Show("Please enter the enrollment ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try
		{
			// Read all lines from the students.txt file
			array<String^>^ lines = File::ReadAllLines("students.txt");

			// Create a list to store the updated lines
			List<String^>^ updatedLines = gcnew List<String^>();

			// Flag to check if the enrollment ID exists
			bool found = false;

			// Iterate through each group of three lines
			for (int i = 0; i < lines->Length; i += 3)
			{
				// Extract enrollment ID from the first line of the group
				String^ currentEnrollmentID = lines[i];

				// Check if the current enrollment ID matches the one to be removed
				if (currentEnrollmentID->Trim() == enrollmentID)
				{
					// Set the flag to true to indicate the ID was found
					found = true;
					// Skip this group (i.e., don't add it to updatedLines)
					continue;
				}

				// Add all lines in the group to updatedLines
				updatedLines->Add(currentEnrollmentID);
				updatedLines->Add(lines[i + 1]); // Name
				updatedLines->Add(lines[i + 2]); // Section
			}

			// If the enrollment ID was not found, display a message
			if (!found)
			{
				MessageBox::Show("Enrollment ID not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Write the updated lines back to the students.txt file
			File::WriteAllLines("students.txt", updatedLines);

			// Show a success message
			MessageBox::Show("Student removed successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex)
		{
			// Show an error message if an exception occurs
			MessageBox::Show("An error occurred while removing the student: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}



	private: System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void ClearButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	enrollmentIDTextBox->Clear();
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void RemoveStudentForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
