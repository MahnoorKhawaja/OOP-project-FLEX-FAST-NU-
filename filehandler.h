#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<limits>
using namespace std;

#pragma

class filehandler
{
    string studentfilename;
    string coursefilename;

public:
    filehandler() {}
    filehandler(string studentname, string coursename, student s) : studentfilename(studentname), coursefilename(coursename) {}
    static void savestudent_tofile(const student &Student);
    static void loadstudents();
    static void clear_and_update(student **Student, int &total);
    static void loadfromfile(student **&student, int &totalstudents);
    static void readfromfile(int &totalstudents);
    static void loadcoursesdetails(course **courses, int totalcourses);
    static void savemarks(const student &Student);
    ~filehandler() {}
};
void filehandler::loadcoursesdetails(course **courses, int totalcourses)
{
    ofstream outfile("course.txt", ios::out);
    if (outfile.is_open())
    {
        for (int i = 0; i < totalcourses; i++)
        {
            string details = courses[i]->getEnrolledStudentsDetails();
            outfile << details;
        }
        outfile.close();
    }
    else
    {
        cout << "unable to open course file" << endl;
    }
}
void filehandler::loadfromfile(student **&studentarray, int &totalstudents) {
    ifstream file("student.txt");
    if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        return;
    }
    string name, rollnumber, contact;
    int age;
    int capacity = 20;
    studentarray = new student *[capacity];

    while (getline(file, name, ',') &&
           getline(file, rollnumber, ',') &&
           getline(file, contact, ',') &&
           (file >> age)) {

        file.ignore(numeric_limits<streamsize>::max(), '\n');

        studentarray[totalstudents] = new student(name, rollnumber, contact, age);
        totalstudents++;
        if (totalstudents == capacity) {
            capacity *= 2;
            student **temp = new student *[capacity];
            for (int i = 0; i < totalstudents; i++) {
                temp[i] = studentarray[i];
            }
            delete[] studentarray;
            studentarray = temp;
        }
    }

    file.close();
}


void filehandler::readfromfile(int &totalstudents)
{
    ifstream infile("student.txt");
    string line;
    cout << "total number of students currently enrolled are: " << totalstudents << endl;
    cout << endl;
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            cout << line;
            cout << endl;
        }
        infile.close();
    }
}
void filehandler::savestudent_tofile(const student &Student)
{

    ofstream file("student.txt", ios::app);
    if (file.is_open())
    {
        file << Student.getname() << "," << Student.getrollnum() << "," << Student.getcontact() << "," << Student.getage() << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

void filehandler::clear_and_update(student **Student, int& total)
{
    ofstream file("student.txt", ios::out);

    if (file.is_open())
    {
        for (int i = 0; i < total; i++)
        {
            if (Student[i] != nullptr)
            {
                file << Student[i]->getname() << "," << Student[i]->getrollnum() << "," << Student[i]->getcontact() << "," << Student[i]->getage() << endl;
            }
        }
        file.close();
    }

    else
    {
        cout << "Unable to open file for writing." << endl;
    }
}
