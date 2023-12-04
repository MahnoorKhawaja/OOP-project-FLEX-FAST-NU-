#include<iostream>
#include"System.h"
using namespace std;
#pragma

// This class represents a course offered by FAST. It has attributes such as code, name,
// instructor, credits, capacity and students. It also has methods to add, remove and display students
// enrolled in the course.
class course:public Enrollment_Manager{
    private:
    string code;
    string course_name;
    string instructor;
    int credit;
    int no_ofstudents;
   
    public:
    course();
    course(string c, string name, string instr, int cr, int cap);
    void addstudent_tocourse();
    void removestudent_fromcourse();
    void courseinfo();
    void displayenrolled_students();
    void totalcourses();
    ~course();
};
    // Constructor to initialize the course with basic information
  course:: course(string c, string name, string instr, int cr, int cap) 
    : code(c), course_name(name), instructor(instr), credit(cr), capacity(cap), students(0) {}
    void course::totalcourses(){
        cout<<"---- NUMBER OF COURSES YOU CAN GET ENROLLED IN ----"<<endl;
        cout<<"1. Object oriented programming                     COURSE CODE CS1005 "<<endl;
        cout<<"2. Computer Architecture and Assembly language     COURSE CODE CS4500 "<<endl;
        cout<<"3. Discrete Mathematics                            COURSE CODE CS2200  "<<endl;
        cout<<"4. Linear Algebra                                  COURSE CODE CS3500  "<<endl;
        cout<<"5. Comprehension and Presentation Skills           COURSE CODE CS6700   "<<endl;

    }
 void course::addstudent_tocourse(){
    
      

 }

