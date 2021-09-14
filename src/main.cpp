#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

#include "../include/staff/Owner.h"

#include "../include/supply/LocalSupply.h"
#include "../include/supply/InternationalSupply.h"

#include "../include/item/BakeryFrozenDiarySnacksBeveragesHealthCondiments.h"
#include "../include/item/Meatseafood.h"
#include "../include/item/Grain.h"	

void logIn();
int displayAllFunctions(char pos, int funcIndex);
void ownerFunctions(char pos);
void manageOwner(char pos, Owner *owner);
void managerFunctions(char pos);
void manageManager(char pos, Manager *manager);
void cashierFunctions(char pos);
void manageCashier(char pos, Cashier *cashier);
void floorWorkerFunctions(char pos);
void manageFloorWorker(char pos, FloorWorker *floorWorker);
void retrieveStaffDetails();
void saveAndExit();
void initializeData();

std::vector<Staff> staffData;
std::vector<Transaction> transactionDetails;
std::vector<LocalSupply> localSupplyDataPending;
std::vector<LocalSupply> localSupplyDataApproved;
std::vector<InternationalSupply> internationalSupplyDataPending;
std::vector<InternationalSupply> internationalSupplyDataApproved;
std::unordered_map<std::string, std::string> userCredentialsMap;
std::unordered_map<std::string, std::string> staffPositionMap;
std::unordered_map<std::string, std::string> fullNameMap;

void supplyEntry(){
	system("cls");
	std::string str;
	
	do{
		std::cout << "Which supply entry you want to make ? (International / Local) : ";
		std::cin >> str;
	}while(str != "International" && str != "Local");
	
	if(str == "Local"){
		LocalSupply localSupply;
    	localSupply.getData();
	}
	else{
		InternationalSupply internationalSupply;
    	internationalSupply.getData();
	}
}

int displayMain(char pos){
	int i;
	bool restrictChk;
	do{
		restrictChk = false;
		std::cout << "1. STOCK\n\n";
		std::cout << "2. SUPPLY\n\n";
		std::cout << "3. STAFF\n\n";
		std::cout << "4. LOG OUT\n\n";
		std::cout << "5. EXIT\n\n\n\n";
		
		do{
	        std::cout << "Select section : ";
	        while (!(std::cin >> i)){
	            std::cin.clear(); // clear the fail bit
	            std::cin.ignore(100, '\n'); // ignore the invalid entry
	            std::cout << "\n Enter appropiate no : ";
	        }
	        if(i == 3 && (pos == 'C' || pos == 'F')){
	        	system("cls");
	        	std::cout << "YOU DON'T HAVE ACCESS TO THIS\n\n\n";
	        	restrictChk = true;
	        	system("pause");
			}
	    }while(i < 1 || 5 < i);
	    system("cls");
	}while(restrictChk);
	return i;
}

int displayAllFunctions(char pos, int funcIndex){
	int j, i = 0;
	system("cls");
	std::cout << "Select a function to perform\n\n";
	
	if(funcIndex == 0){
		switch(pos){
			case 'O':
			case 'M':
				std::cout << ++i << ") Add Items To Inventory\n";
	            std::cout << ++i << ") Remove Items From Inventory\n";
	        case 'C':
	        	std::cout << ++i << ") Add New Transaction\n";
	        case 'F':
	        	if(pos == 'F'){
	                std::cout << ++i << ") Stock Up Items\n";
	            }
	            std::cout << ++i << ") Go To Main Menu\n";
	            std::cout << ++i << ") Exit\n";
	            std::cout << "\n\n***FORCE EXITING / CLOSING PROGRAMME MAY CAUSE DATA CORRUPTION, ALWAYS EXIT FROM MENU OPTIONS***\n\n";
	            break;
		}
		do{
	        std::cout << "\n Enter appropiate no : ";
	        while (!(std::cin >> j)){
	            std::cin.clear(); // clear the fail bit
	            std::cin.ignore(100, '\n'); // ignore the invalid entry
	            std::cout << "\n Enter appropiate no : ";
	        }
	    }while(j < 1 || j > i);
	}
	else if(funcIndex == 1){
		switch(pos){
			case 'O':
			case 'M':
	            std::cout << ++i << ") View All Supply Entries\n";
	        case 'C':
	        case 'F':
				std::cout << ++i << ") Add New Supply Entry\n";
				std::cout << ++i << ") Go To Main Menu\n";
	            std::cout << ++i << ") Exit\n";
	            std::cout << "\n\n***FORCE EXITING / CLOSING PROGRAMME MAY CAUSE DATA CORRUPTION, ALWAYS EXIT FROM MENU OPTIONS***\n\n";
	            break;
		}
		do{
	        std::cout << "\n Enter appropiate no : ";
	        while (!(std::cin >> j)){
	            std::cin.clear(); // clear the fail bit
	            std::cin.ignore(100, '\n'); // ignore the invalid entry
	            std::cout << "\n Enter appropiate no : ";
	        }
	    }while(j < 1 || j > i);
	}
	else{
		switch(pos){
			case 'O':
				std::cout << ++i << ") Add New Staff Members\n";
            	std::cout << ++i << ") Remove Staff Members\n";
			case 'M':
	            std::cout << ++i << ") Check Details Of Staff Members\n";
	        case 'C':
	        case 'F':
				std::cout << ++i << ") Go To Main Menu\n";
	            std::cout << ++i << ") Exit\n";
	            std::cout << "\n\n***FORCE EXITING / CLOSING PROGRAMME MAY CAUSE DATA CORRUPTION, ALWAYS EXIT FROM MENU OPTIONS***\n\n";
	            break;
		}
		do{
	        std::cout << "\n Enter appropiate no : ";
	        while (!(std::cin >> j)){
	            std::cin.clear(); // clear the fail bit
	            std::cin.ignore(100, '\n'); // ignore the invalid entry
	            std::cout << "\n Enter appropiate no : ";
	        }
	    }while(j < 1 || j > i);		
	}
    system("cls");
    return j;
}

