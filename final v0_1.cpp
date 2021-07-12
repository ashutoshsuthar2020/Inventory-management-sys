#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

//DONT FORCE EXIT//PUT PRICCCCCCCCCCCCEEx

struct Date{
    int day;
    int month;
    int year;
};

struct Transaction{
    std::string cashierName;
    std::string customerName;
    std::vector<std::pair<std::string, int>> items;
    Transaction();
    Transaction(std::string cashierName, std::string customerName, std::string item, int no);
};

Transaction::Transaction(){}

Transaction::Transaction(std::string cashierName, std::string customerName, std::string item, int no): cashierName(cashierName), customerName(customerName) {
	items.emplace_back(std::make_pair(item, no));
}

class Staff;
class Owner;
class Manager;
class Cashier;
class FloorWorker;
class Supply;
class LocalSupply;
class InternationalSupply;

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
void saveStaffDetails();
void saveSupplyDetails();
void supplyEntry();
std::string enterFN();
Date enterDate();
std::string enterPos();
std::string enterUN();
std::string enterPW();
std::string enterN();
std::string enterAM();
Date enterAD();
std::string enterOrigin(std::string str);
Date enterDD(std::string str1, std::string str2 , Date date);
    

class Item{
    private:
        std::string item_name;
        float retail_price;
        float discount;
        float final_price;
    public:
        Item();
        Item(std::string a,float b,float c);
        std::string return_item_name();
        float return_retail_price();
        float return_discount();
        float return_final_price();
        ~Item();
};

Item::Item(){
	getchar();
    std::cout<<"Item Name          : ";
    std::getline(std::cin, item_name);

    do{
        std::cout<<"Retail Price       : ";
        while (!(std::cin >> retail_price)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Enter a suitable value : ";
        }
    }while (0 >= retail_price);

    do{
        std::cout<<"Discount           : ";
        while (!(std::cin >> discount)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Enter a suitable value : ";
        }
    }while ((discount<0)||(discount>100));

    final_price =retail_price*(100-discount)/100;
}

Item::Item(std::string a,float b,float c):item_name(a),retail_price(b),discount(c),final_price(b*(100-c)/100){}

std::string Item::return_item_name(){ 
    return item_name;
}

float Item::return_retail_price(){
    return retail_price;
}

float Item::return_discount(){
    return discount;
}

float Item::return_final_price(){
    return final_price;
}

Item::~Item(){}

class Brand{
    private:
        std::string brand_name;
        std::string brand_region;
    public:
        Brand();
        Brand(std::string a,std::string b);
        std::string return_brand_name();
        std::string return_brand_region();
        ~Brand();
};

Brand::Brand(){
	getchar();
    std::cout<<"Enter Brand name   : ";
    std::getline(std::cin, brand_name);
    do{
	    std::cout<<"Enter Brand region (Local / Imported) : ";
	    std::cin>>brand_region;
	}while(brand_region != "Local" && brand_region != "Imported");
}

Brand::Brand(std::string a,std::string b):brand_name(a),brand_region(b){}

std::string Brand::return_brand_name(){
    return brand_name;
}

std::string Brand::return_brand_region(){
    return brand_region;
}

Brand::~Brand(){}

class Produce:public Item{
    private:
        int number_of_item;
    public:
        Produce();
        Produce(std::string a,float b,float c,int d);
        int return_number_of_item();
        int*return_pointer_number_of_item();
        ~Produce();
};

Produce::Produce():Item(){
    do{
        std::cout<<"Number of Item     : ";
        while (!(std::cin >> number_of_item)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Enter a suitable value : ";
        }
    }while (0 > number_of_item);
}

Produce::Produce(std::string a,float b,float c,int d):Item(a,b,c),number_of_item(d){}

int Produce::return_number_of_item(){
    return number_of_item;
}

int* Produce::return_pointer_number_of_item(){
    return &number_of_item;
}

Produce::~Produce(){}

class Bakery_frozen_diary_snacks_beverages_health_condiments:public Produce,public Brand{
	public:
        Bakery_frozen_diary_snacks_beverages_health_condiments();
        Bakery_frozen_diary_snacks_beverages_health_condiments(std::string a,float b,float c,int d,std::string e,std::string f);
        ~Bakery_frozen_diary_snacks_beverages_health_condiments();
};

