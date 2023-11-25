#include <iostream>
// #include<string.h>
using namespace std;
#pragma

class Enrollment_Manager
{
private:
    student **enrollers;
    int total_students;
    int MAX_STUDENTS;

public:
    Enrollment_Manager();
    void addstudent();
    void current_students();
  void remove_student(string rollnumber);
 void update_studentinfo();
    ~Enrollment_Manager();
};

Enrollment_Manager::Enrollment_Manager()
{

    total_students = 0;
    MAX_STUDENTS = 500;
    enrollers = new student *[MAX_STUDENTS]; // Allocate memory for the array
    for (int i = 0; i < MAX_STUDENTS; ++i)
    {
        enrollers[i] = nullptr; // Initialize all elements to nullptr
    }
}
// void Enrollment_manager::update_studentinfo(){
//     cout<<""
// }
void Enrollment_Manager::addstudent()
{
    student *newstudent = new student;
    cout << "Enter the student's details" << endl;
    newstudent->input_details();
    // Add validation logic here
    // if (isValid(newstudent)) { ...
    filehandler::savestudent_tofile(*newstudent);
    cout << "Student added successfully" << endl;
    // Check for array capacity before adding
    if (total_students < MAX_STUDENTS)
    { // Assuming MAX_STUDENTS is the capacity
        enrollers[total_students] = newstudent;
        total_students++;
    }
    else
    {
        cout << "No space to add more students" << endl;
        delete newstudent; // Only delete if there's no space to add
    }
}
void Enrollment_Manager::remove_student(string rollnum)
{

    for (int i = 0; i < total_students; i++)
    {
        if (enrollers[i] != NULL && (enrollers[i]->getrollnum()) == rollnum)
        {
            delete enrollers[i];
            enrollers[i] = nullptr;

            for (int j = i; j < total_students - 1; j++)
            {
                enrollers[j] = enrollers[j + 1];
            }
            enrollers[total_students - 1] = nullptr;
            total_students--;
            cout << "STUDENT SUCESSFULLY REMOVED" << endl;
            filehandler::clear_and_update(enrollers, total_students);
            break;
        }
    }
}
void Enrollment_Manager::current_students()
{
    cout << "Total Students enrolled are :" << endl;
    filehandler::loadstudents();
}

Enrollment_Manager::~Enrollment_Manager()
{
    for (int i = 0; i < total_students; i++)
    {
        delete enrollers[i];
    }
    delete[] enrollers;
}

class System // central class which interacts with the user
{
    private:
    Enrollment_Manager enrollstudents;
 
public:
    System();
    void mainmenu();
    void enrollstudentsmenu();
    void course_registrationmenu();
    void attendancemenu();
    void coursewithdrawmenu();
    void marksmenu();
    ~System();
};
System::System() {}
void System::mainmenu()
{

    cout << "FLEX COURSE MANAGEMENT SYSTEM" << endl;
    cout << "------------------------------" << endl;
    int choice;
    do
    {
        cout << "-----------Main Menu------------" << endl;
        cout << "1. Enroll a student   " << endl;
        cout << "2. Course Registration" << endl;
        cout << "3. Attendance         " << endl;
        cout << "4  Marks              " << endl;
        cout << "5. Course Withdraw    " << endl;
        cout << "6. Exit               " << endl;
        cout << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            enrollstudentsmenu();
            break;
        case 2:
            course_registrationmenu();
            break;
        case 3:
            attendancemenu();
            break;
        case 4:
            marksmenu();
            break;
        case 5:
            coursewithdrawmenu();
            break;
        case 6:
            cout << "Exiting the application..." << endl;
            break;
        default:
            cout << "INVALID INPUT, ENTER AGAIN" << endl;
        }
    } while (choice != 6);
}
void System::enrollstudentsmenu()
{
    cout << "ENROLL STUDENT MENU" << endl;
    int select;
    cout << "1. Display already enrolled students" << endl;
    cout << "2. Add a student                    " << endl;
    cout << "3. Remove a student                 " << endl;
    cout << "4. Edit student detail              " << endl;
    cout << "5. Back to main menu                " << endl;
    cout << endl;
    cout << "Enter your choice" << endl;
    cin >> select;
    switch (select)
    {
    case 1:
    {
      enrollstudents.current_students();
    }
    break;
    case 2:
    {
        enrollstudents.addstudent();
    }
    break;
    case 3:
    {
        string rollnum;
        cout << "Enter the roll number of student you want to remove" << endl;
        cin.ignore();
        getline(cin, rollnum);
        enrollstudents.remove_student(rollnum);
    }
    break;
    case 4:
        break;
    case 5:
        break;
    }
}
void System::course_registrationmenu()
{
    cout << "COURSE REGISTRATION MENU" << endl;
    int select;
    cout << "1. Available courses              " << endl;
    cout << "2. Register course                " << endl;
    cout << "3. Back main menu                 " << endl;
    cin >> select;
    switch (select)
    {
    case 1:
    {
    }
    case 2:
    {
    }
    case 3:
    {
    }
    }
}
void System::attendancemenu()
{
    cout << "ATTENDANCE MENU" << endl;
    cout << "1. Display attendance(subjectwise) " << endl;
    cout << "2. Mark Attendance                 " << endl;
    cout << "3. Back to main menu               " << endl;
    int select;
    cin >> select;
    switch (select)
    {
    case 1:
    {
    }
    case 2:
    {
    }
    case 3:
    {
    }
    }
}
void System::marksmenu()
{
    cout << "MARKS MENU" << endl;
    cout << "1. Display marks(subject wise)" << endl;
    cout << "2. Assign marks               " << endl;
    cout << "3. Back to menu               " << endl;
    int select;
    cin >> select;
    switch (select)
    {
    case 1:
    {
    }
    case 2:
    {
    }
    case 3:
    {
    }
    }
}
void System::coursewithdrawmenu()
{
    cout << "COURSE WITHDRAW MENU " << endl;
    cout << "1. Enrolled courses  " << endl;
    cout << "2. Drop a  course    " << endl;
    cout << "3. Back to main menu " << endl;
    int select;
    cin >> select;
    switch (select)
    {
    case 1:
    {
    }
    case 2:
    {
    }
    case 3:
    {
    }
    }
}
System::~System() {}