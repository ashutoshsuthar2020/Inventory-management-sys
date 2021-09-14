#ifndef STAFF_H
#define STAFF_H

#include "../Date.h"
#include <string> 
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>


class Staff{
    private:
        static bool isRootCreated;                         //owner will be root
        std::string userName;
        std::string password;
        std::string fullName;
        std::string position;
        Date date;
    public:
        Staff();
        Staff(std::string fullName, std::string position, Date date, std::string userName, std::string password);
        Staff(std::string fullName, std::string position, std::string userName);
        static bool getIsRootCreated();
        static void setIsRootCreated();
        std::string getUserName();
        void setUserName();
        std::string getPassword();
        void setPassword();
        std::string getFullName();
        void setFullName();
        std::string getPosition();
        void setPosition();
        Date getDate();   
		void setDate();     
        ~Staff() {};
};

#endif