Bakery_frozen_diary_snacks_beverages_health_condiments::Bakery_frozen_diary_snacks_beverages_health_condiments():Produce(),Brand(){}

Bakery_frozen_diary_snacks_beverages_health_condiments::Bakery_frozen_diary_snacks_beverages_health_condiments(std::string a,float b,float c,int d,std::string e,std::string f):
        Produce(a,b,c,d),Brand(e,f){}

Bakery_frozen_diary_snacks_beverages_health_condiments::~Bakery_frozen_diary_snacks_beverages_health_condiments(){};

class Meat_seafood:public Item{
    private:
        double weight_of_item;
    public:
        Meat_seafood();
        Meat_seafood(std::string a,float b,float c,double d);
        double return_weight_of_item();
        double* return_pointer_weight_of_item();
        ~Meat_seafood();
};

Meat_seafood::Meat_seafood():Item(){
    do{
        std::cout<<"Enter weight of item : ";
        while (!(std::cin >> weight_of_item)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Enter a suitable value : ";
        }
    }while (0 > weight_of_item);
}

Meat_seafood::Meat_seafood(std::string a,float b,float c,double d):Item(a,b,c),weight_of_item(d){}

double Meat_seafood::return_weight_of_item(){
    return weight_of_item;
}

double* Meat_seafood::return_pointer_weight_of_item(){
    return &weight_of_item;
}

Meat_seafood::~Meat_seafood(){}

class Grain:public Meat_seafood,public Brand{
	public:
        Grain();
        Grain(std::string a,float b,float c,double d,std::string e,std::string f);
        ~Grain();
};

Grain::Grain():Meat_seafood(),Brand(){}

Grain::Grain(std::string a,float b,float c,double d,std::string e,std::string f):Meat_seafood(a,b,c,d),Brand(e,f){}

Grain::~Grain(){};

std::vector<Produce> data_produce;
std::vector<Meat_seafood>data_meat_seafood;
std::vector<Grain>data_grain;
std::vector<Bakery_frozen_diary_snacks_beverages_health_condiments>data_bakery_product,data_frozen_product,data_diary_product,data_snaks_and_sweets,
                data_bevarages,data_health_and_beauty,data_condiments_and_spices;
std::vector<Bakery_frozen_diary_snacks_beverages_health_condiments>* vector_pointer[]={&data_bakery_product,&data_frozen_product,&data_diary_product,
                &data_snaks_and_sweets,&data_bevarages,&data_health_and_beauty,&data_condiments_and_spices};

std::string file_name[]={"file_bakery_product.txt","file_frozen_product.txt","file_diary_product.txt","file_snaks_and_sweets.txt","file_bevarages.txt",
                "file_health_and_beauty.txt","file_condiments_and_spices.txt"};

bool change_Category[10]={0,0,0,0,0,0,0,0,0,0};
float retail_price,discount,weight_of_item;
std::string item_name,brand_name,brand_region;
int number_of_item;
std::fstream file;

int select_category(){
    char Category;
    std::cout<<"\n CATEGORY OF ITEMS\n -----------------\n";
    std::cout<<" A.Produce\n B.Meat seafood\n C.Grain\n D.Bakery product\n E.Frozen product\n F.Diary product\n G.Snacks and sweets\n "
             <<"H.Beverages\n I.Health and beauty\n J.Condiments and spices\n\n";
    do{
        std::cout<<"Select Category of item : ";
        std::cin>>Category;
    }while( !((int(Category)>64)&&(int(Category)<75)) && !((int(Category)>96)&&(int(Category)<107)));

    if(int(Category)<75)
    return int(Category)-64;
    else
    return int(Category)-96;
}

