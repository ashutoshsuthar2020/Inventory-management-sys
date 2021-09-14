#ifndef BAKERYFROZENDIARYSNACKSBEVERAGESHEALTHCONDIMENTS_H
#define BAKERYFROZENDIARYSNACKSBEVERAGESHEALTHCONDIMENTS_H

#include "Produce.h"
#include "Brand.h"

class BakeryFrozenDiarySnacksBeveragesHealthCondiments:public Produce,public Brand{
	public:
        BakeryFrozenDiarySnacksBeveragesHealthCondiments();
        BakeryFrozenDiarySnacksBeveragesHealthCondiments(std::string a,float b,float c,int d,std::string e,std::string f);
};

#endif