#ifndef MANAGER_H
#define MANAGER_H

#include "FloorWorker.h"
#include "Cashier.h"

class Manager: public FloorWorker, public Cashier{
    public:
        Manager();
        Manager(std::string fullName, std::string userName);
        void readStaffDetails();
        void addNewItemToStock();
        void viewSupplyEntry();
        ~Manager();
};

#endif