int add_or_remove_stock(int x, Transaction *transaction = NULL){
    int Category =select_category();
    int i_no,add_or_get, price,i=0;
    std::cout<<"List of Items";
    change_Category[Category-1]=true;

    if(Category==1){
        for(;i<data_produce.size();i++)
            std::cout<<"\n"<<i+1<<"."<<data_produce[i].return_item_name();
    }else if(Category==2){
        for(;i<data_meat_seafood.size();i++)
            std::cout<<"\n"<<i+1<<"."<<data_meat_seafood[i].return_item_name();
    }else if(Category==3){
        for(;i<data_grain.size();i++)
            std::cout<<"\n"<<i+1<<"."<<data_grain[i].return_item_name();
    }else{
        for(;i<(*vector_pointer[Category-4]).size();i++)
            std::cout<<"\n"<<i+1<<"."<<(*vector_pointer[Category-4])[i].return_item_name();
    }
    std::cout << "\n";
    
    if(x == 1){
    	std::cout << "\n*If item is not in stock use add item function to add that item. Only managers and owners have access to that function contact them to add new item*\n";
    	std::cout << "Press 0 to go back\n";
    	do{
	        std::cout << "\nSelect Item (No. within range) : ";
	        while (!(std::cin >> i_no)){
	            std::cin.clear(); // clear the fail bit
	            std::cin.ignore(100, '\n'); // ignore the invalid entry
	            std::cout << "Enter a suitbale item number : ";
	        }
	        if(i_no == 0){
	        	return 0;
			}
    	}while (0 > i_no || i < i_no);
	}
    
    else{
    	std::cout << "\n**Press 0 to go back\n";
	    do{
	        std::cout << "\nSelect Item (No. within range) : ";
	        while (!(std::cin >> i_no)){
	            std::cin.clear(); // clear the fail bit
	            std::cin.ignore(100, '\n'); // ignore the invalid entry
	            std::cout << "Enter a suitbale item number : ";
	        }
	        if(i_no == 0){
	        	return 0;
			}
	    }while (0 > i_no || i < i_no);
	}
    bool underFlow;
	do{
		underFlow = false;
	    do{
	    	if(x==1) std::cout<<"Enter the numbers of item to increase : ";
	    	else     std::cout<<"Enter the numbers of item to remove   : ";
		    while (!(std::cin >> add_or_get)){
		        std::cin.clear(); // clear the fail bit
		        std::cin.ignore(100, '\n'); // ignore the invalid entry
		        std::cout << "Enter a suitbale item number : ";
		    }
		}while(add_or_get < 0);
	
	    if(Category==1){
	        if(x==1)
	        *(data_produce[i_no-1].return_pointer_number_of_item()) +=add_or_get;
	        else if(*(data_produce[i_no-1].return_pointer_number_of_item())>=add_or_get){
	            *(data_produce[i_no-1].return_pointer_number_of_item()) -=add_or_get;
	            if(transaction){
	            	(*transaction).items.emplace_back(std::make_pair(data_produce[i_no-1].return_item_name(), add_or_get));
	            	price = data_produce[i_no-1].return_final_price();
				}
	        }
	        else{
	        	if(*(data_produce[i_no-1].return_pointer_number_of_item())==0)
	            std::cout<<"No items in the stock\n";
	            else{
	            std::cout<<"Not enough items in the Stock\n";
	            underFlow = true;
				}
			}	
	    }else if(Category==2){
	        if(x==1)
	        *(data_meat_seafood[i_no-1].return_pointer_weight_of_item()) +=add_or_get;
	        else if(*(data_meat_seafood[i_no-1].return_pointer_weight_of_item())>=add_or_get){
	            *(data_meat_seafood[i_no-1].return_pointer_weight_of_item()) -=add_or_get;
	            if(transaction){
	            	(*transaction).items.emplace_back(std::make_pair(data_meat_seafood[i_no-1].return_item_name(), add_or_get));
	            	price = data_meat_seafood[i_no-1].return_final_price();
				}
	        }
	        else{
	            if(*(data_meat_seafood[i_no-1].return_pointer_weight_of_item())==0)
	            std::cout<<"No items in the stock\n";
	            else{
	            std::cout<<"Not enough items in the Stock\n";
	            underFlow = true;
	            }
	        }
	    }else if(Category==3){
	        if(x==1)
	        *(data_grain[i_no-1].return_pointer_weight_of_item()) +=add_or_get;
	        else if(*(data_grain[i_no-1].return_pointer_weight_of_item())>=add_or_get){
	            *(data_grain[i_no-1].return_pointer_weight_of_item()) -=add_or_get;
	            if(transaction){
	            	(*transaction).items.emplace_back(std::make_pair(data_grain[i_no-1].return_item_name(), add_or_get));
	            	price = data_grain[i_no-1].return_final_price();
				}
	        }
	        else{
	            if(*(data_grain[i_no-1].return_pointer_weight_of_item())==0)
	            std::cout<<"No items in the stock\n";
	            else{
	            std::cout<<"Not enough items in the Stock\n";
	            underFlow = true;
	            }
	        }
	    }else{
	        if(x==1)
	        *((*vector_pointer[Category-4])[i_no-1].return_pointer_number_of_item()) +=add_or_get;
	        else if(*((*vector_pointer[Category-4])[i_no-1].return_pointer_number_of_item())>=add_or_get){
	            *((*vector_pointer[Category-4])[i_no-1].return_pointer_number_of_item()) -=add_or_get;
	            if(transaction){
	            	(*transaction).items.emplace_back(std::make_pair((*vector_pointer[Category-4])[i_no-1].return_item_name(), add_or_get));
	            	price = (*vector_pointer[Category-4])[i_no-1].return_final_price();
				}
	        }	
	        else{
	            if(*((*vector_pointer[Category-4])[i_no-1].return_pointer_number_of_item())==0)
	            std::cout<<"No items in the stock\n";
	            else{
	            std::cout<<"Not enough items in the Stock\n";
	            underFlow = true;
	            }
	        }
	    }
	    if(x==1){
	    	std::cout << "\nItem(s) added to inventory";
		}
	    getchar();
	    getchar();
	}while(underFlow);
	return (add_or_get * price);
}

