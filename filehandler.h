#include<iostream>
#include<fstream>


using namespace std;

#pragma

class filehandler{
    private:
    string studentfilename;
    string coursefilename;
    public:
    filehandler(string studentname,  string coursename,student s):studentfilename(studentname),coursefilename(coursename){}
    static void savestudent_tofile(const student& Student );
    // void updated_student();
    // void removestudent(string rollnumber);
    // void loadstudents();
};

 void filehandler::savestudent_tofile(const student& Student)
{
    // Open file
    ofstream file("studentlist.txt", ios::app); // Use member variable studentfilename
    if (file.is_open()) {
        file << Student.getrollnum() << ","
             << Student.getname() << ","
             << Student.getage() << ","
             << Student.getcontact() << endl; // Use endl to write a new line
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}
