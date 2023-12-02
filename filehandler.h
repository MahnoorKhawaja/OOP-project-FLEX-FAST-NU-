#include<iostream>
#include<fstream>


using namespace std;

#pragma

class filehandler{
    private:
    string studentfilename;
    string coursefilename;
    public:
    filehandler(){}
    filehandler(string studentname,  string coursename,student s):studentfilename(studentname),coursefilename(coursename){}
    static void savestudent_tofile(const student& Student );
    static  void loadstudents();
    static void clear_and_update(student **Student,int total);
    static void loadfromfile(student **student,int& totalstudents);
    ~filehandler(){}
};
void filehandler::loadfromfile(student **student,int& totalstudents){
    
   


}
 void filehandler::savestudent_tofile(const student& Student)
{
     
    // Open file
    ofstream file("student.txt", ios::app); // Use member variable studentfilename
    if (file.is_open()) {
        file <<Student.getname() << "," <<Student.getrollnum() <<","<<Student.getcontact()<<","<<Student.getage() << endl; 
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void filehandler::clear_and_update(student  **Student,int total){
      ofstream file("student.txt", ios::trunc); // Open file in truncate mode

    if (file.is_open()) {
        for (int i=0;i<total;i++) {
            if(Student[i]!=nullptr){
               file <<Student->getname() << "," <<Student->getrollnum() <<","<<Student->getcontact()<<","<<Student->getage() << endl; 
        }
        file.close();
    } else {
        cout << "Unable to open file for writing." <<endl;
    }
}
}

