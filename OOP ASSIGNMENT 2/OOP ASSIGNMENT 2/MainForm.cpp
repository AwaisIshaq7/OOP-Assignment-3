#include "MainForm.h"
#include <Windows.h>
#include <cstdlib>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew OOPASSIGNMENT2::MainForm());
}

// Definitions of MainForm methods
OOPASSIGNMENT2::MainForm::MainForm(void)
{
    InitializeComponent();
    timetableEntries = gcnew List<Tuple<String^, String^, String^, String^, String^>^>();
    teacherDailyHours = gcnew Dictionary<String^, int>();
}

OOPASSIGNMENT2::MainForm::~MainForm()
{
    if (components)
    {
        delete components;
    }
}

void OOPASSIGNMENT2::MainForm::InitializeComponent(void)
{
    this->AddTimeslotButton = (gcnew System::Windows::Forms::Button());
    this->textBox2 = (gcnew System::Windows::Forms::TextBox());
    this->button6 = (gcnew System::Windows::Forms::Button());
    this->button5 = (gcnew System::Windows::Forms::Button());
    this->button4 = (gcnew System::Windows::Forms::Button());
    this->button3 = (gcnew System::Windows::Forms::Button());
    this->button2 = (gcnew System::Windows::Forms::Button());
    this->button1 = (gcnew System::Windows::Forms::Button());
    this->AddTeacherButton = (gcnew System::Windows::Forms::Button());
    this->RemoveTeacherButton = (gcnew System::Windows::Forms::Button());
    this->ExitButton = (gcnew System::Windows::Forms::Button());
    this->label1 = (gcnew System::Windows::Forms::Label());
    this->SuspendLayout();
    // 
    // AddTimeslotButton
    // 
    this->AddTimeslotButton->Font = (gcnew System::Drawing::Font(L"Century", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->AddTimeslotButton->Location = System::Drawing::Point(330, 555);
    this->AddTimeslotButton->Name = L"AddTimeslotButton";
    this->AddTimeslotButton->Size = System::Drawing::Size(202, 74);
    this->AddTimeslotButton->TabIndex = 36;
    this->AddTimeslotButton->Text = L"Add Timeslot";
    this->AddTimeslotButton->UseVisualStyleBackColor = true;
    this->AddTimeslotButton->Click += gcnew System::EventHandler(this, &MainForm::OnAddTimeslotClicked);
    // 
    // textBox2
    // 
    this->textBox2->BackColor = System::Drawing::SystemColors::HighlightText;
    this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->textBox2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->textBox2->Location = System::Drawing::Point(-4, 35);
    this->textBox2->Name = L"textBox2";
    this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
    this->textBox2->Size = System::Drawing::Size(864, 56);
    this->textBox2->TabIndex = 31;
    this->textBox2->Text = L"      Time-table Management System";
    this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox2_TextChanged);
    // 
    // button6
    // 
    this->button6->Font = (gcnew System::Drawing::Font(L"Century", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->button6->Location = System::Drawing::Point(492, 341);
    this->button6->Name = L"button6";
    this->button6->Size = System::Drawing::Size(219, 71);
    this->button6->TabIndex = 29;
    this->button6->Text = L"Remove Student";
    this->button6->UseVisualStyleBackColor = true;
    this->button6->Click += gcnew System::EventHandler(this, &MainForm::RemoveStudentButton_Click);
    // 
    // button5
    // 
    this->button5->Font = (gcnew System::Drawing::Font(L"Century", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->button5->Location = System::Drawing::Point(160, 341);
    this->button5->Name = L"button5";
    this->button5->Size = System::Drawing::Size(202, 71);
    this->button5->TabIndex = 28;
    this->button5->Text = L"Add Students";
    this->button5->UseVisualStyleBackColor = true;
    this->button5->Click += gcnew System::EventHandler(this, &MainForm::AddStudent_Click);
    // 
    // button4
    // 
    this->button4->Font = (gcnew System::Drawing::Font(L"Century", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->button4->Location = System::Drawing::Point(492, 249);
    this->button4->Name = L"button4";
    this->button4->Size = System::Drawing::Size(219, 74);
    this->button4->TabIndex = 27;
    this->button4->Text = L"Room Wise Time-table";
    this->button4->UseVisualStyleBackColor = true;
    this->button4->Click += gcnew System::EventHandler(this, &MainForm::RoomButton_Click);
    // 
    // button3
    // 
    this->button3->Font = (gcnew System::Drawing::Font(L"Century", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->button3->Location = System::Drawing::Point(160, 249);
    this->button3->Name = L"button3";
    this->button3->Size = System::Drawing::Size(202, 74);
    this->button3->TabIndex = 26;
    this->button3->Text = L"Section Wise Time-table";
    this->button3->UseVisualStyleBackColor = true;
    this->button3->Click += gcnew System::EventHandler(this, &MainForm::Section_Button);
    // 
    // button2
    // 
    this->button2->Font = (gcnew System::Drawing::Font(L"Century", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->button2->Location = System::Drawing::Point(160, 162);
    this->button2->Name = L"button2";
    this->button2->Size = System::Drawing::Size(202, 64);
    this->button2->TabIndex = 25;
    this->button2->Text = L" Student Wise Time-table";
    this->button2->UseVisualStyleBackColor = true;
    this->button2->Click += gcnew System::EventHandler(this, &MainForm::StudentLogin_Button);
    // 
    // button1
    // 
    this->button1->Font = (gcnew System::Drawing::Font(L"Century", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->button1->Location = System::Drawing::Point(492, 162);
    this->button1->Name = L"button1";
    this->button1->Size = System::Drawing::Size(219, 68);
    this->button1->TabIndex = 24;
    this->button1->Text = L" Teacher Wise Time-table";
    this->button1->UseVisualStyleBackColor = true;
    this->button1->Click += gcnew System::EventHandler(this, &MainForm::Teacherlogin_button);
    // 
    // AddTeacherButton
    // 
    this->AddTeacherButton->Font = (gcnew System::Drawing::Font(L"Century", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->AddTeacherButton->Location = System::Drawing::Point(160, 429);
    this->AddTeacherButton->Name = L"AddTeacherButton";
    this->AddTeacherButton->Size = System::Drawing::Size(202, 74);
    this->AddTeacherButton->TabIndex = 32;
    this->AddTeacherButton->Text = L"Add Teachers";
    this->AddTeacherButton->UseVisualStyleBackColor = true;
    this->AddTeacherButton->Click += gcnew System::EventHandler(this, &MainForm::AddTeacherButton_Click);
    // 
    // RemoveTeacherButton
    // 
    this->RemoveTeacherButton->Font = (gcnew System::Drawing::Font(L"Century", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->RemoveTeacherButton->Location = System::Drawing::Point(492, 429);
    this->RemoveTeacherButton->Name = L"RemoveTeacherButton";
    this->RemoveTeacherButton->Size = System::Drawing::Size(219, 73);
    this->RemoveTeacherButton->TabIndex = 33;
    this->RemoveTeacherButton->Text = L"Remove Teacher";
    this->RemoveTeacherButton->UseVisualStyleBackColor = true;
    this->RemoveTeacherButton->Click += gcnew System::EventHandler(this, &MainForm::RemoveTeacherButton_Click);
    // 
    // ExitButton
    // 
    this->ExitButton->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->ExitButton->Location = System::Drawing::Point(587, 689);
    this->ExitButton->Name = L"ExitButton";
    this->ExitButton->Size = System::Drawing::Size(261, 68);
    this->ExitButton->TabIndex = 35;
    this->ExitButton->Text = L"Exit";
    this->ExitButton->UseVisualStyleBackColor = true;
    this->ExitButton->Click += gcnew System::EventHandler(this, &MainForm::ExitButton_Click);
    // 
    // label1
    // 
    this->label1->AutoSize = true;
    this->label1->Font = (gcnew System::Drawing::Font(L"Century", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->label1->Location = System::Drawing::Point(12, 111);
    this->label1->Name = L"label1";
    this->label1->Size = System::Drawing::Size(264, 33);
    this->label1->TabIndex = 37;
    this->label1->Text = L"Select any option:";
    this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
    // 
    // MainForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
        static_cast<System::Int32>(static_cast<System::Byte>(192)));
    this->ClientSize = System::Drawing::Size(860, 799);
    this->Controls->Add(this->label1);
    this->Controls->Add(this->AddTimeslotButton);
    this->Controls->Add(this->ExitButton);
    this->Controls->Add(this->RemoveTeacherButton);
    this->Controls->Add(this->AddTeacherButton);
    this->Controls->Add(this->textBox2);
    this->Controls->Add(this->button6);
    this->Controls->Add(this->button5);
    this->Controls->Add(this->button4);
    this->Controls->Add(this->button3);
    this->Controls->Add(this->button2);
    this->Controls->Add(this->button1);
    this->Name = L"MainForm";
    this->Text = L"mainform";
    this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
    this->ResumeLayout(false);
    this->PerformLayout();

}

void OOPASSIGNMENT2::MainForm::OnAddTimeslotClicked(System::Object^ sender, System::EventArgs^ e)
{
    AddTimeslotForm^ addTimeslotForm = gcnew AddTimeslotForm();
    if (addTimeslotForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        String^ course = addTimeslotForm->Course;
        String^ teacher = addTimeslotForm->Teacher;
        String^ room = addTimeslotForm->Room;
        String^ day = addTimeslotForm->Day;
        String^ timeslot = addTimeslotForm->Timeslot;

        if (!CheckCourseClash(course, day, timeslot) &&
            !CheckRoomAvailability(room, day, timeslot) &&
            !CheckTeacherAvailability(teacher, day, timeslot) &&
            CheckTeacherHourLimit(teacher, day))
        {
            AddTimetableEntry(course, teacher, room, day, timeslot);
            MessageBox::Show("Timeslot added successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else
        {
            MessageBox::Show("Timeslot could not be added due to a conflict.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
}


// Definitions for other methods remain unchanged...

bool OOPASSIGNMENT2::MainForm::CheckCourseClash(String^ course, String^ day, String^ timeslot)
{
    for each (auto entry in timetableEntries)
    {
        if (entry->Item1 == course && entry->Item4 == day && entry->Item5 == timeslot)
            return true;
    }
    return false;
}

bool OOPASSIGNMENT2::MainForm::CheckRoomAvailability(String^ room, String^ day, String^ timeslot)
{
    for each (auto entry in timetableEntries)
    {
        if (entry->Item3 == room && entry->Item4 == day && entry->Item5 == timeslot)
            return false;
    }
    return true;
}

bool OOPASSIGNMENT2::MainForm::CheckTeacherAvailability(String^ teacher, String^ day, String^ timeslot)
{
    for each (auto entry in timetableEntries)
    {
        if (entry->Item2 == teacher && entry->Item4 == day && entry->Item5 == timeslot)
            return false;
    }
    return true;
}

bool OOPASSIGNMENT2::MainForm::CheckTeacherHourLimit(String^ teacher, String^ day)
{
    if (teacherDailyHours->ContainsKey(teacher) && teacherDailyHours[teacher] >= 4)
        return false;
    return true;
}

void OOPASSIGNMENT2::MainForm::AddTimetableEntry(String^ course, String^ teacher, String^ room, String^ day, String^ timeslot)
{
    timetableEntries->Add(gcnew Tuple<String^, String^, String^, String^, String^>(course, teacher, room, day, timeslot));
    if (!teacherDailyHours->ContainsKey(teacher))
        teacherDailyHours[teacher] = 0;
    teacherDailyHours[teacher]++;
}

void OOPASSIGNMENT2::MainForm::Teacherlogin_button(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    TeacherLogin^ teacher = gcnew TeacherLogin();
    teacher->ShowDialog();
    this->Show();
}

void OOPASSIGNMENT2::MainForm::StudentLogin_Button(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    StudentLogin^ student = gcnew StudentLogin();
    student->ShowDialog();
    this->Show();
}

void OOPASSIGNMENT2::MainForm::Section_Button(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    SectionLogin^ section = gcnew SectionLogin();
    section->ShowDialog();
    this->Show();
}

void OOPASSIGNMENT2::MainForm::RoomButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    RoomLogin^ room = gcnew RoomLogin();
    room->ShowDialog();
    this->Show();
}

void OOPASSIGNMENT2::MainForm::AddStudent_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    AddStudentForm^ addstudent = gcnew AddStudentForm();
    addstudent->ShowDialog();
    this->Show();
}

void OOPASSIGNMENT2::MainForm::RemoveStudentButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    RemoveStudentForm^ removestudent = gcnew RemoveStudentForm();
    removestudent->ShowDialog();
    this->Show();
}



void OOPASSIGNMENT2::MainForm::RemoveTeacherButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    RemoveTeacher^ removeteacher = gcnew RemoveTeacher();
    removeteacher->ShowDialog();
    this->Show();
}

void OOPASSIGNMENT2::MainForm::AddTeacherButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    AddTeacher^ addteacher = gcnew AddTeacher();
    addteacher->ShowDialog();
    this->Show();
}



void OOPASSIGNMENT2::MainForm::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

void OOPASSIGNMENT2::MainForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}

void OOPASSIGNMENT2::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {}
