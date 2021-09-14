#include "Meatseafood.h"

Meatseafood::Meatseafood():Item(){
    do{
        std::cout<<"Enter weight of item : ";
        while (!(std::cin >> weightOfItem)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Enter a suitable value : ";
        }
    }while (0 > weightOfItem);
}

Meatseafood::Meatseafood(std::string a,float b,float c,double d):Item(a,b,c),weightOfItem(d){}

double Meatseafood::returnWeightOfItem(){
    return weightOfItem;
}

double* Meatseafood::returnPointerWeightOfItem(){
    return &weightOfItem;
}