void ownerFunctions(char pos, std::string userN){
    Owner owner(fullNameMap[userN], userN);
    manageOwner(pos, &owner);
    logIn();
}

void manageOwner(char pos, Owner *owner){
    int i = 0, j = 0;
    
    do{
    	j = displayMain(pos);
    	switch(j){
    		case 1:
    			do{
	    			i = displayAllFunctions(pos, 0);
	    			switch(i){
		    				case 1:
		    					(*owner).addNewItemToStock();
		    					break;
		    				case 2:
		    					(*owner).stockDecrement();
		    					break;
		    				case 3:
		    					(*owner).makeTransaction((*owner).getFullName());
		    					break;
		    				case 5:
		    					saveAndExit();
		    					break;
	    				}
				}while(i != 4);
    			break;
    		case 2:
    			do{
	    			i = displayAllFunctions(pos, 1);
	    			switch(i){
		    				case 1:
		    					(*owner).viewSupplyEntry();
		    					break;
		    				case 2:
		    					supplyEntry();
		    					break;
		    				case 4:
		    					saveAndExit();
		    					break;
	    				}
				}while(i != 3);
    			break;
    		case 3:
    			do{
	    			i = displayAllFunctions(pos, 2);
	    			switch(i){
		    				case 1:
		    					(*owner).userInputFunc();
		    					break;
		    				case 2:
		    					(*owner).removeStaff();
		    					break;
		    				case 3:
		    					(*owner).readStaffDetails();
		    					break;
		    				case 5:
		    					saveAndExit();
		    					break;
	    				}
				}while(i != 4);
    			break;
			case 5:
				exit(0);
		}
	}while(j != 4);
    
    std::cout << "Have a nice day :)\n";
    getchar();
    getchar();
}

void managerFunctions(char pos, std::string userN){
    Manager manager(fullNameMap[userN], userN);
    manageManager(pos, &manager);
    logIn();
}

void manageManager(char pos, Manager *manager){
    int i = 0, j = 0;
    
    do{
    	j = displayMain(pos);
    	switch(j){
    		case 1:
    			do{
	    			i = displayAllFunctions(pos, 0);
	    			switch(i){
		    				case 1:
		    					(*manager).addNewItemToStock();
		    					break;
		    				case 2:
		    					(*manager).stockDecrement();
		    					break;
		    				case 3:
		    					(*manager).makeTransaction((*manager).getFullName());
		    					break;
		    				case 5:
		    					saveAndExit();
		    					break;
	    				}
				}while(i != 4);
    			break;
    		case 2:
    			do{
	    			i = displayAllFunctions(pos, 1);
	    			switch(i){
		    				case 1:
		    					(*manager).viewSupplyEntry();
		    					break;
		    				case 2:
		    					supplyEntry();
		    					break;
		    				case 4:
		    					saveAndExit();
		    					break;
	    				}
				}while(i != 3);
    			break;
    		case 3:
    			do{
	    			i = displayAllFunctions(pos, 2);
	    			switch(i){
		    				case 1:
		    					(*manager).readStaffDetails();
		    					break;
		    				case 3:
		    					saveAndExit();
		    					break;
	    				}
				}while(i != 2);
    			break;
			case 5:
				exit(0);
		}
	}while(j != 4);
    
    std::cout << "Have a nice day :)\n";
    getchar();
    getchar();
}

