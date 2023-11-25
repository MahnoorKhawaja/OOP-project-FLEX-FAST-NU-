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
   static  void loadstudents();
   static void clear_and_update(student **Student,int total);
};
void filehandler::loadstudents(){
    cout<<"file openning"<<endl;
    ifstream infile("student.txt");
    string line;
    if(infile.is_open())
    {
        while(getline(infile,line)){
            cout<<"read line "<< line<<endl;
        }
        infile.close();
    }
    else{
        cout<<"unable to open file"<<endl;
    }


}
 void filehandler::savestudent_tofile(const student& Student)
{
     
    // Open file
    ofstream file("student.txt", ios::app); // Use member variable studentfilename
    if (file.is_open()) {
        file << "Roll number :"<<Student.getrollnum() << endl
             << "Name        :"<<Student.getname() << endl
             << "Age         :"<<Student.getage() << endl
             << "Contact     :"<<Student.getcontact() << endl; // Use endl to write a new line
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
           file <<"Rollnumber :" << Student[i]->getrollnum() <<endl
             << "Name :"    <<  Student[i]->getname() <<endl
             << "Age: "       <<  Student[i]->getage() << endl
             << "Contact info: "<<Student[i]->getcontact() << endl;
            }    
        }
        file.close();
    } else {
        cout << "Unable to open file for writing." <<endl;
    }
}
