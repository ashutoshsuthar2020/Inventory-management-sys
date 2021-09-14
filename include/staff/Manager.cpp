#include "Manager.h"

extern std::vector<Staff> staffData;
extern std::vector<LocalSupply> localSupplyDataPending;
extern std::vector<InternationalSupply> internationalSupplyDataPending;
extern std::vector<LocalSupply> localSupplyDataApproved;
extern std::vector<InternationalSupply> internationalSupplyDataApproved;

Manager::Manager(){}

Manager::Manager(std::string fullName, std::string userName): Staff(fullName, "Manager", userName){}

void Manager::readStaffDetails(){
    getchar();
    std::cout << "\n\n Viewing Staff Data \n\n";
    if(staffData.size() > 0){
    	std::cout << "Full name\tPositon\t\tJoined Date\n";
	}
    for(int i = 0; i < staffData.size(); i++){
        std::cout << staffData[i].getFullName() << "\t\t" << staffData[i].getPosition() << "\t\t" << staffData[i].getDate().day << "-"
            << staffData[i].getDate().month << "-" << staffData[i].getDate().year << "\n";
    }
    std::cout << "\n\n End of Staff Data \n\nPress enter to go back";
    getchar();
}

void Manager::addNewItemToStock(){
	char c;
	do{
		std::cout << "Do you want to (A)add new item to inventory or (B)increase the stock ? ";
		std::cin >> c;
	}while(c != 'A' && c!= 'B');
	
	if(c == 'A'){
		stockIncrement(false);
	}
	else{
		stockIncrement(true);
	}
}

void Manager::viewSupplyEntry(){
	int i = 0, j = 0, k = 1;
    bool noneChk = true; 
    if(localSupplyDataPending.size() > 0 || localSupplyDataApproved.size() > 0){
    	std::cout << "\nLocal Supply Details\n\n";
    	std::cout << "ID\tItem name\t\tQuantity  Date of Arrival  Status\tName of Origin\tDate of Departure  Vehicle\tVehicle RegNo.\n";
    	noneChk = false;
	}
	
	std::vector<std::vector<LocalSupply>> lSupply = {localSupplyDataPending, localSupplyDataApproved};
	std::vector<std::vector<InternationalSupply>> iSupply = {internationalSupplyDataPending, internationalSupplyDataApproved};
	
	for(int x = 0; x < lSupply.size(); x++){
		for(i; i < lSupply[x].size(); i++){
	    	std::cout << k++ << "\t"<< lSupply[x][i].getItemName() << "\t\t\t" <<lSupply[x][i].getQuantity() << "\t     " << lSupply[x][i].getDateOfArrival().day << "-" 
	        << lSupply[x][i].getDateOfArrival().month  << "-" << lSupply[x][i].getDateOfArrival().year << "\t   " <<  lSupply[x][i].getStatus() << "\t    " 
	        << lSupply[x][i].getNameOfOrigin() << "\t   " << lSupply[x][i].getDateOfDeparture().day << "-" << lSupply[x][i].getDateOfDeparture().month << "-" 
	        << lSupply[x][i].getDateOfDeparture().year << "\t " << lSupply[x][i].getVehicle() << "\t";
	        if(lSupply[x][i].getVehicle() == "Van"){
	        	std::cout << "\t";
			}
			std::cout << lSupply[x][i].getVehicleRegNo() << "\n";
		}		
	}
	
	if(internationalSupplyDataPending.size() > 0 || internationalSupplyDataApproved.size() > 0){
		std::cout << "\nInternational Supply Details\n\n";
    	std::cout << "ID\tItem name\t\tQuantity  Date of Arrival  Status\tCountry of Origin\t Arrival Date at Harbour  Ship No\n";
    	noneChk = false;
	}
	
	for(int x = 0; x < iSupply.size(); x++){
		for(j; j < iSupply[x].size(); j++){
			std::cout << k++ << "\t"<< iSupply[x][j].getItemName() << "\t\t\t" <<iSupply[x][j].getQuantity() << "\t     " << iSupply[x][j].getDateOfArrival().day << "-" 
		    << iSupply[x][j].getDateOfArrival().month  << "-" << iSupply[x][j].getDateOfArrival().year << "\t   " <<  iSupply[x][j].getStatus() << "\t     " 
		    << iSupply[x][j].getcountryOfOrigin() << "   \t        " << iSupply[x][j].getArrivalDateAtHarbour().day << "-" << iSupply[x][j].getArrivalDateAtHarbour().month << "-" 
		    << iSupply[x][j].getArrivalDateAtHarbour().year << "\t    " << iSupply[x][j].getShipNo() << "\n";
		}
	}
	
	if(noneChk){
		std::cout << "** NO DATA FOUND **\n";
	}
	
	system("pause");
}

Manager::~Manager(){}