void add_new_item(int Category){
    std::cout<<"Enter item Details\n";
    change_Category[Category-1]=true;
    char order;
    do{
        if(Category==1)      data_produce.push_back(Produce());
        else if(Category==2) data_meat_seafood.push_back(Meat_seafood());
        else if(Category==3) data_grain.push_back(Grain());
        else                 (*vector_pointer[Category-4]).push_back(Bakery_frozen_diary_snacks_beverages_health_condiments());

        do{
        std::cout<<"ENTER N/n to add a new item\nENTER E/e TO EXIT\n";
        std::cin>>order;
        if((order!='N')&&(order!='n')&&(order!='E')&&(order!='e'))
            std::cout<<"Enter a correct option.\n";
        else
            break;
        }while(true);
        system("cls");
    }while((order!='E')&&(order!='e'));
}

void save_and_exit(){
    for(int i=0;i<10;i++){
    if(change_Category[i]==1){
        if(i==0){
            file.open("file_produce.txt");
            for(int k=0;k<data_produce.size();k++)
            file<<data_produce[k].return_item_name()<<"\n"<<data_produce[k].return_retail_price()<<" "<<data_produce[k].return_discount()
			<<" "<<data_produce[k].return_number_of_item()<<"\n";}
        else if(i==1){
            file.open("file_meat_seafood.txt");
            for(int k=0;k<data_meat_seafood.size();k++)
            file<<data_meat_seafood[k].return_item_name()<<"\n"<<data_meat_seafood[k].return_retail_price()<<" "<<data_meat_seafood[k].return_discount()
			<<" "<<data_meat_seafood[k].return_weight_of_item()<<"\n";}
        else if(i==2){
            file.open("file_grain.txt");
            for(int k=0;k<data_grain.size();k++)
            file<<data_grain[k].return_item_name()<<"\n"<<data_grain[k].return_retail_price()<<" "<<data_grain[k].return_discount()<<" "
			<<data_grain[k].return_weight_of_item()<<"\n"<<data_grain[k].return_brand_name()<<"\n"<<data_grain[k].return_brand_region()<<"\n";}
        else{
            file.open(file_name[i-3]);
            for(int k=0;k<(*vector_pointer[i-3]).size();k++)
            file<<(*vector_pointer[i-3])[k].return_item_name()<<"\n"<<(*vector_pointer[i-3])[k].return_retail_price()<<" "<<
			(*vector_pointer[i-3])[k].return_discount()<<" "<<(*vector_pointer[i-3])[k].return_number_of_item()<<"\n"<<(*vector_pointer[i-3])[k].return_brand_name()<<
			"\n"<<(*vector_pointer[i-3])[k].return_brand_region()<<"\n";}
        file.close();
    }
    }
    saveSupplyDetails();
    exit(0);
}
 
