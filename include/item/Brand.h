#ifndef BRAND_H
#define BRAND_H

#include <string>

class Brand{
    private:
        std::string brandName;
        std::string brandRegion;
    public:
        Brand();
        Brand(std::string a,std::string b);
        std::string returnBrandName();
        std::string returnBrandRegion();
};

#endif
