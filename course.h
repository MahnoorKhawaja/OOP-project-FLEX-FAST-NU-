#pragma once

#include<iostream>
#include"student.h"
using namespace std;


class course{
    private:
    string code;
    string instructor;
    int credit;
    int count_ofstudents;
    student** enrolledstudents;
    int capacity;
    public:
    course();
    course(string code, string instr,int cr,int cap);
    string getcode();
    void setcode(string code);
    void addstudent_tocourse(student *s);
    void removestudent_fromcourse(const string& rollnumber);
    void displayenrolled_students();
    string getinstructor();
    string getEnrolledStudentsDetails();
     int getcr();
     student* getarray();
    // void disp();
   // int getcap();
  //  void totalcourses();
    ~course();
};
   course::course(){
    count_ofstudents=0;
   
   }

course:: course(string code, string instr,int cr,int cap)
  {
    this->code=code;
    this->instructor=instr;
   this->credit=cr;
   
     count_ofstudents=0;
    this->capacity=cap;
     enrolledstudents=new student*[capacity];
    for(int i=0;i<capacity;i++)
    {
        enrolledstudents[i]=nullptr;
    }
  } 
//   student* getarray(){
//     return enrolledstudents;
//   }
string course::getinstructor(){
    return instructor;
}
int course::getcr(){
    return credit;
}
// int getcap(){
//     return capacity;
// }
void course::setcode(string code){
    this->code=code;

}

string course::getcode(){
    return code;
}
  
 void course::addstudent_tocourse(student* s){
    // capacity=30;
    // count_ofstudents=0;
    cout<<count_ofstudents;
    cout<<capacity;
   if(count_ofstudents<capacity)
   {
    enrolledstudents[count_ofstudents]=s;
     count_ofstudents++;
    cout<<"student added to course "<< code <<" sucessfully "<<endl;
   }  
   else
   {
    cout<<"capacity for this course is full, cannot enroll"<<endl;
   }
 }
void course::removestudent_fromcourse(const string& rollnumber)
{
    for(int i=0;i<count_ofstudents;i++)
    {
        if(enrolledstudents[i]!=nullptr && enrolledstudents[i]->getrollnum()==rollnumber)
        {
            for(int j=i;j<count_ofstudents-1;j++)
            {
                enrolledstudents[j]=enrolledstudents[j+1];
            }
            enrolledstudents[count_ofstudents--]=nullptr;
            cout<<"student removed from course "<<code<<" sucessfully"<<endl;
            break;
        }
    }
}
// void course::displayenrolled_students(){
//     cout<<"-----STUDENTS ENROLLED IN COURSE "<<code<<"----"<<endl;
//     for(int i=0;i<count_ofstudents;i++)
//     {
//         if(enrolledstudents[i]!=nullptr)
//         {
//             cout<<"name: "<<enrolledstudents[i]->getname()<<" roll number: "<<enrolledstudents[i]->getrollnum()<<endl;
//         }
//     }

// }
string course::getEnrolledStudentsDetails() {
    string details = "-----STUDENTS ENROLLED IN COURSE " + code + "----\n";
    for (int i = 0; i < count_ofstudents; i++) {
        if (enrolledstudents[i] != nullptr) {
            details += "Name: " + enrolledstudents[i]->getname() + ", Roll Number: " + enrolledstudents[i]->getrollnum() + "\n";
        }
    }
    return details;
}
course::~course(){

        delete[] enrolledstudents;
}
