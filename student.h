#include<iostream>
using namespace std;
#pragma

class student{ 
    private:
    string name;
    string rollnumber;
    int age;
    string contact;
    string course;
    float attendance;
    float marks;
    public:
    student(){};
    student(string name,string rollnumber,int age,strint contact,string course,float attendance,float marks);
    void setdata(string name,string rollnumber,int age,strint contact,string course,float attendance,float marks);
    string getname();
    string getrollnum();
    string getage();
    string getcontact();
    string getcourse();
    float getattendance();
    float getmarks();
    void enrollstudent();
    void registercourse();
    void withdrawcourse();
    void attendancetrack();
    void assignmarks();
    ~student();

};