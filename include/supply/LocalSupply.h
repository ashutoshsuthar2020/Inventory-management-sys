#ifndef LOCALSUPPLY_H
#define LOCALSUPPLY_H

#include "Supply.h"

class LocalSupply: public Supply{
    private:
        std::string nameOfOrigin;
        Date dateOfDeparture;
        std::string vehicle;
        std::string vehicleRegNo;
    public:
        LocalSupply();
        LocalSupply(std::string name , std::string amount, Date d , std::string s, std::string origin, Date departureDate, std::string v, std::string regNo);
        void getData();
        std::string getNameOfOrigin();
        Date getDateOfDeparture();
        std::string getVehicle();
        std::string getVehicleRegNo();
        ~LocalSupply();
};

#endif
