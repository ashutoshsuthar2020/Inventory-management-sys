#include "LocalSupply.h"

extern std::vector<LocalSupply> localSupplyDataPending;

LocalSupply::LocalSupply(){}

LocalSupply::LocalSupply(std::string name , std::string amount, Date d , std::string s, std::string origin, Date departureDate, std::string v, std::string regNo): 
                Supply(name, amount, d,s ),nameOfOrigin(origin), dateOfDeparture(departureDate), vehicle(v), vehicleRegNo(regNo){}
                
std::string LocalSupply::getNameOfOrigin(){
	return nameOfOrigin;
}

Date LocalSupply::getDateOfDeparture(){
	return dateOfDeparture;
}

std::string LocalSupply::getVehicle(){
	return vehicle;
}

std::string LocalSupply::getVehicleRegNo(){
	return vehicleRegNo;
}
	
void LocalSupply::getData(){
	std::string name, amount, origin, v, regNo;
	Date date, departureDate;
	bool valChk;
    
    name = enterN();
    amount = enterAM();
    date = enterAD();
    origin = enterOrigin("Name of origin(Farm/Factory) :  ");
	departureDate = enterDD("Date of departure from the Farm/Factory(dd mm yy) :  ", "\nDATE OF DEPARTURE FROM FARM/FACTORY CANT BE LATER THAN DATE OF ARRIVAL AT SUPERMARKET\n", date);
    
    getchar();
    do{
        std::cout<<"Vehicle used for the transportation(Large truck/Small truck/Van) :  ";			
        std::getline(std::cin, v);
    }while(v != "Large truck" && v != "Small truck" && v != "Van");
	std::cout<<"Vehicle registration number :  ";
	std::cin>>regNo;
    LocalSupply localSupply(name, amount, date, "Pending", origin, departureDate, v, regNo);
    localSupplyDataPending.emplace_back(localSupply);
        
	std::cout << "\nSupply entry added.\n";
    system("pause");
}

LocalSupply::~LocalSupply(){}