void initialize_data(){
	std::string dummy;
    file.open("file_produce.txt");
    int i;
    if(!file){
        std::cout<<"File_produce.txt not found\n";
        std::ofstream newfile("file_produce.txt");
        add_new_item(1);
        newfile.close();
    }
    else{
    	i = 0;
        while(!file.eof()){
        	if(i == 0){
        		getline(file, item_name);
			}
			else if(i == 1){
				file>>retail_price>>discount>>number_of_item;
				getline(file, dummy);
			}
			else{
				data_produce.push_back(Produce (item_name,retail_price,discount,number_of_item));
				i = -1;
			}
			i++;
        }
    }
    file.close();
    
    file.open("file_meat_seafood.txt");
    if(!file){
        std::cout<<"File_meat_seafood.txt not found\n";
        std::ofstream newfile("file_meat_seafood.txt");
        add_new_item(2);
        newfile.close();
    }
    else{
    	i = 0;
        while(!file.eof()){
        	if(i == 0){
        		getline(file, item_name);
			}
			else if(i == 1){
				file>>retail_price>>discount>>number_of_item;
				getline(file, dummy);
			}
			else{
				data_meat_seafood.push_back(Meat_seafood (item_name,retail_price,discount,number_of_item));
				i = -1;
			}
			i++;
        }
    }
    file.close();
 
    file.open("file_grain.txt");
    if(!file){
        std::cout<<"File_grain.txt not found\n";
        std::ofstream newfile("file_grain.txt");
        add_new_item(3);
        newfile.close();
    }
    else{
    	i = 0;
        while(!file.eof()){
        	if(i == 0){
        		getline(file, item_name);
			}
			else if(i == 1){
				file>>retail_price>>discount>>weight_of_item;
				getline(file, brand_name);
			}
			else if(i == 2){
				getline(file, brand_name);
			}
			else if(i == 3){
				file>>brand_region;
				getline(file, dummy);
			}
			else{
				data_grain.push_back(Grain (item_name,retail_price,discount,weight_of_item,brand_name,brand_region));
				i = -1;
			}
			i++;
        }
    }
    file.close();

    for(int j=0;j<7;j++){
        file.open(file_name[j]);
        if(!file){
            std::cout<<file_name[j]<<" not found\n";
            std::ofstream newfile(file_name[j]);
            add_new_item(j+4);
            newfile.close();
        }
        else{
        	i = 0;
        	while(!file.eof()){
        	if(i == 0){
        		getline(file, item_name);
			}
			else if(i == 1){
				file>>retail_price>>discount>>number_of_item;
				getline(file, brand_name);
			}
			else if(i == 2){
				getline(file, brand_name);
			}
			else if(i == 3){
				file>>brand_region;
				getline(file, dummy);
			}
			else{
				(*vector_pointer[j]).push_back(Bakery_frozen_diary_snacks_beverages_health_condiments (item_name,retail_price,discount,number_of_item,brand_name,brand_region));
				i = -1;
			}
			i++;
        }
        }
        file.close();
    }
}

std::vector<Staff> staffData;
std::vector<Transaction> transactionDetails;
std::vector<LocalSupply> localSupplyDataPending;
std::vector<LocalSupply> localSupplyDataApproved;
std::vector<InternationalSupply> internationalSupplyDataPending;
std::vector<InternationalSupply> internationalSupplyDataApproved;
std::unordered_map<std::string, std::string> userCredentialsMap;
std::unordered_map<std::string, std::string> staffPositionMap;
std::unordered_map<std::string, std::string> fullNameMap;


class Supply {
    private:
        std::string quantity;
        Date dateOfArrival;
        std::string itemName ;
        std::string status;
    public:
        Supply() {}
        Supply( std::string name, std::string amount, Date d, std::string s):itemName(name), quantity(amount), dateOfArrival(d),status(s) {}
        std::string getQuantity() {return quantity;}
        Date getDateOfArrival() {return dateOfArrival;}
        std::string getItemName() {return itemName;}
        std::string getStatus() {return status;}
        void setStatus(std::string s){ status = s;}
        ~Supply(){}
};


