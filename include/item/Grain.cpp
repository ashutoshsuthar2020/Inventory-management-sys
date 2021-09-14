#include "Grain.h"

Grain::Grain():Meatseafood(),Brand(){}

Grain::Grain(std::string a,float b,float c,double d,std::string e,std::string f):Meatseafood(a,b,c,d),Brand(e,f){}
