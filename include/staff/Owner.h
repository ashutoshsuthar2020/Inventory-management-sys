#ifndef OWNER_H
#define OWNER_H

#include "Manager.h"

class Owner: public Manager{
     public:
        Owner(std::string fullName, std::string userName);
        void addStaff(std::string userName, std::string password, std::string fullName, std::string position, Date date);
        void removeStaff();
        void userInputFunc();
        ~Owner();
};

#endif