class LocalSupply: public Supply{
    private:
        std::string nameOfOrigin;
        Date dateOfDeparture;
        std::string vehicle;
        std::string vehicleRegNo;
    public:
        LocalSupply();
        LocalSupply(std::string name , std::string amount, Date d , std::string s, std::string origin, Date departureDate, std::string v, std::string regNo);
        void getData();
        std::string getNameOfOrigin() {return nameOfOrigin;}
        Date getDateOfDeparture() {return dateOfDeparture;}
        std::string getVehicle() {return vehicle;}
        std::string getVehicleRegNo() {return vehicleRegNo;}
        ~LocalSupply();
};

LocalSupply::LocalSupply() {}

LocalSupply::LocalSupply(std::string name , std::string amount, Date d , std::string s, std::string origin, Date departureDate, std::string v, std::string regNo): 
                Supply(name, amount, d,s ),nameOfOrigin(origin), dateOfDeparture(departureDate), vehicle(v), vehicleRegNo(regNo){}
	
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

class InternationalSupply: public Supply{
    private:
        std::string countryOfOrigin;
        Date arrivalDateAtHarbour;
        int shipNo;
    public:
        InternationalSupply();
        InternationalSupply(std::string name, std::string amount, Date d, std::string s, std::string country, Date arrivalDate, int no);
        void getData();
        std::string getcountryOfOrigin() {return countryOfOrigin;}
        Date getArrivalDateAtHarbour() {return arrivalDateAtHarbour;}
        int getShipNo() {return shipNo;}
        ~InternationalSupply();
};

InternationalSupply::InternationalSupply() {}

InternationalSupply::InternationalSupply(std::string name, std::string amount, Date d, std::string s, std::string country, Date arrivalDate, int no): 
                    Supply(name, amount, d,s ),countryOfOrigin(country), arrivalDateAtHarbour(arrivalDate), shipNo(no){}

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

