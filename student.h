#pragma once
#include <iostream>
#include <cstring>
#include"course.h"
using namespace std;


class student // deals with basic information of individual students
{
private:
    string name;
    string rollnumber;
    int age;
    string contact;
    course **array;
    string *enrolledcourses;
    float attendance;
    float marks;
    int totalcourses_enrolled;
    int currentcoursecount;
    string course;

public:
    student();
    student(string name, string rollnumber, string contact,int age);
    void setdata(string name, string rollnumber, int age, string contact, string course, float attendance, float marks, int totalcourses_enrolled);
    student(string name, string rollnumber, int age, string contact, string course, float attendance, float marks, int totalcourses_enrolled);
  //   student(string name, string rollnumber, string contact,int age, string course, float attendance, float marks, int totalcourses_enrolled);
    string getname() const;
    string getrollnum() const;
    int getage() const;
    string getcontact() const;
    string getcourse();
    float getattendance();
    float getmarks();
    void input_details();
    void registercourse(string& code);
    void withdrawcourse( string &code);
    void attendancetrack();
    void setname(string updatename);
    void setcontact(string contact);
    void setrollnumber(string roll);
    void assignmarks();
    void array();
    ~student();
};
student::student()
{
    totalcourses_enrolled = 5;
   enrolledcourses = new string[totalcourses_enrolled];
    currentcoursecount = 0;
    // enrolledcourses=new course*[totalcourses_enrolled];
    // for(int i=0;i<totalcourses_enrolled;i++)
    // {
    //     enrolledcourses[i]=nullptr;
    // }
} // default constructor called
void student::registercourse(string& code)
{
    // currentcoursecount=0;
    // totalcourses_enrolled=5;
    cout<<currentcoursecount;
    cout<<totalcourses_enrolled;
  if (currentcoursecount < totalcourses_enrolled)
    {   
        
        enrolledcourses[currentcoursecount] = code;
        currentcoursecount++;
        cout<<"enrolled in course"<<code<<endl;
    }
    else
   {
        cout << "Sorry, cannot enroll in this course as no space left" << endl;
    }
}
void student::array(){
    for(int i=0;i<totalcourses_enrolled;i++)
    {
        if(enrolledcourses[i]!=" ")
        {
        cout<< i+1<<" : " <<enrolledcourses[i]<<endl;
        }
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

void student::withdrawcourse( string& code)
{
    if (currentcoursecount == 0)
    {
        cout << "You are not enrolled in any courses." << endl;
        return;
    }

    string lowerCoursename;
    lowerCoursename = tolowercase(code);
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
        cout << "You have successfully withdrawn from the course: " << code << endl;
    }
    else
    {
        cout << "Course not found: " <<  code << endl;
    }
}

student::student(string name, string rollnumber,string contact,int age)
{
    currentcoursecount=0;
    totalcourses_enrolled=5;
    this->name = name;
    this->rollnumber = rollnumber;
    this->age = age;
    this->contact = contact;
    //     for(int i=0;i<totalcourses_enrolled;i++)
    // {
    //     enrolledcourses[i]=nullptr;
    // }
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
student::~student() {
 //   delete [] enrolledcourses;
}
