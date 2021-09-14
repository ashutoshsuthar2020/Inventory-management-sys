#include "FloorWorker.h"

extern std::vector<LocalSupply> localSupplyDataPending;
extern std::vector<InternationalSupply> internationalSupplyDataPending;
extern std::vector<LocalSupply> localSupplyDataApproved;
extern std::vector<InternationalSupply> internationalSupplyDataApproved;
int addOrRemoveStock(int x, Transaction *transaction = NULL);
extern int selectCategory();
extern void addNewItem(int Category);

FloorWorker::FloorWorker(){}

FloorWorker::FloorWorker(std::string fullName, std::string userName): Staff(fullName, "FloorWorker", userName){}

void FloorWorker::stockIncrement(bool isFloorWorker){
    system("cls");
    std::cout << "Current Supply Details \n";
    int i = 0, j = 0, k = 1;
    bool noneChk = true;
    
    if(localSupplyDataPending.size() > 0){
    	std::cout << "\nLocal Supply Details\n\n";
    	std::cout << "ID\tItem name\t\tQuantity  Date of Arrival  Status\tName of Origin\tDate of Departure  Vehicle\tVehicle RegNo.\n";
    	noneChk = false;
	}
    for(i; i < localSupplyDataPending.size(); i++){
	    	std::cout << k++ << "\t"<< localSupplyDataPending[i].getItemName() << "\t\t\t" <<localSupplyDataPending[i].getQuantity() << "\t     " << localSupplyDataPending[i].getDateOfArrival().day << "-" 
	        << localSupplyDataPending[i].getDateOfArrival().month  << "-" << localSupplyDataPending[i].getDateOfArrival().year << "\t   " <<  localSupplyDataPending[i].getStatus() << "\t    " 
	        << localSupplyDataPending[i].getNameOfOrigin() << "\t   " << localSupplyDataPending[i].getDateOfDeparture().day << "-" << localSupplyDataPending[i].getDateOfDeparture().month << "-" 
	        << localSupplyDataPending[i].getDateOfDeparture().year << "\t " << localSupplyDataPending[i].getVehicle() << "\t";
	        if(localSupplyDataPending[i].getVehicle() == "Van"){
	        	std::cout << "\t";
			}
			std::cout << localSupplyDataPending[i].getVehicleRegNo() << "\n";
	}
	
	if(internationalSupplyDataPending.size() > 0){
		std::cout << "\nInternational Supply Details\n\n";
    	std::cout << "ID\tItem name\t\tQuantity  Date of Arrival  Status\tCountry of Origin\t Arrival Date at Harbour  Ship No\n";
    	noneChk = false;
	}
	
	for(j; j < internationalSupplyDataPending.size(); j++){
			std::cout << k++ << "\t"<< internationalSupplyDataPending[j].getItemName() << "\t\t\t" <<internationalSupplyDataPending[j].getQuantity() << "\t     " << internationalSupplyDataPending[j].getDateOfArrival().day << "-" 
	        << internationalSupplyDataPending[j].getDateOfArrival().month  << "-" << internationalSupplyDataPending[j].getDateOfArrival().year << "\t   " <<  internationalSupplyDataPending[j].getStatus() << "\t     " 
	        << internationalSupplyDataPending[j].getcountryOfOrigin() << "   \t        " << internationalSupplyDataPending[j].getArrivalDateAtHarbour().day << "-" << internationalSupplyDataPending[j].getArrivalDateAtHarbour().month << "-" 
	        << internationalSupplyDataPending[j].getArrivalDateAtHarbour().year << "\t    " << internationalSupplyDataPending[j].getShipNo() << "\n";
	}
	
	if(noneChk){
		std::cout << "** NO DATA FOUND **\n";
		system("pause");
		return;
	}
	
	int n;
	std::cout << "\n";
	std::cout << "*Enter 0 if you want to go back*\n";
	do{
        std::cout << "Enter the id of supply detail to put it to stocks : ";
        while (!(std::cin >> n)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout << "Enter the no. of supply detail to put it to stocks : ";
        }
        if(n == 0) return;
    }while(n < 1 || n > (i + j));
    
    system("cls");
    
    if(i < n){
    	std::cout << "Item name\t\tQuantity  Date of Arrival  Status\tCountry of Origin\t Arrival Date at Harbour  Ship No\n";
    	j = n - i - 1;
    	std::cout << internationalSupplyDataPending[j].getItemName() << "\t\t\t" <<internationalSupplyDataPending[j].getQuantity() << "\t     " << internationalSupplyDataPending[j].getDateOfArrival().day << "-" 
	    << internationalSupplyDataPending[j].getDateOfArrival().month  << "-" << internationalSupplyDataPending[j].getDateOfArrival().year << "\t   " <<  internationalSupplyDataPending[j].getStatus() << "\t     " 
	    << internationalSupplyDataPending[j].getcountryOfOrigin() << "   \t        " << internationalSupplyDataPending[j].getArrivalDateAtHarbour().day << "-" << internationalSupplyDataPending[j].getArrivalDateAtHarbour().month << "-" 
	    << internationalSupplyDataPending[j].getArrivalDateAtHarbour().year << "\t    " << internationalSupplyDataPending[j].getShipNo() << "\n";
	}
	else{
		std::cout << "Item name\t\tQuantity  Date of Arrival  Status\tName of Origin\tDate of Departure  Vehicle\tVehicle RegNo.\n";
		j = n - 1 ;
		std::cout << localSupplyDataPending[j].getItemName() << "\t\t\t" <<localSupplyDataPending[j].getQuantity() << "\t     " << localSupplyDataPending[j].getDateOfArrival().day << "-" 
	    << localSupplyDataPending[j].getDateOfArrival().month  << "-" << localSupplyDataPending[j].getDateOfArrival().year << "\t   " <<  localSupplyDataPending[j].getStatus() << "\t    " 
	    << localSupplyDataPending[j].getNameOfOrigin() << "\t   " << localSupplyDataPending[j].getDateOfDeparture().day << "-" << localSupplyDataPending[j].getDateOfDeparture().month << "-" 
	    << localSupplyDataPending[j].getDateOfDeparture().year << "\t " << localSupplyDataPending[j].getVehicle() << "\t";
	    if(localSupplyDataPending[j].getVehicle() == "Van"){
	       	std::cout << "\t";
		}
		std::cout << localSupplyDataPending[j].getVehicleRegNo() << "\n";
	}
	
    int chk = 0;
    if(isFloorWorker){
		chk = addOrRemoveStock(1); //add num items
	}
	else{
		addNewItem(selectCategory());         //add new item
		chk = 1;
	}
	
	if(chk != 0){
		if(i < n){
			internationalSupplyDataPending[n - i - 1].setStatus("Approved");
			internationalSupplyDataApproved.emplace_back(internationalSupplyDataPending[n - i - 1]);
			internationalSupplyDataPending.erase(internationalSupplyDataPending.begin() + n - i - 1);
		}
		else{
			localSupplyDataPending[n - 1].setStatus("Approved");
			localSupplyDataApproved.emplace_back(localSupplyDataPending[n - 1]);
			localSupplyDataPending.erase(localSupplyDataPending.begin() + n - 1);
		}
	}
}

FloorWorker::~FloorWorker(){}
