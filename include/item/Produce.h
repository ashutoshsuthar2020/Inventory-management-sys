#ifndef PRODUCE_H
#define PRODUCE_H

#include "Item.h"

class Produce:public Item{
    private:
        int numberOfItem;
    public:
        Produce();
        Produce(std::string a,float b,float c,int d);
        int returnNumberOfItem();
        int*returnPointerNumberOfItem();
};

#endif
