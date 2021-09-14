#ifndef INTERNATIONALSUPPLY_H
#define INTERNATIONALSUPPLY_H

#include "Supply.h"

class InternationalSupply: public Supply{
    private:
        std::string countryOfOrigin;
        Date arrivalDateAtHarbour;
        int shipNo;
    public:
        InternationalSupply();
        InternationalSupply(std::string name, std::string amount, Date d, std::string s, std::string country, Date arrivalDate, int no);
        void getData();
        std::string getcountryOfOrigin();
        Date getArrivalDateAtHarbour();
        int getShipNo();
        ~InternationalSupply();
};

#endif
