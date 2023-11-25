#include<iostream>
using namespace std;
#pragma

// This class represents a course offered by FAST. It has attributes such as code, name,
// instructor, credits, capacity and students. It also has methods to add, remove and display students
// enrolled in the course.
class course{
    private:
    string code;
    string course_name;
    string instructor;
    int credit;
    int capacity;
    int students;
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
        cout<<"NUMBER OF COURSES YOU CAN GET ENROLLED IN"<<endl;
        cout<<"1. Object oriented programming                "<<endl;
        cout<<"2. Computer Architecture and Assembly language"<<endl;
        cout<<"3. Discrete Mathematics                       "<<endl;
        cout<<"4. Linear Algebra                             "<<endl;
        cout<<"5. Comprehension and Presentation Skills      "<<endl;

    }
 void course::addstudent_tocourse(){

 }

