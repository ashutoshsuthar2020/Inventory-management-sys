#include "Brand.h"
#include <iostream>

Brand::Brand(){
	getchar();
    std::cout<<"Enter Brand name   : ";
    std::getline(std::cin, brandName);
    do{
	    std::cout<<"Enter Brand region (Local / Imported) : ";
	    std::cin>>brandRegion;
	}while(brandRegion != "Local" && brandRegion != "Imported");
}

Brand::Brand(std::string a,std::string b):brandName(a),brandRegion(b){}

std::string Brand::returnBrandName(){
    return brandName;
}

std::string Brand::returnBrandRegion(){
    return brandRegion;
}
