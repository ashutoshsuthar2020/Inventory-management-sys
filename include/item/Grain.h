#ifndef GRAIN_H
#define GRAIN_H

#include "Brand.h"
#include "Meatseafood.h"

class Grain:public Meatseafood,public Brand{
	public:
        Grain();
        Grain(std::string a,float b,float c,double d,std::string e,std::string f);
};

#endif
