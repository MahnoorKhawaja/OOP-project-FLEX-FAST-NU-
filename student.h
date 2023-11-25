#include <iostream>
#include<string.h>
using namespace std;
#pragma

class student //deals with basic information of individual students
{
private:
    string name;
    string rollnumber;
    int age;
    string contact;
    string course;
    float attendance;
    float marks;

public:
    student();
    student(string name, string rollnumber, int age, string contact, string course, float attendance, float marks);
    void setdata(string name, string rollnumber, int age, string contact, string course, float attendance, float marks);
    string getname() const;
    string getrollnum() const;
    int getage() const;
    string getcontact() const;
    string getcourse();
    float getattendance();
    float getmarks();
    void input_details();
    // void registercourse();
    // void withdrawcourse();
    void attendancetrack();
    void assignmarks();
    ~student();
};
student::student(){} // default constructor called
student::student(string name, string rollnumber, int age, string contact, string course, float attendance, float marks)
{
    this->name = name;
    this->rollnumber = rollnumber;
    this->age = age;
    this->contact = contact;
    this->course = course;
    this->attendance = attendance;
    this->marks = marks;
}
void student::input_details()
{
    cout << "Enter your name" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter your roll number" << endl;
    cin.ignore();
    getline(cin, rollnumber);
    cout << "Enter your contact" << endl;
    cin.ignore();
    getline(cin, contact);
    cout << "Enter your age" << endl;
    cin.ignore();
    cin >> age;
}
void student::setdata(string name, string rollnumber, int age, string contact, string course, float attendance, float marks)
{
    this->name = name;
    this->rollnumber = rollnumber;
    this->age = age;
    this->contact = contact;
    this->course = course;
    this->attendance = attendance;
    this->marks = marks;
}
string student::getname() const
{
    return name;
}
string student::getrollnum() const
{
    return rollnumber;
}
int student::getage() const{
    return age;
}
string student::getcontact() const{
    return contact;
}
string student::getcourse(){
    return course;
}
float student::getattendance(){
    return attendance;
}
float student::getmarks(){
    return marks;
}
student::~student(){}