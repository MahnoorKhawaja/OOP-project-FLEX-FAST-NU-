#include <iostream>

using namespace std;
#pragma

class Enrollment_Manager{
    public:
    Enrollment_Manager();
    void addstudent();
    
};
Enrollment_Manager::Enrollment_Manager(){
}
void Enrollment_Manager::addstudent(){
    student newstudent;
    cout<<"Enter the students details"<<endl;
    newstudent.input_details();
    filehandler::savestudent_tofile(newstudent);
    cout<<"Student added sucessfully"<<endl;

}
class System:public Enrollment_Manager // central class which interacts with the user
{

public:
    System();
    void mainmenu();
    void enrollstudentsmenu();
    void course_registrationmenu();
    void attendancemenu();
    void coursewithdrawmenu();
    void marksmenu();
    ~System();
};
System::System() {}
void System::mainmenu()
{

    cout << "FLEX COURSE MANAGEMENT SYSTEM" << endl;
    cout << "------------------------------" << endl;
    int choice;
   do{
    cout<<"-----------Main Menu------------"<<endl;
    cout<<"Enter your choice"<<endl;
    cout<<"1. Enroll a student   "<<endl;
    cout<<"2. Course Registration"<<endl;
    cout<<"3. Attendance         "<<endl;
    cout<<"4  Marks              "<<endl;
    cout<<"5. Course Withdraw    "<<endl;
    cout<<"6. Exit               "<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        enrollstudentsmenu();
        break;
        case 2:
        course_registrationmenu();
        break;
        case 3:
        attendancemenu();
        break;
        case 4:
        marksmenu();
        break;
        case 5:
        coursewithdrawmenu();
        break;
        case 6:
        cout<<"Exiting the application..."<<endl;
        break;
        default:
        cout<<"INVALID INPUT, ENTER AGAIN"<<endl;
    }   
    }while(choice!=6);
}
void System::enrollstudentsmenu(){
    cout<<"ENROLL STUDENT MENU"<<endl;
    int select;
    cout<<"1. Display already enrolled students"<<endl;
    cout<<"2. Add a student                    "<<endl;
    cout<<"3. Remove a student                 "<<endl;
    cout<<"4. Edit student detail              "<<endl;
    cout<<"5. Back to main menu                "<<endl;
    cin>>select;
    switch(select)
    {
        case 1:
        {
          
        }
        case 2:
        {
              Enrollment_Manager::addstudent();
        }
        case 3:
        {
        } 
        case 4:
        {

        }
        case 5:
        {

        }
         
    }
}
void System::course_registrationmenu(){
    cout<<"COURSE REGISTRATION MENU"<<endl;
    int select;
    cout<<"1. Available courses              "<<endl;
    cout<<"2. Register course                "<<endl; 
    cout<<"3. Back main menu                 "<<endl;
    cin>>select;
    switch(select)
    {
        case 1:{}
        case 2:{}
        case 3:{}
    }
}
void System::attendancemenu(){
    cout<<"ATTENDANCE MENU"<<endl;
    cout<<"1. Display attendance(subjectwise) "<<endl;
    cout<<"2. Mark Attendance                 "<<endl;
    cout<<"3. Back to main menu               "<<endl;
    int select;
    cin>>select;
    switch(select)
    {
        case 1:{}
        case 2:{}
        case 3:{}
    }
}
void System::marksmenu(){
    cout<<"MARKS MENU"<<endl;
    cout<<"1. Display marks(subject wise)"<<endl;
    cout<<"2. Assign marks               "<<endl;
    cout<<"3. Back to menu               "<<endl;
    int select;
    cin>>select;
     switch(select)
    {
        case 1:{}
        case 2:{}
        case 3:{}
    }
}
void System::coursewithdrawmenu(){
    cout<<"COURSE WITHDRAW MENU "<<endl;
    cout<<"1. Enrolled courses  " <<endl;
    cout<<"2. Drop a  course    "<<endl;
    cout<<"3. Back to main menu "<<endl; 
    int select;
    cin>>select;
     switch(select)
    {
        case 1:{}
        case 2:{}
        case 3:{}
    }

}
   System::~System(){}