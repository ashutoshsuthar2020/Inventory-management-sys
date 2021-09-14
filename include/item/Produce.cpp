#include "Produce.h"

Produce::Produce():Item(){
    do{
        std::cout<<"Number of Item     : ";
        while (!(std::cin >> numberOfItem)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Enter a suitable value : ";
        }
    }while (0 > numberOfItem);
}

Produce::Produce(std::string a,float b,float c,int d):Item(a,b,c),numberOfItem(d){}

int Produce::returnNumberOfItem(){
    return numberOfItem;
}

int* Produce::returnPointerNumberOfItem(){
    return &numberOfItem;
}
