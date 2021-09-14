#ifndef SUPPLY_H
#define SUPPLY_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../Date.h"

extern std::string enterN();
extern std::string enterAM();
extern Date enterAD();
extern std::string enterOrigin(std::string str);
extern Date enterDD(std::string str1, std::string str2, Date date);

class Supply {
    private:
        std::string quantity;
        Date dateOfArrival;
        std::string itemName ;
        std::string status;
    public:
        Supply() {}
        Supply( std::string name, std::string amount, Date d, std::string s);
        std::string getQuantity();
        Date getDateOfArrival();
        std::string getItemName();
        std::string getStatus();
        void setStatus(std::string s);
        ~Supply(){}
};

void retrieveSupplyDetails();
void saveSupplyDetails();

#endif
