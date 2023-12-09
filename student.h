#pragma once
#include <iostream>
#include <cstring>
#include "course.h"
using namespace std;
class Attendance {
private:
    string courseCode;
    int totalClasses;
    int classesAttended;

public:
    Attendance() : courseCode(""), totalClasses(0), classesAttended(0) {}

    Attendance(string courseCode) : courseCode(courseCode), totalClasses(0), classesAttended(0) {}

    void markAttendance(bool isPresent) {
        totalClasses++;
        if (isPresent) {
            classesAttended++;
        }
    }

    float getAttendancePercentage() const {
        if (totalClasses == 0) return 0;
        return (static_cast<float>(classesAttended) / totalClasses) * 100.0f;
    }

    void displayAttendance() const {
        cout << "Attendance in " << courseCode << ": " << getAttendancePercentage() << "%" << endl;
    }

    string getCourseCode() const {
        return courseCode;
    }
};

class marks
{
private:
    string assessment_type;
    float marks_obtained;
    float total;
    string subject;
public:
    marks()
    {
        assessment_type = "";
        marks_obtained = 0;
        total = 0;
    }
   
    marks(const string &name, float m, float t,const string& sub) : assessment_type(name), marks_obtained(m), total(t),subject(sub) {}
    string getsubject(){
        return subject;
    }
    
    void setName(string name)
    {
        assessment_type = name;
    }
    
