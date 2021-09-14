#include "Staff.h"
#include "Owner.h"

extern std::vector<Staff> staffData;
extern std::unordered_map<std::string, std::string> userCredentialsMap;
extern std::unordered_map<std::string, std::string> staffPositionMap;
extern std::unordered_map<std::string, std::string> fullNameMap;

std::string enterFN();
std::string enterUN();
std::string enterPW();
Date enterDate();
std::string enterPos();

bool Staff::isRootCreated = false;

Staff::Staff() {}
Staff::Staff(std::string fullName, std::string position, Date date, std::string userName, std::string password): 
                            userName(userName), password(password), fullName(fullName), position(position), date(date) {}

Staff::Staff(std::string fullName, std::string position, std::string userName): userName(userName), fullName(fullName), date(date) {}

bool Staff::getIsRootCreated(){
	return isRootCreated;
}

void Staff::setIsRootCreated(){
	isRootCreated = true;
}

std::string Staff::getFullName(){
    return fullName;
}

void Staff::setFullName(){
	fullName = enterFN();
}

std::string Staff::getUserName(){
	return userName;
}

void Staff::setUserName(){
	userName = enterUN();
}

std::string Staff::getPassword(){
	return password;
}

void Staff::setPassword(){
	password = enterPW();
}

std::string Staff::getPosition(){
	return position;
}

void Staff::setPosition(){
	position = enterPos();
}

Date Staff::getDate(){
	return date;
}

void Staff::setDate(){
	date = enterDate();
}

void retrieveStaffDetails(){
    std::string fullName, position, userName, password;
    Date date;
    std::ifstream file("./test/staff/staffData.txt");
    int i = 0;
    if(file.is_open()){
        while(!file.eof()){
            if(i == 0){
                getline(file, fullName);
            }
            else if(i == 1){
                file >> position >> date.day >> date.month >> date.year >> userName;
                getline(file, password);
            }
            else if(i == 2){
                getline(file, password);
            }
            else{
                Staff newStaff(fullName, position, date, userName, password);
                staffData.emplace_back(newStaff);
                userCredentialsMap[userName] = password;
                staffPositionMap[userName] = position;
                fullNameMap[userName] = fullName;
                i = -1;
                Staff::setIsRootCreated();
            }
            i++;
           }
    }
    if(!Staff::getIsRootCreated()){
        Owner owner("dummy", "dummy");
        std::cout << "Looks like there is no root(Owner) in this system. Press Enter to create\n";
        owner.userInputFunc();
    }
}

void saveStaffDetails(){
    std::ofstream file;
    file.open("./test/staff/staffData.txt");
    for(int i = 0; i < staffData.size(); i++){
        file << staffData[i].getFullName() << "\n" << staffData[i].getPosition() << " " << staffData[i].getDate().day << " "
             << staffData[i].getDate().month << " " << staffData[i].getDate().year << " " << staffData[i].getUserName() << "\n" << staffData[i].getPassword() << '\n';
    }
    file.close();
}

std::string enterFN(){
	std::string fullName;
    std::cout << "\nEnter fullname : ";
    std::getline(std::cin, fullName);
    return fullName;
}

Date enterDate(){
	Date date;
    do{
        std::cout << "Enter joined date (put space between date, month & year like, dd mm yyyy format) : ";
        std::cin >> date.day >> date.month >> date.year;
    }while(date.day <= 0 || date.day > 31 || date.month <= 0 || date.month > 12 || date.year <= 1940 || date.year > 2200);
    return date;
}

std::string enterPos(){
	std::string position;
    if(Staff::getIsRootCreated()){
        do{
            std::cout << "Positions in this business are,\n";
            std::cout << "\tManager\n\tCashier\n\tFloorWorker\n";
            std::cout << "Enter position (Use same naming convention) :";
            std::cin >> position;
        }while(position != "Manager" && position != "Cashier" && position != "FloorWorker");
        return position;
    }
    return ("Owner");
}

std::string enterUN(){
    bool userChk;
    std::string userName;
    do{
        userChk = false;
        std::cout << "\nEnter username(NO SPACES) : ";
        std::cin >> userName;

        if(!(userCredentialsMap.find(userName) == userCredentialsMap.end())){
            userChk = true;
            std::cout << "username not available";
        }
    }while(userChk);
    return userName;
}

std::string enterPW(){
    bool userChk;
    std::string password, password2;
    getchar();
    do{
        userChk = false;
        std::cout << "Password, \n* More than 6 characters \n* Must have an Uppercase letter \n* Must be alphanumeric \n" ;//make star when typing
        std::cout << "Enter password  : ";
        std::getline(std::cin, password);

        bool capNotChk = true;
        bool alphaNumNotChk = true;

        if(password.length() < 6){
            userChk = true;
        }
        else{
            for(int i = 0; i < password.length(); i++){
                if(password.at(i) >= 'A' && password.at(i) <= 'Z'){
                    capNotChk = false;
                }
                if(password.at(i) >= '0' && password.at(i) <= '9'){
                    alphaNumNotChk = false;
                }
                if(password.at(i) == ' '){
                    alphaNumNotChk = false;
                }
            }
            if(alphaNumNotChk || capNotChk){
                userChk = true;
            }
        }
    }while(userChk);

       do{
        std::cout << "Re-enter password : ";
        std::getline(std::cin, password2);

        if(password2 != password){
            std::cout << "passwords dont match. ..";
        }
    }while(password2 != password);
    return password;
}

