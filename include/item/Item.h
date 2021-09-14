#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>
#include <string>

class Item{
    private:
        std::string itemName;
        float retailPrice;
        float discount;
        float finalPrice;
    public:
        Item();
        Item(std::string a,float b,float c);
        std::string returnItemName();
        float returnRetailPrice();
        float returnDiscount();
        float returnFinalPrice();
};

#endif