    void setmarks(float mark)
    {
        marks_obtained = mark;
    }
    void settotal(float total)
    {
        this->total = total;
    }
    string getName()
    {
        return assessment_type;
    }
    float getmarks()
    {
        return marks_obtained;
    }
    float gettotal()
    {
        return total;
    }
    void display()
    {
        cout <<subject<<" : "<<endl;
        cout<< assessment_type << " "
             << "Total: " << total << " "
             << "Obtained : " << marks_obtained << endl;
    }
};
class course;
class student // deals with basic information of individual students
{
private:
    string name;
    string rollnumber;
    int age;
    string contact;
    marks *assessments;  
    int assessmentCount; 
    int assessmentCapacity;
    course *enrolledcoursesname;
    string *enrolledcourses;
    float attendance;
    int totalcourses_enrolled;
    int currentcoursecount;
    string course;
    float attendancee;
    Attendance *track_attendance;
    int attendance_count;
    

public:
    student();
    student(string name, string rollnumber, string contact, int age);
    void setdata(string name, string rollnumber, int age, string contact, string course, float attendance, int totalcourses_enrolled);
    student(string name, string rollnumber, int age, string contact, string course, float attendance, int totalcourses_enrolled);
    //student(string name, string rollnumber, string contact,int age, string course, float attendance, float marks, int totalcourses_enrolled);
    string getname() const;
    string getrollnum() const;
    int getage() const;
    string getcontact() const;
    string getcourse();
    float getattendance();
    void input_details();
    void registercourse(string &code);
    void withdrawcourse(string &code);
    void setname(string updatename);
    void setcontact(string contact);
    void setrollnumber(string roll);
    void assignmarks(string code);
    bool check_course(string code);
    void arrayy();
    void displaymarks(string code);
    void mark_attendance(string code);
    void display_attendance(string code);
    ~student();
};
student::student()
{

    totalcourses_enrolled = 5;
    currentcoursecount = 0;
    attendance = 0;
    assessmentCount = 0;
    assessmentCapacity = 5; 
    enrolledcourses = new string[totalcourses_enrolled];
    assessments = new marks[assessmentCapacity];
    attendancee=100;
    attendance_count=0;
    track_attendance=new Attendance[5];
}
bool student::check_course(string code)
{
    for (int i = 0; i < currentcoursecount; i++)
    {
        if (enrolledcourses[i] == code)
        {
            return true;
        }
    }
    return false;
}
void student::registercourse(string &code)
{
    // currentcoursecount=0;
    // totalcourses_enrolled=5;
    cout << currentcoursecount;
    cout << totalcourses_enrolled;
    if (currentcoursecount < totalcourses_enrolled)
    {

        enrolledcourses[currentcoursecount] = code;
        currentcoursecount++;
        cout << "enrolled in course" << code << endl;
    }
    else
    {
        cout << "Sorry, cannot enroll in this course as no space left" << endl;
    }
}
void student::arrayy()
{
    for (int i = 0; i < currentcoursecount; i++)
    {
        if (enrolledcourses[i] != " ")
        {
            cout << i + 1 << " : " << enrolledcourses[i] << endl;
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

void student::withdrawcourse(string &code)
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
        cout << "Course not found: " << code << endl;
    }
}

student::student(string name, string rollnumber, string contact, int age)
{

    this->name = name;
    this->rollnumber = rollnumber;
    this->age = age;
    this->contact = contact;
    totalcourses_enrolled = 5;
    currentcoursecount = 0;
    attendance = 0;
    assessmentCount = 0;
    assessmentCapacity = 5; 
    enrolledcourses = new string[totalcourses_enrolled];
    assessments = new marks[assessmentCapacity];
    attendancee=100;
        attendance_count=0;
    track_attendance=new Attendance[totalcourses_enrolled];

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
    cout << rollnumber << endl;
    cout << "Enter your contact" << endl;
    getline(cin, contact);
    cout << "Enter your age" << endl;
    cin >> age;
    cin.ignore(); // Clear the input buffer after reading an integer
}

void student::setdata(string name, string rollnumber, int age, string contact, string course, float attendance, int totalcourses_enrolled)
{
    this->name = name;
    this->rollnumber = rollnumber;
    this->age = age;
    this->contact = contact;
    this->course = course;
    this->attendance = attendance;
    this->totalcourses_enrolled = totalcourses_enrolled;
}
student::student(string name, string rollnumber, int age, string contact, string course, float attendance, int totalcourses_enrolled)
{
    this->name = name;
    this->rollnumber = rollnumber;
    this->age = age;
    this->contact = contact;
    this->course = course;
    this->attendance = attendance;
    this->totalcourses_enrolled = totalcourses_enrolled;
    attendance = 0;
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


void student:: assignmarks(string code)
{
    string assessmentType;
    for(int i=0;i<currentcoursecount;i++)
    {
        if(enrolledcourses[i]==code){
    cout<<"Assigning marks for  "<<code<<endl;
    float totalMarks, score;
    cout << "Enter the type of assessment-- quiz/mids/final: ";
    cin >> assessmentType;
    cout << "Enter the total for this assessment: ";
    cin >> totalMarks;
    cout << "Enter the score of the student for this " << assessmentType << ": ";
    cin >> score;

    if (assessmentCount == assessmentCapacity)
    {
        // Resize array
        int newCapacity = assessmentCapacity * 2;
        marks *newAssessments = new marks[newCapacity];
        for (int i = 0; i < assessmentCount; i++)
        {
            newAssessments[i] = assessments[i];
        }
        delete[] assessments;
        assessments = newAssessments;
        assessmentCapacity = newCapacity;
    }

    assessments[assessmentCount++] = marks(assessmentType, score, totalMarks,code);
    cout<<"Marks for "<<assessmentType<<"has been added"<<endl;
    break;
        }
    }
}
void student::displaymarks(string code){
cout<<"display marks"<<endl;
 for(int i=0;i<currentcoursecount;i++)
 {
    if(enrolledcourses[i]==code)
    {
        for(int i=0;i<assessmentCount;i++)
        {
            if(assessments[i].getsubject()==code)
            {
                cout<<"displaying"<<endl;
                assessments[i].display();
            }
            else
            {
                cout<<"you are not marked for it yet"<<code<<endl;
            }
        }

    }
 }
}
void student::mark_attendance(string code) {
    // Find the Attendance object for the specified course
    for (int i = 0; i < attendance_count; ++i) {
        if (track_attendance[i].getCourseCode() == code) {
            cout << "Enter P/A for attendance in " << code << ": ";
            char a;
            cin >> a;
            track_attendance[i].markAttendance(a == 'P' || a == 'p');
            return;
        }
    }

    // If Attendance object for the course not found, create new
    cout << "Enter P/A for attendance in new course " << code << ": ";
    char a;
    cin >> a;
    track_attendance[attendance_count++] = Attendance(code);
    track_attendance[attendance_count - 1].markAttendance(a == 'P' || a == 'p');
}

void student::display_attendance(string code) {
    for (int i = 0; i < attendance_count; ++i) {
        if (track_attendance[i].getCourseCode() == code) {
            track_attendance[i].displayAttendance();
            return;
        }
    }
    cout << "No attendance record found for course " << code << endl;
}



student::~student()
{
    delete[] enrolledcourses;
    delete[] assessments;
}