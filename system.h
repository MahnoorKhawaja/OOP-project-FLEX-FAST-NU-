#include <iostream>
#include <cstring>
// #include<windows.h>
#include "course.h"
#include "validator.h"
#include "filehandler.h"
// #include"student.h"
using namespace std;
#pragma

class Enrollment_Manager : public validator
{
private:
    student **enrollers; // keeps track of all the students enrolled in the application, central array
    int total_students;
    int MAX_STUDENTS;
    course **coursesarray;
    int MAX_COURSES;
    int totalcourses;

public:
    Enrollment_Manager();
    void addstudent();
    void current_students();
    void remove_student(string rollnumber);
    void update_studentinfo();
    course *findcoursebycode(const string &code, int totalcourses);
    void enrollStudentInCourse(const string &rollnumber);
    void addcourse(course *c);
    void availablecourses();
    string toLowercase(const string &str);
    string trim(const string &str);
  //  void withdrawStudentFromCourse(const string &rollnum, const string &code);
    student **get_student_array();
    void incrementcourses();

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
    MAX_COURSES = 5;
    totalcourses = 0;
    coursesarray = new course *[MAX_COURSES]; // total courses available through out application
    for (int i = 0; i < MAX_COURSES; i++)
    {
        coursesarray[i] = nullptr;
    }
}

string Enrollment_Manager::toLowercase(const string &str)
{
    string lowerStr;
    for (char c : str)
    {
        if (c >= 'A' && c <= 'Z')
        {
            lowerStr += (c - 'A' + 'a');
        }
        else
        {
            lowerStr += c;
        }
    }
    return lowerStr;
}
string Enrollment_Manager::trim(const string &str)
{
    int start = 0;
    int end = str.length() - 1;
    while (start <= end && str[start] == ' ')
    {
        start++;
    }

    while (end >= start && str[end] == ' ')
    {
        end--;
    }

    if (start <= end)
    {
        return str.substr(start, end - start + 1);
    }
    return "";
}

void Enrollment_Manager::enrollStudentInCourse(const string &rollnumber)
{
    cout << "checking if student is enrolled " << endl;
    for (int i = 0; i < total_students; i++)
    {
        if (enrollers[i] != nullptr && enrollers[i]->getrollnum() == rollnumber)
        {
            cout << "yes, is enrolled." << endl;
            string code;
            cout << endl;
            cout << "enter your course code" << endl;
           getline(cin, code);
        //    cin>>code;
        //    cout<<code;
            course *course_enroll = nullptr;
            course_enroll = findcoursebycode(code, totalcourses);
            cout << "check 2" << endl;
            if (course_enroll != nullptr)
            {
                cout << "check 3" << endl;

                enrollers[i]->registercourse(code);
                // course_enroll is a pointer to a Course object
                cout << "enrolling under course" << endl;
                course_enroll->addstudent_tocourse(enrollers[i]);
             //   filehandler::loadcoursesdetails(coursesarray, totalcourses);

                cout << "student enrolled in the course" << code << endl;
            }
            else
            {
                cout << "course not found." << endl;
            }
        }
    }
}

// void withdrawStudentFromCourse(const string &rollnum, const string &code)
// {
//     cout << "checking if the student is even enrolled" << endl;
//     for (int i = 0; i < total_students; i++)
//     {
//         if (enrollers[i] != nullptr && enrollers[i]->getrollnum == rollnum)
//         {
//             cout << "student exits" << endl;
//             course *course_withdraw = findcoursebycode(code, totalcourses);
//             if(course_withdraw!=nullptr)
//             { 
//                 enrollers[i]->withdrawcourse(code);
//                 course_withdraw->removestudent_fromcourse(rollnum);
                

//             }
//             else
//             {
//                 cout<<"such a course doesnt exist"<<endl;
//             }
//         }
//     }

//     // c->removeStudent(s->getrollnum());
//     // s->withdrawcourse(c->getCode());
// }

