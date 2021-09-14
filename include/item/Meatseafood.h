#ifndef MEATSEAFOOD_H
#define MEATSEAFOOD_H

#include "Item.h"

class Meatseafood:public Item{
    private:
        double weightOfItem;
    public:
        Meatseafood();
        Meatseafood(std::string a,float b,float c,double d);
        double returnWeightOfItem();
        double* returnPointerWeightOfItem();
};

#endif
