#ifndef CASHIER_H
#define CASHIER_H

#include "Staff.h"
#include "../Transaction.h"

class Cashier: public virtual Staff{
    public:
        Cashier();
        Cashier(std::string fullName, std::string userName);
        void makeTransaction(std::string userName);
        void stockDecrement();
        ~Cashier();
};

#endif
