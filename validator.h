#include<iostream>
using namespace std;
#pragma

class validator{
    public:
    validator(){}//default constructor
bool isValid(student *obj) {
    // Check name is not empty
    int nameLength = 0;
    for (char c : obj->getname()) { ++nameLength; } // Replace obj.name with obj.getName() if name is private
    if (nameLength == 0) {
        cout << "Name has to be provided." <<endl;
        return false;
    }

    // Check age is greater than 16
    if (obj->getage() <= 16) {
        std::cout << "Being older than 16 is required." << std::endl;
        return false;
    }

    // Check roll number format 'L' or 'l' followed by 22-xxxx
    int rollNumberLength = 0;
    for (char c : obj->getrollnum()) { ++rollNumberLength; } // Replace obj.rollNumber with obj.getRollNumber() if rollNumber is private
    // if (rollNumberLength != 9 || (obj->getrollnum()[0] != 'L' && obj->getrollnum()[0] != 'l') || obj->getrollnum()[3] != '-') {
    //     std::cout << "Invalid roll number format." << std::endl;
    //     return false;
    // }
    // for (int i = 4; i < rollNumberLength; ++i) {
    //     if (obj->getrollnum()[i] < '0' || obj->getrollnum()[i] > '9') {
    //         std::cout << "Invalid roll number format." << std::endl;
    //         return false;
    //     }
    // }
    if(rollNumberLength!=8)
    {
        cout<<"invalid roll number"<<endl;
        return false;
    }

    // Check contact number is 11 digits
    int contactNumberLength = 0;
    for (char c : obj->getcontact()) { ++contactNumberLength; } // Replace obj.contact with obj.getContact() if contact is private
    if (contactNumberLength != 11) {
        std::cout << "Contact number must be 11 digits." << std::endl;
        return false;
    }
    for (char digit : obj->getcontact()) {
        if (digit < '0' || digit > '9') {
            std::cout << "Contact number must be 11 digits." << std::endl;
            return false;
        }
    }

    // If all validations pass
    return true;
}
~validator(){}
};