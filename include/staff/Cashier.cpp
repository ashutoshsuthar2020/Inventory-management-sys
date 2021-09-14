#include "Cashier.h"

extern int addOrRemoveStock(int x, Transaction *transaction = NULL);
extern std::vector<Transaction> transactionDetails;

Cashier::Cashier(){}

Cashier::Cashier(std::string fullName, std::string userName): Staff(fullName, "Cashier", userName){}

void Cashier::stockDecrement(){
	addOrRemoveStock(0); //remove num items
}

void Cashier::makeTransaction(std::string fullName){
	Transaction transaction;
	float cash;
	char c;
	int n = 0;
	do{
		do{	
			system("cls");
			n++;
			cash += addOrRemoveStock(0, &transaction); //remove num items
			std::cout << "\nMake another transaction to this person (Y/N) : ";
			std::cin >> c;
		}while(c != 'N' && c != 'Y');
	}while(c == 'Y');
    getchar();
    std::string customerName;
    if(cash != 0){
	    std::cout << "\nEnter customer name : ";
	    std::getline(std::cin, customerName);
	    std::cout << "Total price : " << cash;
		getchar();
	    
	    transaction.cashierName = fullName;
	    transaction.customerName = customerName;
	    transactionDetails.emplace_back(transaction);
	    
	    std::ofstream file;
	    file.open("transactionData.txt");
	    for(int i = 0; i < transactionDetails.size(); i++){
	    	for(int j = 0; j < n; j++){
	    		file << transactionDetails[i].cashierName << "\n" << transactionDetails[i].customerName << "\n" << transactionDetails[i].items[j].first << "\n"
	        	<< transactionDetails[i].items[j].second << "\n";
			}
	    }
	    file.close();
	}
}

Cashier::~Cashier(){}
