#include <iostream>
#include <cstring>
using namespace std;
#pragma

class student // deals with basic information of individual students
{
private:
    string name;
    string rollnumber;
    int age;
    string contact;
    string *enrolledcourses;
    float attendance;
    float marks;
    int totalcourses_enrolled;
    int currentcoursecount;
    string course;

public:
    student();
    student(string name, string rollnumber, int age, string contact, string course, float attendance, float marks, int totalcourses_enrolled);
    void setdata(string name, string rollnumber, int age, string contact, string course, float attendance, float marks, int totalcourses_enrolled);
    string getname() const;
    string getrollnum() const;
    int getage() const;
    string getcontact() const;
    string getcourse();
    float getattendance();
    float getmarks();
    void input_details();
    void registercourse(const string &coursename);
    void withdrawcourse(const string &coursename);
    void attendancetrack();
    void setname(string updatename);
    void setcontact(string contact);
    void setrollnumber(string roll);
    void assignmarks();
    ~student();
};
student::student()
{
    totalcourses_enrolled = 5;
    enrolledcourses = new string[totalcourses_enrolled];
    currentcoursecount = 0;
} // default constructor called
void student::registercourse(const string &coursename)
{
    if (currentcoursecount <= totalcourses_enrolled)
    {
        enrolledcourses[currentcoursecount] = coursename;
        currentcoursecount++;
    }
    else
    {
        cout << "Sorry, cannot enroll in this course as no space left" << endl;
    }
}
string tolowercase(const string &str)
{
    string lowerStr;
    for (char c : str)
    {
        lowerStr += tolower(c);
    }
    return lowerStr;
}

void student::withdrawcourse(const string &coursename)
{
    if (currentcoursecount == 0)
    {
        cout << "You are not enrolled in any courses." << endl;
        return;
    }

    string lowerCoursename;
    lowerCoursename = tolowercase(coursename);
    bool courseFound = false;

    for (int i = 0; i < currentcoursecount; i++)
    {
        if ((tolowercase(enrolledcourses[i])) == lowerCoursename)
        {
            for (int j = i; j < currentcoursecount - 1; j++)
            {
                enrolledcourses[j] = enrolledcourses[j + 1];
            }
            currentcoursecount--;
            courseFound = true;
            break;
        }
    }

    if (courseFound)
    {
        cout << "You have successfully withdrawn from the course: " << coursename << endl;
    }
    else
    {
        cout << "Course not found: " << coursename << endl;
    }
}

student::student(string name, string rollnumber, int age, string contact, string course, float attendance, float marks, int totalcourses_enrolled)
{
    this->name = name;
    this->rollnumber = rollnumber;
    this->age = age;
    this->contact = contact;
    this->course = course;
    this->attendance = attendance;
    this->marks = marks;
    this->totalcourses_enrolled = totalcourses_enrolled;
}
void student::setname(string updatename)
{
    name = updatename;
}
void student::setcontact(string contact)
{
    this->contact = contact;
}
void student::setrollnumber(string roll)
{
    rollnumber = roll;
}
void student::input_details()
{
    
        cout << "Enter your name" << endl;
        cin.ignore(); // Uncomment if needed based on previous input method
        getline(cin, name);
        
        cout << "Enter your roll number" << endl; // Clear the input buffer to ensure no leftover newline character
        getline(cin, rollnumber);
        cout<<rollnumber<<endl;
        cout << "Enter your contact" << endl;
        getline(cin, contact);
        cout << "Enter your age" << endl;
        cin >> age;
        cin.ignore(); // Clear the input buffer after reading an integer
    }

void student::setdata(string name, string rollnumber, int age, string contact, string course, float attendance, float marks, int totalcourses_enrolled)
{
    this->name = name;
    this->rollnumber = rollnumber;
    this->age = age;
    this->contact = contact;
    this->course = course;
    this->attendance = attendance;
    this->marks = marks;
    this->totalcourses_enrolled = totalcourses_enrolled;
}
string student::getname() const
{
    return name;
}
string student::getrollnum() const
{
    return rollnumber;
}
int student::getage() const
{
    return age;
}
string student::getcontact() const
{
    return contact;
}
string student::getcourse()
{
    return course;
}
float student::getattendance()
{
    return attendance;
}
float student::getmarks()
{
    return marks;
}
student::~student() {}
