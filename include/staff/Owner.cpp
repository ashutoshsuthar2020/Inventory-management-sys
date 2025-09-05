#include "Owner.h"

extern std::vector<Staff> staffData;
extern std::unordered_map<std::string, std::string> userCredentialsMap;
extern std::unordered_map<std::string, std::string> staffPositionMap;
extern std::unordered_map<std::string, std::string> fullNameMap;
extern void saveStaffDetails();
extern std::string enterFN();
extern std::string enterUN();
extern std::string enterPW();
extern Date enterDate();
extern std::string enterPos();

Owner::Owner(std::string fullName, std::string userName): Staff(fullName, "Owner", userName) {}

void Owner::addStaff(std::string userName, std::string password, std::string fullName, std::string position, Date date){
    if(position == "Owner"){
        setIsRootCreated();
    }

    Staff newStaff(fullName, position, date, userName, password);
    staffData.emplace_back(newStaff);

    userCredentialsMap[userName] = password;
    staffPositionMap[userName] = position;

    std::cout << "\nAn account was created for " << position << ", " << fullName << ".\n\nPress enter to go back\n"; 
    getchar();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    saveStaffDetails();
}	

void Owner::removeStaff(){
    std::string username;
    bool userChk;
    do{
        userChk = false;
        std::cout << "Enter username of staff that you want to delete :";
        std::cin >> username;
    }while(userCredentialsMap.find(username) == userCredentialsMap.end());
    if(getUserName() == username){
        std::cout << "\nYou are trying to remove root(Owner) account. Which will cause deletion of all company data & quit the programme.\n";
        std::cout << "In case of owner has changed, you can change the owner information\n\n\n";
        char s;
        do{
            std::cout << "If you want to delete owner account press \"Y\"\n";
            std::cout << "\nTo close this window press \"N\"\n";
            std::cin >> s;
        }while(s != 'Y' && s != 'N' && s != 'T');
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        switch(s){
            case 'Y':
                staffData.clear();
                userCredentialsMap.clear();
                staffPositionMap.clear();
                saveStaffDetails();
                exit(0);
                break;
            case 'N':
                break;
        }
        return;
    }
    if(staffPositionMap.erase(username)){
        for(int i = 0; i < staffData.size(); i++){
            if(staffData[i].getUserName() == username){
                staffData.erase(staffData.begin() + i);
            }
        }
        userCredentialsMap.erase(username);
        saveStaffDetails();
    }
    else{
        std::cout << "\nUser not found !!\n";
        system("pause");
    }
}

void Owner::userInputFunc(){
    Date date;

    std::string fullName;
    std::string userName;
    std::string position;
    std::string password;
    
    getchar();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "\nADDING NEW STAFF DETAILS\n";
    fullName = enterFN();
    date = enterDate();
    position = enterPos();

    std::cout << "\n\n..This one is for login process of user..\n\n";

    userName = enterUN();
    password = enterPW();

    addStaff(userName, password, fullName, position, date);
}

Owner::~Owner(){}

