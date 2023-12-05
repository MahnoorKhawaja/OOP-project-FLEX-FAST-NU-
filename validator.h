#pragma once
#include<iostream>
//#include"student.h"
using namespace std;


class validator{
    public:
    validator(){}//default constructor hehe
bool isValid(student *obj) {
    // check name is not empty
    int nameLength = 0;
    for (char c : obj->getname()) { ++nameLength; } 
    if (nameLength == 0) {
        cout << "Name has to be provided." <<endl;
        return false;
    }

    // check age is greater than 16
    if (obj->getage() <= 16) {
        cout << "Being older than 16 is required." << endl;
        return false;
    }

    int rollNumberLength = 0;
    for (char c : obj->getrollnum()) { ++rollNumberLength; } 

    if(rollNumberLength!=8)
    {
        cout<<"invalid roll number"<<endl;
        return false;
    }

    // Check contact number is 11 digits
    int contactNumberLength = 0;
    for (char c : obj->getcontact()) { ++contactNumberLength; } 
    if (contactNumberLength != 11) {
        cout << "Contact number must be 11 digits." <<endl;
        return false;
    }
    for (char digit : obj->getcontact()) {
        if (digit < '0' || digit > '9') {
            cout << "Contact number must be 11 digits." <<endl;
            return false;
        }
    }


    return true;
}
~validator(){}
};