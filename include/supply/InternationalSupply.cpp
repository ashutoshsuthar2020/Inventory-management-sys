#include "InternationalSupply.h"

extern std::vector<InternationalSupply> internationalSupplyDataPending;

InternationalSupply::InternationalSupply(){}

InternationalSupply::InternationalSupply(std::string name, std::string amount, Date d, std::string s, std::string country, Date arrivalDate, int no): 
                    Supply(name, amount, d,s ),countryOfOrigin(country), arrivalDateAtHarbour(arrivalDate), shipNo(no){}
                    
std::string InternationalSupply::getcountryOfOrigin(){
	return countryOfOrigin;
}

Date InternationalSupply::getArrivalDateAtHarbour(){
	return arrivalDateAtHarbour;
}

int InternationalSupply::getShipNo(){
	return shipNo;
}

void InternationalSupply::getData(){
	std::string name, amount, country;
	Date date, arrivalDate;
	int no;
    
    name = enterN();
    amount = enterAM();
    date = enterAD();
    country = enterOrigin("Country of origin :  ");
    arrivalDate = enterDD("Date of arrival at the local harbour(dd mm yy) :  ", "\nDATE OF ARRIVAL AT HARBOUR CANT BE LATER THAN DATE OF ARRIVAL AT SUPERMARKET\n", date);
	
    std::cout<<"Ship number :  ";	
    while (!(std::cin >> no)){
        std::cin.clear(); // clear the fail bit
        std::cin.ignore(100, '\n'); // ignore the invalid entry
        std::cout << "Please Enter a valid value:  ";
    }
	InternationalSupply internationalSupply(name, amount, date, "Pending", country, arrivalDate, no);
    internationalSupplyDataPending.emplace_back(internationalSupply);
    
    std::cout << "\nSupply entry added.\n";
    system("pause");
}

InternationalSupply::~InternationalSupply(){}
