#include "AddTimeslotForm.h"

void OOPASSIGNMENT2::AddTimeslotForm::OnSubmitClicked(System::Object^ sender, System::EventArgs^ e)
{
    // Get the timeslot details from the textboxes
    this->Course = courseTextBox->Text;
    this->Teacher = teacherTextBox->Text;
    this->Room = roomTextBox->Text;
    this->Day = dayTextBox->Text;
    this->Timeslot = timeslotTextBox->Text;

    // Check if any of the fields are empty
    if (Course == "" || Teacher == "" || Room == "" || Day == "" || Timeslot == "") {
        MessageBox::Show("Please fill in all the fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    try {
        // Here you can add code to handle the collected timeslot information
        // For example, adding it to a timetable list or saving it to a file

        // Show a success message
        MessageBox::Show("Timeslot added successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    catch (Exception^ ex) {
        // Show an error message if an exception occurs
        MessageBox::Show("An error occurred while adding the timeslot: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    this->Close();
}

void OOPASSIGNMENT2::AddTimeslotForm::OnExitClicked(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}
