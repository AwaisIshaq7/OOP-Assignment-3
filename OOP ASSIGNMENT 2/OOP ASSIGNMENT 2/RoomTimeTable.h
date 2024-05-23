#pragma once

namespace OOPASSIGNMENT2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for RoomTimeTable
	/// </summary>
	public ref class RoomTimeTable : public System::Windows::Forms::Form
	{
	public:
		RoomTimeTable(String^ roomName)
		{
			InitializeComponent(roomName);
			//
			//TODO: Add the constructor code here
			//
			PopulateRoomTimeTable(roomName);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RoomTimeTable()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		System::Windows::Forms::DataGridView^ dataGridView1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(String^ roomName)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->dataGridView1 = gcnew System::Windows::Forms::DataGridView();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 40);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(776, 398);
			this->dataGridView1->TabIndex = 0;
			// 
			// RoomTimeTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 450);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"RoomTimeTable";
			this->Text = L"Room Time Table";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

			Label^ roomLabel = gcnew Label();
			roomLabel->Text = "TimeTable For Room " + roomName;
			roomLabel->AutoSize = true;
			roomLabel->Location = Point(12, 9);
			this->Controls->Add(roomLabel);
		}
#pragma endregion

		void PopulateRoomTimeTable(String^ roomName)
		{
			// Construct the timetable file name based on the room name
			String^ fileName = "timetable_" + roomName + ".txt";

			// Add columns to the DataGridView
			dataGridView1->Columns->Add("Day", "Day");
			dataGridView1->Columns->Add("Start Time", "Start Time");
			dataGridView1->Columns->Add("End Time", "End Time");
			dataGridView1->Columns->Add("Class Details", "Class Details");

			dataGridView1->Columns["Class Details"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

			try
			{
				// Open the timetable file
				StreamReader^ reader = gcnew StreamReader(fileName);
				String^ line;

				// Read each line from the file
				while ((line = reader->ReadLine()) != nullptr)
				{
					// Split the line by spaces to extract day, start time, end time, and class details
					array<String^>^ parts = line->Split(' ');

					// Ensure the line has enough parts to parse
					if (parts->Length >= 5)
					{
						String^ day = parts[0];
						String^ startTime = parts[1];
						String^ endTime = parts[2];
						String^ classDetails = "";

						// Concatenate the remaining parts to form the class details
						for (int i = 3; i < parts->Length; i++)
						{
							classDetails += parts[i] + " ";
						}

						// Add the parsed values to the DataGridView
						dataGridView1->Rows->Add(day, startTime, endTime, classDetails->Trim());
					}
				}

				// Close the reader
				reader->Close();
			}
			catch (Exception^ ex)
			{
				// Handle any exceptions that may occur while reading the file
				MessageBox::Show("An error occurred while reading the timetable file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	};
}
