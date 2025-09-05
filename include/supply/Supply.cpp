#include "Supply.h"
#include "LocalSupply.h"
#include "InternationalSupply.h"

extern std::vector<LocalSupply> localSupplyDataPending;
extern std::vector<InternationalSupply> internationalSupplyDataPending;
extern std::vector<LocalSupply> localSupplyDataApproved;
extern std::vector<InternationalSupply> internationalSupplyDataApproved;

Supply::Supply( std::string name, std::string amount, Date d, std::string s):itemName(name), quantity(amount), dateOfArrival(d),status(s) {}

std::string Supply::getQuantity(){
	return quantity;
}
        
Date Supply::getDateOfArrival(){
	return dateOfArrival;
}

std::string Supply::getItemName(){
	return itemName;
}

std::string Supply::getStatus(){
	return status;
}

void Supply::setStatus(std::string s){
	status = s;
}

std::string enterN(){
	std::string name;
    getchar();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout<<"--- Enter the details of the item ---\n";
    std::cout<<"Name :  ";
    std::getline(std::cin, name);
    return name;
}
std::string enterAM(){
	std::string amount;
	bool valChk;
	do{
    	valChk = false;
		std::cout<<"Amount (if Kg/g put it next to quantity like, xxKg / xxg):  ";
		std::cin >> amount;
		
		for(int i = 0; i < amount.length(); i++){
			if(amount.at(i) >= '0' && amount.at(i) <='9'){
			}
			else if(amount.at(i) == 'g' && i == (amount.length() - 1)){
			}
			else if(amount.at(i) == 'K' && i ==(amount.length() - 2)){
			}
			else{
				valChk = true;
			}
		}
		if(valChk){
			std::cout << "\nPut it in correct format\n";
		}
     }while(valChk);
     return amount;
}

Date enterAD(){ 
	Date date;
	do{
        std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        while (!(std::cin >> date.day)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        }
        while (!(std::cin >> date.month)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        }
        while (!(std::cin >> date.year)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        }
    }while(date.day<1||date.day>30||date.month<1||date.month>12||date.year<1940||date.year>2200);
    return date;
}

std::string enterOrigin(std::string str){
	getchar();
	std::string origin;
	std::cout<<str;
	std::getline(std::cin, origin);
	return origin;
}

Date enterDD(std::string str1, std::string str2, Date date){
	Date date2;
	do{
        std::cout<< str1;
        while (!(std::cin >> date2.day)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<< str1;
        }
        while (!(std::cin >> date2.month)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<< str1;
        }
        while (!(std::cin >> date2.year)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<< str1;
        }
    }while(date2.day<1||date2.day>30||date2.month<1||date2.month>12||date2.year<1940||date2.year>2200);
    while((date2.year * 365 + date2.month * 30 + date2.day) > (date.year * 365 + date.month * 30 + date.day)){
        std::cout << str2;
            do{
                std::cout<< str1;
                while (!(std::cin >> date2.day)){
                    std::cin.clear(); // clear the fail bit
                    std::cin.ignore(100, '\n'); // ignore the invalid entry
                    std::cout<< str1;
                }
                while (!(std::cin >> date2.month)){
                    std::cin.clear(); // clear the fail bit
                    std::cin.ignore(100, '\n'); // ignore the invalid entry
                    std::cout<< str1;
                }
                while (!(std::cin >> date2.year)){
                    std::cin.clear(); // clear the fail bit
                    std::cin.ignore(100, '\n'); // ignore the invalid entry
                    std::cout<< str1;
                }
            }while(date2.day<1||date2.day>30||date2.month<1||date2.month>12||date2.year<1940||date2.year>2200);
    }
    return date2;
}

