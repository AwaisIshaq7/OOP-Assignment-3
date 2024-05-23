#pragma once
#include "TeacherLogin.h"
#include "StudentLogin.h"
#include "SectionLogin.h"
#include "RoomLogin.h"
#include "AddStudentForm.h"
#include "RemoveStudentForm.h"
#include "RemoveTeacher.h"
#include "AddTeacher.h"
#include "AddTimeslotForm.h"


namespace OOPASSIGNMENT2
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void);

	protected:
		~MainForm();

	private:
		System::ComponentModel::Container^ components;
		List<Tuple<String^, String^, String^, String^, String^>^>^ timetableEntries;
	private: System::Windows::Forms::Label^ label1;
		   Dictionary<String^, int>^ teacherDailyHours;

		bool CheckCourseClash(String^ course, String^ day, String^ timeslot);
		bool CheckRoomAvailability(String^ room, String^ day, String^ timeslot);
		bool CheckTeacherAvailability(String^ teacher, String^ day, String^ timeslot);
		bool CheckTeacherHourLimit(String^ teacher, String^ day);
		void AddTimetableEntry(String^ course, String^ teacher, String^ room, String^ day, String^ timeslot);

		// Declaration of the OnAddTimeslotClicked event handler
		System::Void OnAddTimeslotClicked(System::Object^ sender, System::EventArgs^ e);

	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ AddTeacherButton;
	private: System::Windows::Forms::Button^ RemoveTeacherButton;

	private: System::Windows::Forms::Button^ ExitButton;
	private: System::Windows::Forms::Button^ AddTimeslotButton;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void);
#pragma endregion


	private: System::Void Teacherlogin_button(System::Object^ sender, System::EventArgs^ e);
	private: System::Void StudentLogin_Button(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Section_Button(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RoomButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddStudent_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RemoveStudentButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RemoveTeacherButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddTeacherButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
