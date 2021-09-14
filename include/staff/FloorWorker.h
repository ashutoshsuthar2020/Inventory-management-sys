#ifndef FLOORWORKER_H
#define FLOORWORKER_H

#include "Staff.h"
#include "../Transaction.h"
#include "../supply/LocalSupply.h"
#include "../supply/InternationalSupply.h"

class FloorWorker: public virtual Staff{
    public:
        FloorWorker();
        FloorWorker(std::string fullName, std::string userName);
        void stockIncrement(bool isFloorWorker = true);
        ~FloorWorker();
};

#endif