void cashierFunctions(char pos, std::string userN){
    Cashier cashier(fullNameMap[userN], userN);
    manageCashier(pos, &cashier);
    logIn();
}

void manageCashier(char pos, Cashier *cashier){
    int i = 0, j = 0;
    
    do{
    	j = displayMain(pos);
    	switch(j){
    		case 1:
    			do{
	    			i = displayAllFunctions(pos, 0);
	    			switch(i){
		    				case 1:
		    					(*cashier).makeTransaction((*cashier).getFullName());
		    					break;
		    				case 3:
		    					saveAndExit();
		    					break;
	    				}
				}while(i != 2);
    			break;
    		case 2:
    			do{
	    			i = displayAllFunctions(pos, 1);
	    			switch(i){
		    				case 1:
		    					supplyEntry();
		    					break;
		    				case 3:
		    					saveAndExit();
		    					break;
	    				}
				}while(i != 2);
    			break;
			case 5:
				exit(0);
		}
	}while(j != 4);
    
    std::cout << "Have a nice day :)\n";
    getchar();
    getchar();
}

void floorWorkerFunctions(char pos, std::string userN){
    FloorWorker floorWorker(fullNameMap[userN], userN);
    manageFloorWorker(pos, &floorWorker);
    logIn();
}

void manageFloorWorker(char pos, FloorWorker *floorWorker){
    int i = 0, j = 0;
    
    do{
    	j = displayMain(pos);
    	switch(j){
    		case 1:
    			do{
	    			i = displayAllFunctions(pos, 0);
	    			switch(i){
		    				case 1:
		    					(*floorWorker).stockIncrement();
		    					break;
		    				case 3:
		    					saveAndExit();
		    					break;
	    				}
				}while(i != 2);
    			break;
    		case 2:
    			do{
	    			i = displayAllFunctions(pos, 1);
	    			switch(i){
		    				case 1:
		    					supplyEntry();
		    					break;
		    				case 3:
		    					saveAndExit();
		    					break;
	    				}
				}while(i != 2);
    			break;
			case 5:
				exit(0);
		}
	}while(j != 4);
   
    std::cout << "Have a nice day :)\n";
    getchar();
    getchar();
}

void retrieveTransactionDetails(){
    std::string customerName, cashierName, itemName, dummy;
    int no;
    std::ifstream file("./test/transactionData.txt");
    int i = 0;
    if(file.is_open()){
        while(!file.eof()){
            if(i == 0){
                getline(file, cashierName);
            }
            else if(i == 1){
                getline(file, customerName);
            }
            else if(i == 2){
                getline(file, itemName);
            }
            else if(i == 3){
                file >> no;
				getline(file, dummy); 
            }
            else{
                Transaction transaction(cashierName, customerName, itemName, no);
                transactionDetails.emplace_back(transaction);
                i = -1;
            }
            i++;
           }
    }
}

void logIn(){
    std::string userN, passW;
	system("cls");
    std::cout << "\nWELCOME TO SUPERMARKET INVENTORY MANAGEMENT SYSTEM\n";
	std::cout << "\nLOGIN TO YOUR ACC TO CONTINUE\n\n";
    do{
        std::cout << "\nUsername :";
        std::cin >> userN;
        getchar();
        std::cout << "Password :";
        std::getline(std::cin, passW);
        if(userCredentialsMap[userN] != passW){
            std::cout << "Incorrect user credential\n";
        }
    }while(userCredentialsMap[userN] != passW);
    system("cls");
    std::cout << "\nWelcome back, " << userN << "\n\n";
    char pos = staffPositionMap[userN][0];

    switch(pos){
        case 'O':
            ownerFunctions(pos, userN);
            break;
        case 'M':
            managerFunctions(pos, userN);
            break;
        case 'C':
            cashierFunctions(pos, userN);
            break;
        case 'F':
            floorWorkerFunctions(pos, userN);
            break;
    }
}

int main(){
    retrieveStaffDetails();
    retrieveSupplyDetails();
    retrieveTransactionDetails();

    initializeData();
    
     logIn();
    return 0;
}