void retrieveSupplyDetails(){
    std::string name, amount, s, origin, v, regNo;
    int shipNo;
    Date d, departureDate;
    std::ifstream file("./test/supply/localSupplyDataPending.txt");
    int i = 0;
    {
        if(file.is_open()){
            while(!file.eof()){
                if(i == 0){
                    getline(file, name);
                }
                else if(i == 1){
                    file >> amount >> d.day >> d.month >> d.year >> s;
                    getline(file, origin);
                }
                else if(i == 2){
                    getline(file, origin);
                }
                else if(i == 3){
                    file >> departureDate.day >> departureDate.month >> departureDate.year;
                    getline(file, v);
                }
                else if(i == 4){
                    getline(file, v);
                }
                else if(i == 5){
                    getline(file, regNo);
                }
                else{
                    LocalSupply localSupply(name, amount, d, s, origin, departureDate, v, regNo);
                    localSupplyDataPending.emplace_back(localSupply);
                    i = -1;
                }
                i++;
            }
        }
    }

    {
        std::ifstream file("./test/supply/internationalSupplyDataPending.txt");
        i = 0;
        if(file.is_open()){
            while(!file.eof()){
                if(i == 0){
                    getline(file, name);
                }
                else if(i == 1){
                    file >> amount >> d.day >> d.month >> d.year >> s;
                    getline(file, origin);
                }
                else if(i == 2){
                    getline(file, origin);
                }
                else if(i == 3){
                    file >> departureDate.day >> departureDate.month >> departureDate.year;
                }
                else if(i == 4){
                    file >> shipNo;
                    getline(file, regNo);
                }
                else{
                    InternationalSupply internationalSupply(name, amount, d, s, origin, departureDate, shipNo);
                    internationalSupplyDataPending.emplace_back(internationalSupply);
                    i = -1;
                }
                i++;
            }
        }
    }
}

void saveSupplyDetails(){
	std::string lName[2] = {"./test/supply/localSupplyDataPending.txt", "./test/supply/localSupplyDataApproved.txt"};
	std::string iName[2] = {"./test/supply/internationalSupplyDataPending.txt", "./test/supply/internationalSupplyDataApproved.txt"};
	
	std::vector<std::vector<LocalSupply>> lVec = {localSupplyDataPending, localSupplyDataApproved};
	std::vector<std::vector<InternationalSupply>> iVec = {internationalSupplyDataPending, internationalSupplyDataApproved};

	{
		std::ofstream file;
		for(int j = 0; j < 2; j++){
			file.open(lName[j]);
		    for(int i = 0; i < lVec[j].size(); i++){
		        file << lVec[j][i].getItemName() << "\n" <<lVec[j][i].getQuantity() << " " << lVec[j][i].getDateOfArrival().day << " " 
		        << lVec[j][i].getDateOfArrival().month  << " " << lVec[j][i].getDateOfArrival().year << " " <<  lVec[j][i].getStatus() << "\n" 
		        << lVec[j][i].getNameOfOrigin() << "\n" << lVec[j][i].getDateOfDeparture().day << " " << lVec[j][i].getDateOfDeparture().month << " " 
		        << lVec[j][i].getDateOfDeparture().year << "\n" << lVec[j][i].getVehicle() << "\n" << lVec[j][i].getVehicleRegNo() << "\n";
		    }
		    file.close();
		}
	}
    {
	    std::ofstream file;
	    for(int j = 0; j < 2; j++){
	    	file.open(iName[j]);
		    for(int i = 0; i < iVec[j].size(); i++){
		        file << iVec[j][i].getItemName() << "\n" <<iVec[j][i].getQuantity() << " " << iVec[j][i].getDateOfArrival().day << " " 
		        << iVec[j][i].getDateOfArrival().month  << " " << iVec[j][i].getDateOfArrival().year << " " <<  iVec[j][i].getStatus() << "\n" 
		        << iVec[j][i].getcountryOfOrigin() << "\n" << iVec[j][i].getArrivalDateAtHarbour().day << " " 
				<< iVec[j][i].getArrivalDateAtHarbour().month << " " << iVec[j][i].getArrivalDateAtHarbour().year << "\n" << iVec[j][i].getShipNo() << "\n";
		    }
		    file.close();
		}
	}

}