std::string enterN(){
	std::string name;
	getchar();
    system("cls");
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

class Staff{
    private:
        static bool isRootCreated;                         //owner will be root
        std::string userName;
        std::string password;
        std::string fullName;
        std::string position;
        Date date;
    public:
        Staff();
        Staff(std::string fullName, std::string position, Date date, std::string userName, std::string password);
        Staff(std::string fullName, std::string position, std::string userName);
        static bool getIsRootCreated();
        static void setIsRootCreated();
        std::string getUserName();
        void setUserName();
        std::string getPassword();
        void setPassword();
        std::string getFullName();
        void setFullName();
        std::string getPosition();
        void setPosition();
        Date getDate();   
		void setDate();     
        ~Staff() {};
};

bool Staff::isRootCreated = false;

Staff::Staff() {}
Staff::Staff(std::string fullName, std::string position, Date date, std::string userName, std::string password): 
                            userName(userName), password(password), fullName(fullName), position(position), date(date) {}

Staff::Staff(std::string fullName, std::string position, std::string userName): userName(userName), fullName(fullName), date(date) {}

bool Staff::getIsRootCreated(){
	return isRootCreated;
}

void Staff::setIsRootCreated(){
	isRootCreated = true;
}

std::string Staff::getFullName(){
    return fullName;
}

void Staff::setFullName(){
	fullName = enterFN();
}

std::string Staff::getUserName(){
	return userName;
}

void Staff::setUserName(){
	userName = enterUN();
}

std::string Staff::getPassword(){
	return password;
}

void Staff::setPassword(){
	password = enterPW();
}

std::string Staff::getPosition(){
	return position;
}

void Staff::setPosition(){
	position = enterPos();
}

Date Staff::getDate(){
	return date;
}

void Staff::setDate(){
	date = enterDate();
}

class FloorWorker: public virtual Staff{
    public:
        FloorWorker();
        FloorWorker(std::string fullName, std::string userName);
        void stockIncrement(bool isFloorWorker = true);
        ~FloorWorker();
};

FloorWorker::FloorWorker() {}

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
		chk = add_or_remove_stock(1); //add num items
	}
	else{
		add_new_item(select_category());         //add new item
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

FloorWorker::~FloorWorker() {}

class Cashier: public virtual Staff{
    public:
        Cashier();
        Cashier(std::string fullName, std::string userName);
        void makeTransaction(std::string userName);
        void stockDecrement();
        ~Cashier();
};

Cashier::Cashier() {}

Cashier::Cashier(std::string fullName, std::string userName): Staff(fullName, "Cashier", userName){}

void Cashier::stockDecrement(){
	add_or_remove_stock(0); //remove num items
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
			cash += add_or_remove_stock(0, &transaction); //remove num items
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

Cashier::~Cashier() {}

class Manager: public FloorWorker, public Cashier{
    public:
        Manager();
        Manager(std::string fullName, std::string userName);
        void readStaffDetails();
        void addNewItemToStock();
        void viewSupplyEntry();
        ~Manager();
};

Manager::Manager() {}

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

Manager::~Manager() {}

class Owner: public Manager{
     public:
        Owner(std::string fullName, std::string userName);
        void addStaff(std::string userName, std::string password, std::string fullName, std::string position, Date date);
        void removeStaff();
        void userInputFunc();
        ~Owner();
};

Owner::Owner(std::string fullName, std::string userName): Staff(fullName, "Owner", userName) {}

void Owner::addStaff(std::string userName, std::string password, std::string fullName, std::string position, Date date){
    if(position == "Owner"){
        setIsRootCreated();
    }

    Staff newStaff(fullName, position, date, userName, password);
    staffData.emplace_back(newStaff);

    userCredentialsMap[userName] = password;
    staffPositionMap[userName] = position;

    std::cout << "\nAn account was created for " << position << ", " << fullName << ".\n\nPress enter to go back\n"; 
    getchar();
    system("cls");
    saveStaffDetails();
}	

void Owner::removeStaff(){
    std::string username;
    bool userChk;
    do{
        userChk = false;
        std::cout << "Enter username of staff that you want to delete :";
        std::cin >> username;
    }while(userCredentialsMap.find(username) == userCredentialsMap.end());
    if(getUserName() == username){
        std::cout << "\nYou are trying to remove root(Owner) account. Which will cause deletion of all company data & quit the programme.\n";
        std::cout << "In case of owner has changed, you can change the owner information\n\n\n";
        char s;
        do{
            std::cout << "If you want to delete owner account press \"Y\"\n";
            std::cout << "\nTo close this window press \"N\"\n";
            std::cin >> s;
        }while(s != 'Y' && s != 'N' && s != 'T');
		system("cls");
        switch(s){
            case 'Y':
                staffData.clear();
                userCredentialsMap.clear();
                staffPositionMap.clear();
                saveStaffDetails();
                exit(0);
                break;
            case 'N':
                break;
        }
        return;
    }
    if(staffPositionMap.erase(username)){
        for(int i = 0; i < staffData.size(); i++){
            if(staffData[i].getUserName() == username){
                staffData.erase(staffData.begin() + i);
            }
        }
        userCredentialsMap.erase(username);
        saveStaffDetails();
    }
    else{
        std::cout << "\nUser not found !!\n";
        system("pause");
    }
}

void Owner::userInputFunc(){
    Date date;

    std::string fullName;
    std::string userName;
    std::string position;
    std::string password;
    
    getchar();
    system("cls");
	std::cout << "\nADDING NEW STAFF DETAILS\n";
    fullName = enterFN();
    date = enterDate();
    position = enterPos();

    std::cout << "\n\n..This one is for login process of user..\n\n";

    userName = enterUN();
    password = enterPW();

    addStaff(userName, password, fullName, position, date);
}

Owner::~Owner() {}

std::string enterFN(){
	std::string fullName;
    std::cout << "\nEnter fullname : ";
    std::getline(std::cin, fullName);
    return fullName;
}

Date enterDate(){
	Date date;
    do{
        std::cout << "Enter joined date (put space between date, month & year like, dd mm yyyy format) : ";
        std::cin >> date.day >> date.month >> date.year;
    }while(date.day <= 0 || date.day > 31 || date.month <= 0 || date.month > 12 || date.year <= 1940 || date.year > 2200);
    return date;
}

std::string enterPos(){
	std::string position;
    if(Staff::getIsRootCreated()){
        do{
            std::cout << "Positions in this business are,\n";
            std::cout << "\tManager\n\tCashier\n\tFloorWorker\n";
            std::cout << "Enter position (Use same naming convention) :";
            std::cin >> position;
        }while(position != "Manager" && position != "Cashier" && position != "FloorWorker");
        return position;
    }
    return ("Owner");
}

std::string enterUN(){
    bool userChk;
    std::string userName;
    do{
        userChk = false;
        std::cout << "\nEnter username(NO SPACES) : ";
        std::cin >> userName;

        if(!(userCredentialsMap.find(userName) == userCredentialsMap.end())){
            userChk = true;
            std::cout << "username not available";
        }
    }while(userChk);
    return userName;
}

std::string enterPW(){
    bool userChk;
    std::string password, password2;
    getchar();
    do{
        userChk = false;
        std::cout << "Password, \n* More than 6 characters \n* Must have an Uppercase letter \n* Must be alphanumeric \n" ;//make star when typing
        std::cout << "Enter password  : ";
        std::getline(std::cin, password);

        bool capNotChk = true;
        bool alphaNumNotChk = true;

        if(password.length() < 6){
            userChk = true;
        }
        else{
            for(int i = 0; i < password.length(); i++){
                if(password.at(i) >= 'A' && password.at(i) <= 'Z'){
                    capNotChk = false;
                }
                if(password.at(i) >= '0' && password.at(i) <= '9'){
                    alphaNumNotChk = false;
                }
                if(password.at(i) == ' '){
                    alphaNumNotChk = false;
                }
            }
            if(alphaNumNotChk || capNotChk){
                userChk = true;
            }
        }
    }while(userChk);

       do{
        std::cout << "Re-enter password : ";
        std::getline(std::cin, password2);

        if(password2 != password){
            std::cout << "passwords dont match. ..";
        }
    }while(password2 != password);
    return password;
}

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
		    					save_and_exit();
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
		    					save_and_exit();
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
		    					save_and_exit();
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
		    					save_and_exit();
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
		    					save_and_exit();
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
		    					save_and_exit();
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
		    					save_and_exit();
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
		    					save_and_exit();
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
		    					save_and_exit();
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
		    					save_and_exit();
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

void retrieveStaffDetails(){
    std::string fullName, position, userName, password;
    Date date;
    std::ifstream file("staffData.txt");
    int i = 0;
    if(file.is_open()){
        while(!file.eof()){
            if(i == 0){
                getline(file, fullName);
            }
            else if(i == 1){
                file >> position >> date.day >> date.month >> date.year >> userName;
                getline(file, password);
            }
            else if(i == 2){
                getline(file, password);
            }
            else{
                Staff newStaff(fullName, position, date, userName, password);
                staffData.emplace_back(newStaff);
                userCredentialsMap[userName] = password;
                staffPositionMap[userName] = position;
                fullNameMap[userName] = fullName;
                i = -1;
                Staff::setIsRootCreated();
            }
            i++;
           }
    }
    if(!Staff::getIsRootCreated()){
        Owner owner("dummy", "dummy");
        std::cout << "Looks like there is no root(Owner) in this system. Press Enter to create\n";
        owner.userInputFunc();
    }
}

void retrieveSupplyDetails(){
    std::string name, amount, s, origin, v, regNo;
    int shipNo;
    Date d, departureDate;
    std::ifstream file("localSupplyDataPending.txt");
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
        std::ifstream file("internationalSupplyDataPending.txt");
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

void retrieveTransactionDetails(){
    std::string customerName, cashierName, itemName, dummy;
    int no;
    std::ifstream file("transactionData.txt");
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

void saveStaffDetails(){
    std::ofstream file;
    file.open("staffData.txt");
    for(int i = 0; i < staffData.size(); i++){
        file << staffData[i].getFullName() << "\n" << staffData[i].getPosition() << " " << staffData[i].getDate().day << " "
             << staffData[i].getDate().month << " " << staffData[i].getDate().year << " " << staffData[i].getUserName() << "\n" << staffData[i].getPassword() << '\n';
    }
    file.close();
}

void saveSupplyDetails(){
	std::string lName[2] = {"localSupplyDataPending.txt", "localSupplyDataApproved.txt"};
	std::string iName[2] = {"internationalSupplyDataPending.txt", "internationalSupplyDataApproved.txt"};
	
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

    initialize_data();
    
     logIn();
    return 0;
}