void Enrollment_Manager::addcourse(course *c)
{
    if (totalcourses < MAX_COURSES)
    {
        cout << "Adding course: " << c->getcode() << endl;
        coursesarray[totalcourses] = c;
        totalcourses++;
        cout << totalcourses;
    }
    else
    {
        cout << "no more courses can be added" << endl;
    }
}
course *Enrollment_Manager::findcoursebycode(const string &code, int totalcourses)
{
    string searchCode = toLowercase(trim(code));
    cout << "Searching for course: " << searchCode << endl;
    for (int i = 0; i < totalcourses; i++)
    {
        if (coursesarray[i] != nullptr)
        {
            string currentCode = toLowercase(trim(coursesarray[i]->getcode()));
            cout << "Checking course: " << currentCode << endl;
            if (currentCode == searchCode)
            {
                cout << "Course found: " << currentCode << endl;
                cout << "---------------------------" << endl;
                return coursesarray[i];
            }
        }
    }
    cout << "Course not found." << endl;
    return nullptr;
}

void Enrollment_Manager::availablecourses()
{

    for (int i = 0; i < totalcourses; i++)
    {
        {
            cout << coursesarray[i]->getcode() << " " << coursesarray[i]->getinstructor() << " " << coursesarray[i]->getcr() << " " << endl;
        }
    }
}
void Enrollment_Manager::update_studentinfo()
{
    cout << "---Select which part of student information you want to update---" << endl;
    cout << "1. Students Name " << endl;
    cout << "2. Student Roll Number" << endl;
    cout << "3. Student contact number" << endl;
    string enter;
    cout << "Enter your choice:" << endl;
    cin.ignore();
    getline(cin, enter);
    if (enter == "1")
    {
        cout << "enter your previous name" << endl;
        string name;
        getline(cin, name);
        cout << name;
        cout << "enter your new name" << endl;
        string newname;
        getline(cin, newname);
        cout << newname;
        for (int i = 0; i < total_students; i++)
        {
            if (enrollers[i]->getname() == name)
            {
                enrollers[i]->setname(newname);
                cout << "NAME HAS BEEN UPDATED" << endl;
                filehandler::clear_and_update(enrollers, total_students);
                break;
            }
        }
    }

    if (enter == "2")
    {
        cout << "enter your previous roll number" << endl;
        string roll;
        cin.ignore();
        getline(cin, roll);
        cout << "enter your new rollnumber" << endl;
        string newroll;
        cin.ignore();
        getline(cin, newroll);
        for (int i = 0; i < total_students; i++)
        {
            if (enrollers[i]->getrollnum() == roll)
            {
                enrollers[i]->setrollnumber(newroll);
                cout << "ROLL NUMBER HAS BEEN UPDATED" << endl;
                filehandler::clear_and_update(enrollers, total_students);
                break;
            }
        }
    }
    if (enter == "3")
    {
        cout << "enter your previous contact" << endl;
        string contact;
        cin.ignore();
        getline(cin, contact);
        cout << "enter your new contactnumber" << endl;
        string newcontact;
        cin.ignore();
        getline(cin, newcontact);
        for (int i = 0; i < total_students; i++)
        {
            if (enrollers[i]->getcontact() == contact)
            {
                enrollers[i]->setcontact(newcontact);
                cout << "CONTACT HAS BEEN UPDATED" << endl;
                filehandler::clear_and_update(enrollers, total_students);
                break;
            }
        }
    }
}
void Enrollment_Manager::addstudent()
{
    student *newstudent = new student();
    cout << "Enter the student's details" << endl;
    newstudent->input_details();
    char c;

    // Add validation logic here
    if (validator::isValid(newstudent))
    {
        cout << "do you want to save the info to file, press y for yes and n for no" << endl;
        cin >> c;
        if (c == 'y')
        {
            filehandler::savestudent_tofile(*newstudent);
            if (total_students < MAX_STUDENTS)
            { // Assuming MAX_STUDENTS is the capacity
                enrollers[total_students] = newstudent;
                total_students++;
                cout<<total_students;
            }
            else
            {
                cout << "No space to add more students" << endl;
                delete newstudent; // Only delete if there's no space to add
            }
            cout << "Student added successfully" << endl;
        }
        else
        {
            cout << "student not added to file" << endl;
        }
    }
    else
    {
        cout << "cannot add this student" << endl;
    }
}
void Enrollment_Manager::remove_student(string rollnum)
{

    for (int i = 0; i < total_students; i++)
    {
        if (enrollers[i] != nullptr && (enrollers[i]->getrollnum()) == rollnum)
        {
            delete enrollers[i];
            enrollers[i] = nullptr;

            for (int j = i; j < total_students - 1; j++)
            {
                enrollers[j] = enrollers[j + 1];
            }
            enrollers[total_students - 1] = nullptr;
            total_students--;
            for(int i=0;i<total_students;i++)
            {
                cout<<enrollers[i]->getname();
            }
            cout << "STUDENT SUCESSFULLY REMOVED" << endl;
            filehandler::clear_and_update(enrollers, total_students);

            break;
        }
    }
}
void Enrollment_Manager::current_students()
{
    cout << "Total Students that are already enrolled :" << endl;
    filehandler::loadfromfile(enrollers, total_students);
   // filehandler::readfromfile(total_students);
   for(int i=0;i<total_students;i++)
   {
      cout<<enrollers[i]->getname()<<endl;
   }
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
    Enrollment_Manager manager;

public:
    int identity;
    System();
    void mainmenu();
    void enrollstudentsmenu();
    void course_registrationmenu();
    void attendancemenu();
    void coursewithdrawmenu();
    void marksmenu();
    ~System();
};
System::System()
{
    course *course1 = new course("oop", "Dr.Nazia Parveen", 3, 30);
    manager.addcourse(course1);
    course *course2 = new course("disc", "Prof.Hamid Javed", 2, 30);
    manager.addcourse(course2);
    course *course3 = new course("coal", "Dr.Naila Bhatti", 1, 30);
    manager.addcourse(course3);
    course *course4 = new course("math", "Prof.Iqbal Younas", 4, 30);
    manager.addcourse(course4);
}
void System::mainmenu()
{

    cout << "FLEX COURSE MANAGEMENT SYSTEM" << endl;
    cout << "------------------------------" << endl;
    int choice;

    do
    {
        cout << "You are a :" << endl;
        cout << "1. Student  " << endl;
        cout << "2. Teacher  " << endl;
        cout << "3. Admin    " << endl;
        cin >> identity;

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
            if (identity == 3)
            {
                enrollstudentsmenu();
            }
            else
            {
                cout << "Enrollment of students is done by admin only" << endl;
            }
            break;
        case 2:
            if (identity == 3 || identity == 1)
            {
                course_registrationmenu();
            }
            else
            {
                cout << "Course registeration is done by admin only" << endl;
            }
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
        manager.current_students();
    }
    break;
    case 2:
    {
        manager.addstudent();
    }
    break;
    case 3:
    {
        string rollnum;
        cout << "Enter the roll number of student you want to remove" << endl;
        cin.ignore();
        getline(cin, rollnum);
        manager.remove_student(rollnum);
    }
    break;
    case 4:
    {
        manager.update_studentinfo();
    }
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
        if (identity == 1 || identity == 3)
        {

            cout << "Available courses are :" << endl;
            //   course *course5 = new course("cps", "Prof.Jonathan Bragg", 2, 30);
            //   manager.addcourse(course5);
            manager.availablecourses();
        }
        else
        {
            cout << "teachers dont need to have this information" << endl;
        }
        break;
    }
    case 2:
    {
        if (identity == 1 || identity == 3)
        {
            cout << "enter your roll number to register for any course" << endl;
            string rollno;
            cin.ignore();
            getline(cin, rollno);
            manager.enrollStudentInCourse(rollno);
        }
        break;
    }
    case 3:
    {
        break;
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
        // string rollnumber, code;
        // cout << "Enter your roll number, for checking purposes" << endl;
        // cin.ignore();
        // getline(cin, rollnumber);
        // cout << "Enter the course code you want to withdraw/drop from" << endl;
        // getline(cin, code);
        // manager.withdrawStudentFromCourse(rollnumber, code);
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