#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

struct Date{
    int day;
    int month;
    int year;
};

struct Transaction{
    std::string cashierName;
    std::string customerName;
    std::vector<std::pair<std::string, int>> items;
    Transaction(std::string cashierName, std::string customerName, std::vector<std::pair<std::string, int>> items);
};

Transaction::Transaction(std::string cashierName, std::string customerName, std::vector<std::pair<std::string, int>> items) : 
                            cashierName(cashierName), customerName(customerName), items(items) {}

class Owner;
class Manager;
class Cashier;
class FloorWorker;
class Supply;
class LocalSupply;
class InternationalSupply;

void logIn();
int displayAllFunctions(char pos);
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
    std::cout<<"Item Name          : ";
    std::cin>>item_name;

    do{
        std::cout<<"Retail Price       : ";
        while (!(std::cin >> retail_price)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Enter A Suitable value : ";
        }
    }while (0 >= retail_price);

    do{
        std::cout<<"Discount           : ";
        while (!(std::cin >> discount)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Enter A Suitable value : ";
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
    std::cout<<"Enter Brand name   : ";
    std::cin>>brand_name;
    std::cout<<"Enter Brand region : ";
    std::cin>>brand_region;
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Enter A Suitable value : ";
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

class Bakery_frozen_diary_snaks_bevarages_health_condiments:public Produce,public Brand{
	public:
        Bakery_frozen_diary_snaks_bevarages_health_condiments();
        Bakery_frozen_diary_snaks_bevarages_health_condiments(std::string a,float b,float c,int d,std::string e,std::string f);
        ~Bakery_frozen_diary_snaks_bevarages_health_condiments();
};

Bakery_frozen_diary_snaks_bevarages_health_condiments::Bakery_frozen_diary_snaks_bevarages_health_condiments():Produce(),Brand(){}

Bakery_frozen_diary_snaks_bevarages_health_condiments::Bakery_frozen_diary_snaks_bevarages_health_condiments(std::string a,float b,float c,int d,std::string e,std::string f):
        Produce(a,b,c,d),Brand(e,f){}

Bakery_frozen_diary_snaks_bevarages_health_condiments::~Bakery_frozen_diary_snaks_bevarages_health_condiments(){};

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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Enter A Suitable value : ";
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
std::vector<Bakery_frozen_diary_snaks_bevarages_health_condiments>data_bakery_product,data_frozen_product,data_diary_product,data_snaks_and_sweets,
                data_bevarages,data_health_and_beauty,data_condiments_and_spices;
std::vector<Bakery_frozen_diary_snaks_bevarages_health_condiments>* vector_pointer[]={&data_bakery_product,&data_frozen_product,&data_diary_product,
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

void add_or_remove_stock(int x){
    int Category =select_category();
    int i_no,add_or_get,i=0;
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
    do{
        std::cout << "\nSelect Item (No. within range) : ";
        while (!(std::cin >> i_no)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout << "Enter a suitbale item number : ";
        }
    }while (0 > i_no || i < i_no);

    while(true){
    if(x==1) std::cout<<"Enter the numbers of item to increase : ";
    else     std::cout<<"Enter the numbers of item to remove   : ";
    while (!(std::cin >> add_or_get)){
        std::cin.clear(); // clear the fail bit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
        std::cout << "Enter a suitbale item number : ";
    }

    if(add_or_get<0)
        std::cout<<"Enter a suitable value.\n";
    else
        break;
    }

    if(Category==1){
        if(x==1)
        *(data_produce[i_no-1].return_pointer_number_of_item()) +=add_or_get;
        else if(*(data_produce[i_no-1].return_pointer_number_of_item())>=add_or_get)
            *(data_produce[i_no-1].return_pointer_number_of_item()) -=add_or_get;
        else
            std::cout<<"Not enough items in the Stock";
    }else if(Category==2){
        if(x==1)
        *(data_meat_seafood[i_no-1].return_pointer_weight_of_item()) +=add_or_get;
        else if(*(data_meat_seafood[i_no-1].return_pointer_weight_of_item())>=add_or_get)
            *(data_meat_seafood[i_no-1].return_pointer_weight_of_item()) -=add_or_get;
        else
            std::cout<<"Not enough items in the Stock";
    }else if(Category==3){
        if(x==1)
        *(data_grain[i_no-1].return_pointer_weight_of_item()) +=add_or_get;
        else if(*(data_grain[i_no-1].return_pointer_weight_of_item())>=add_or_get)
            *(data_grain[i_no-1].return_pointer_weight_of_item()) -=add_or_get;
        else
            std::cout<<"Not enough items in the Stock";
    }else{
        if(x==1)
        *((*vector_pointer[Category-4])[i_no-1].return_pointer_number_of_item()) +=add_or_get;
        else if(*((*vector_pointer[Category-4])[i_no-1].return_pointer_number_of_item())>=add_or_get)
            *((*vector_pointer[Category-4])[i_no-1].return_pointer_number_of_item()) -=add_or_get;
        else
            std::cout<<"Not enough items in the Stock";
    }
}

void add_new_item(){
    int Category =select_category();
    std::cout<<"Enter item Details\n";
    change_Category[Category-1]=true;

    if(Category==1)      data_produce.push_back(Produce());
    else if(Category==2) data_meat_seafood.push_back(Meat_seafood());
    else if(Category==3) data_grain.push_back(Grain());
    else                 (*vector_pointer[Category-4]).push_back(Bakery_frozen_diary_snaks_bevarages_health_condiments());
}

void save_and_exit(){
    for(int i=0;i<10;i++){
    if(change_Category[i]==1){
        if(i==0){
            file.open("file_produce.txt");
            for(int k=0;k<data_produce.size();k++)
            file<<data_produce[k].return_item_name()<<" "<<data_produce[k].return_retail_price()<<" "<<data_produce[k].return_discount()<<" "<<data_produce[k].return_number_of_item()<<"\n";}
        else if(i==1){
            file.open("file_meat_seafood.txt");
            for(int k=0;k<data_meat_seafood.size();k++)
            file<<data_meat_seafood[k].return_item_name()<<" "<<data_meat_seafood[k].return_retail_price()<<" "<<data_meat_seafood[k].return_discount()<<" "<<data_meat_seafood[k].return_weight_of_item()<<"\n";}
        else if(i==2){
            file.open("file_grain.txt");
            for(int k=0;k<data_grain.size();k++)
            file<<data_grain[k].return_item_name()<<" "<<data_grain[k].return_retail_price()<<" "<<data_grain[k].return_discount()<<" "<<data_grain[k].return_weight_of_item()<<" "<<data_grain[k].return_brand_name()<<" "<<data_grain[k].return_brand_region()<<"\n";}
        else{
            file.open(file_name[i-3]);
            for(int k=0;k<(*vector_pointer[i-3]).size();k++)
            file<<(*vector_pointer[i-3])[k].return_item_name()<<" "<<(*vector_pointer[i-3])[k].return_retail_price()<<" "<<(*vector_pointer[i-3])[k].return_discount()<<" "<<(*vector_pointer[i-3])[k].return_number_of_item()<<" "<<(*vector_pointer[i-3])[k].return_brand_name()<<" "<<(*vector_pointer[i-3])[k].return_brand_region()<<"\n";}
        file.close();
    }
    }
}

void initialize_data(){
    file.open("file_produce.txt");
    if(!file){
        std::cout<<"File not found";
        return;
    }
    else while(!file.eof()){
        file>>item_name>>retail_price>>discount>>number_of_item;
        data_produce.push_back(Produce (item_name,retail_price,discount,number_of_item));
    }
    data_produce.pop_back();
    file.close();

    file.open("file_meat_seafood.txt");
    if(!file){
        std::cout<<"File not found";
        return;
    }
    else while(!file.eof()){
        file>>item_name>>retail_price>>discount>>weight_of_item;
        data_meat_seafood.push_back(Meat_seafood (item_name,retail_price,discount,weight_of_item));
    }
    data_meat_seafood.pop_back();
    file.close();
 
    file.open("file_grain.txt");
    if(!file){
        std::cout<<"File not found";
        return;
    }
    else while(!file.eof()){
        file>>item_name>>retail_price>>discount>>weight_of_item>>brand_name>>brand_region;
        data_grain.push_back(Grain (item_name,retail_price,discount,weight_of_item,brand_name,brand_region));
    }
    data_grain.pop_back();
    file.close();

    for(int i=0;i<7;i++){
        file.open(file_name[i]);
        if(!file){
            std::cout<<"File not found";
            return;
        }
        else while(!file.eof()){
            file>>item_name>>retail_price>>discount>>number_of_item>>brand_name>>brand_region;
            (*vector_pointer[i]).push_back(Bakery_frozen_diary_snaks_bevarages_health_condiments (item_name,retail_price,discount,number_of_item,brand_name,brand_region));
        }
        (*vector_pointer[i]).pop_back();
        file.close();
    }
}

class Staff{
    private:
        bool static isRootCreated;                         //owner will be root
        static int noOfStaffs;
        std::string userName;
        std::string password;
        std::string fullName;
        std::string position;
        Date date;
    public:
        Staff();
        Staff(std::string fullName, std::string position, Date date, std::string userName, std::string password);
        Staff(std::string fullName, std::string position, std::string userName);
        std::string getFullName();
        friend class Owner;
        friend class Manager;
        friend void retrieveStaffDetails();
        friend void saveStaffDetails();
        ~Staff() {};
};

Staff::Staff() {}
Staff::Staff(std::string fullName, std::string position, Date date, std::string userName, std::string password): 
                            userName(userName), password(password), fullName(fullName), position(position), date(date) {}

Staff::Staff(std::string fullName, std::string position, std::string userName): userName(userName), fullName(fullName), date(date) {}

std::string Staff::getFullName(){
    return fullName;
}

std::vector<Staff> staffData;
std::vector<Transaction> transactionDetails;
std::vector<LocalSupply> localSupplyData;
std::vector<InternationalSupply> internationalSupplyData;
std::unordered_map<std::string, std::string> userCredentialsMap;
std::unordered_map<std::string, std::string> staffPositionMap;
std::unordered_map<std::string, std::string> fullNameMap;

int Staff::noOfStaffs = 0;
bool Staff::isRootCreated = false;

class FloorWorker: public virtual Staff{
    public:
        FloorWorker();
        FloorWorker(std::string fullName, std::string userName);
        void stockIncrement();
        ~FloorWorker();
};

FloorWorker::FloorWorker() {}

FloorWorker::FloorWorker(std::string fullName, std::string userName): Staff(fullName, "FloorWorker", userName){}

void FloorWorker::stockIncrement(){
            // if not already here you cantt stock up ..call manager or Onwer
            //stock++;
}

FloorWorker::~FloorWorker() {}

class Cashier: public virtual Staff{
    public:
        Cashier();
        Cashier(std::string fullName, std::string userName);
        void makeTransaction(std::string userName);
        void stockDecrement(std::vector<std::pair<std::string, int>> items = {{"", 0}});
        ~Cashier();
};

Cashier::Cashier() {}

Cashier::Cashier(std::string fullName, std::string userName): Staff(fullName, "Cashier", userName){}

void Cashier::stockDecrement(std::vector<std::pair<std::string, int>> items){
            //stock--;
}

void Cashier::makeTransaction(std::string fullName){
    getchar();
    std::string customerName;
    std::cout << "\nEnter customer name : ";
    std::getline(std::cin, customerName);
    //fullName

    // Transaction transaction(cashierName, customerName, items);
    // transactionDetails.emplace_back(transaction);

}

Cashier::~Cashier() {}

class Manager: public FloorWorker, public Cashier{
    public:
        Manager();
        Manager(std::string fullName, std::string userName);
        void readStaffDetails();
        ~Manager();
};

Manager::Manager() {}

Manager::Manager(std::string fullName, std::string userName): Staff(fullName, "Manager", userName){}

void Manager::readStaffDetails(){
    getchar();
    std::cout << "\n\n Viewing Staff Data \n\n";
    for(int i = 0; i < staffData.size(); i++){
        std::cout << staffData[i].fullName << " " << staffData[i].position << " " << staffData[i].date.day << " "
            << staffData[i].date.month << " " << staffData[i].date.year << "\n";
    }
    std::cout << "\n\n End of Staff Data \n\nPress enter to go back";
    getchar();
}

Manager::~Manager() {}

class Owner: public Manager{
     public:
        Owner(std::string fullName, std::string userName);
        void addStaff(std::string userName, std::string password, std::string fullName, std::string position, Date date);
        void changeOwnerInfo(Staff *staff);
        void removeStaff();
        void userInputFunc();
        void enterFName(std::string *fullName);
        void enterDate(Date *date);
        void enterPos(std::string *position);
        void enterUN(std::string *userName);
        void enterPass(std::string *password);
        ~Owner();
};

Owner::Owner(std::string fullName, std::string userName): Staff(fullName, "Owner", userName) {}

void Owner::addStaff(std::string userName, std::string password, std::string fullName, std::string position, Date date){
    if(position == "Owner"){
        isRootCreated = true;
    }

    Staff newStaff(fullName, position, date, userName, password);
    noOfStaffs++;
    staffData.emplace_back(newStaff);

    userCredentialsMap[userName] = password;
    staffPositionMap[userName] = position;

    std::cout << "\nAn account was created for " << position << ", " << fullName << ".\n\nPress enter to go back\n"; 
    getchar();
    saveStaffDetails();
}

void Owner::changeOwnerInfo(Staff *staff){
    std::string ans;
    char ch;
    do{
        getchar();
        do{
            std::cout << "\nWhat info do you want to change from, " << (*staff).userName << "'s details ? (FULL NAME, POSITION, JOINED DATE, USERNAME, PASSWORD)\n";
            std::getline(std::cin, ans);
        }while(ans != "FULL NAME" && ans != "POSITION" && ans != "JOINED DATE" && ans != "USERNAME" && ans != "PASSWORD");
        bool userChk = false;
        switch(ans.at(3)){
            case 'L':
                std::cout << "\nCurrent full name : " <<  (*staff).fullName;
                enterFName(&(*staff).fullName);
                break;
            case 'I':
                if((*staff).position == "Owner"){
                    std::cout << "\nYou can't change position of Owner\n";
                    break;
                }
                std::cout << "\nCurrent position : " <<  (*staff).position;
                enterPos(&(*staff).position);
                break;
            case 'N':
                std::cout << "\nCurrent joined date : " <<  (*staff).date.day << "/" << (*staff).date.month << "/" << (*staff).date.year <<"\n" ;
                enterDate(&(*staff).date);
                break;
            case 'R':
                std::cout << "\nCurrent user name : " <<  (*staff).fullName;
                enterFName(&(*staff).userName);
                break;
            case 'S':
                std::string str;
                do{
                    std::cout << "\nEnter root(Owner) password to change " << (*staff).userName << "'s password :";
                    std::cin >> str;
                }while(userCredentialsMap[userName] != str);
                enterPass(&(*staff).password);
                break;
        }

        do{
            std::cout << "\nDo you want to change another information of " << (*staff).userName << " ? (Y/N) :";
            std::cin >> ch;
        }while(ch != 'N' && ch != 'Y');
        saveStaffDetails();
    }while(ch == 'Y');
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
    if(username == userName){
        std::cout << "\nYou are trying to remove root(Owner) account. Which will cause deletion of all company data & quit the programme.\n";
        std::cout << "In case of owner has changed, you can change the owner information\n\n\n";
        char s;
        do{
            std::cout << "If you want to delete owner account press \"Y\"\n";
            std::cout << "If you want to change owner account info press \"T\"\n";
            std::cout << "\nTo close this window press \"N\"\n";
            std::cin >> s;
        }while(s != 'Y' && s != 'N' && s != 'T');

        switch(s){
            case 'Y':
                staffData.clear();
                userCredentialsMap.clear();
                staffPositionMap.clear();
                saveStaffDetails();
                exit(0);
                break;
            case 'T':
                changeOwnerInfo(&staffData[0]);
                break;
            case 'N':
                std::cout << "\nCLOSE WINDOW\n";///////I PUT RETURN SO CHK
                break;
        }
        return;
    }
    if(staffPositionMap.erase(username)){
        for(int i = 0; i < noOfStaffs; i++){
            if(staffData[i].userName == username){
                staffData.erase(staffData.begin() + i);
            }
        }
        userCredentialsMap.erase(username);
        noOfStaffs--;
        saveStaffDetails();
    }
    else{
        std::cout << "\nUser not found !!\n";
    }
}

void Owner::userInputFunc(){
    Date date;

    std::string fullName;
    std::string userName;
    std::string position = "Owner";
    std::string password;

    enterFName(&fullName);
    enterDate(&date);
    enterPos(&position);

    std::cout << "\n\n..This one is for login process of user..\n\n";

    enterUN(&userName);
    enterPass(&password);

    addStaff(userName, password, fullName, position, date);
}

void Owner::enterFName(std::string *fullName){
    getchar();
    std::cout << "\nEnter fullname : ";
    std::getline(std::cin, *fullName);
}

void Owner::enterDate(Date *date){
    do{
        std::cout << "Enter joined date (put space between date, month & year like, dd mm yyyy format) : ";
        std::cin >> (*date).day >> (*date).month >> (*date).year;
    }while((*date).day <= 0 || (*date).day > 31 || (*date).month <= 0 || (*date).month > 12 || (*date).year <= 1940 || (*date).year > 2200);
}

void Owner::enterPos(std::string *position){
    if(Staff::isRootCreated){
        do{
            std::cout << "Positions in this business are,\n";
            std::cout << "\tManager\n\tCashier\n\tFloorWorker\n";
            std::cout << "Enter position (Use same naming convention) :";
            std::cin >> *position;
        }while(*position != "Manager" && *position != "Cashier" && *position != "FloorWorker");
    }
}

void Owner::enterUN(std::string *userName){
    bool userChk;
    do{
        userChk = false;
        std::cout << "Enter username(NO SPACES) : ";
        std::cin >> *userName;

        if(!(userCredentialsMap.find(*userName) == userCredentialsMap.end())){
            userChk = true;
            std::cout << "username not available";
        }
    }while(userChk);
}

void Owner::enterPass(std::string *password){
    bool userChk;
    std::string password2;
    getchar();
    do{
        userChk = false;
        std::cout << "Password, \n* More than 6 characters \n* Must have an Uppercase letter \n* Must be alphanumeric \n" ;//make star when typing
        std::cout << "Enter password  : ";
        std::getline(std::cin, *password);

        bool capNotChk = true;
        bool alphaNumNotChk = true;

        if((*password).length() < 6){
            userChk = true;
        }
        else{
            for(int i = 0; i < (*password).length(); i++){
                if((*password).at(i) >= 'A' && (*password).at(i) <= 'Z'){
                    capNotChk = false;
                }
                if((*password).at(i) >= '0' && (*password).at(i) <= '9'){
                    alphaNumNotChk = false;
                }
                if((*password).at(i) == ' '){
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

        if(password2 != *password){
            std::cout << "passwords dont match. ..";
        }
    }while(password2 != *password);
}

Owner::~Owner() {}



class Supply {
    private:
        std::string quantity;
        Date dateOfArrival;
        std::string itemName ;
        std::string status;
    public:
        Supply() {}
        Supply( std::string name, std::string amount, Date d, std::string s):itemName(name), quantity(amount), dateOfArrival(d),status(s) {}
        void SetData(std::string name, std::string amount, Date date);
        std::string getQuantity() {return quantity;}
        Date getDateOfArrival() {return dateOfArrival;}
        std::string getItemName() {return itemName;}
        std::string getStatus() {return status;}
        ~Supply(){}
};

void Supply::SetData(std::string name, std::string amount,Date date){
	itemName = name;
	quantity = amount;
	dateOfArrival = date;
}


class LocalSupply: public Supply{
    private:
        std::string nameOfOrigin;
        Date dateOfDeparture;
        std::string vehicle;
        std::string vehicleRegNo;
    public:
        LocalSupply();
        LocalSupply(std::string name , std::string amount, Date d , std::string s, std::string origin, Date departureDate, std::string v, std::string regNo);
        void GetData();
        ~LocalSupply();
};

LocalSupply::LocalSupply() {}

LocalSupply::LocalSupply(std::string name , std::string amount, Date d , std::string s, std::string origin, Date departureDate, std::string v, std::string regNo): 
                Supply(name, amount, d,s ),nameOfOrigin(origin), dateOfDeparture(departureDate), vehicle(v), vehicleRegNo(regNo){}
	
void LocalSupply::GetData(){
	std::string name, amount, origin, v, regNo;
	Date date, departureDate;
    getchar();
	std::cout<<"--- Enter the details of the item ---\n";
	std::cout<<"Name :  ";
	std::getline(std::cin, name);
    // do{
    //     std::cout<<"Amount :  ";
    //     while (!(std::cin >> amount)){
    //         std::cin.clear(); // clear the fail bit
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
    //         std::cout << "Please Enter a valid value:  ";
    //     }
    // }while(amount < 0);
    do{
        std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        while (!(std::cin >> date.day)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        }
        while (!(std::cin >> date.month)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        }
        while (!(std::cin >> date.year)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        }
    }while(date.day<1||date.day>30||date.month<1||date.month>12||date.year<1940||date.year>2200);
    
    getchar();
	std::cout<<"Name of origin(Farm/Factory) :  ";
	std::getline(std::cin, origin);
    do{
        std::cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
        while (!(std::cin >> departureDate.day)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
        }
        while (!(std::cin >> departureDate.month)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
        }
        while (!(std::cin >> departureDate.year)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
        }
    }while(departureDate.day<1||departureDate.day>30||departureDate.month<1||departureDate.month>12||departureDate.year<1940||departureDate.year>2200);
    while((departureDate.year * 365 + departureDate.month * 30 + departureDate.day) > (date.year * 365 + date.month * 30 + date.day)){
        std::cout << "\nDATE OF DEPARTURE FROM FARM/FACTORY CANT BE LATER THAN DATE OF ARRIVAL AT SUPERMARKET\n";
            do{
                std::cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
                while (!(std::cin >> departureDate.day)){
                    std::cin.clear(); // clear the fail bit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
                    std::cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
                }
                while (!(std::cin >> departureDate.month)){
                    std::cin.clear(); // clear the fail bit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
                    std::cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
                }
                while (!(std::cin >> departureDate.year)){
                    std::cin.clear(); // clear the fail bit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
                    std::cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
                }
            }while(departureDate.day<1||departureDate.day>30||departureDate.month<1||departureDate.month>12||departureDate.year<1940||departureDate.year>2200);
    }
    getchar();
    do{
        std::cout<<"Vehicle used for the transportation(Large truck/Small truck/Van) :  ";			
        std::getline(std::cin, v);
    }while(v != "Large truck" && v != "Small truck" && v != "Van");
	std::cout<<"Vehicle registration number :  ";
	std::cin>>regNo;
    LocalSupply localSupply(name, amount, date, "Pending", origin, departureDate, v, regNo);
    localSupplyData.emplace_back(localSupply);

    std::ofstream file;
    file.open("localSupplyData.txt");
    for(int i = 0; i < localSupplyData.size(); i++){
        file << localSupplyData[i].getItemName() << "\n" <<localSupplyData[i].getQuantity() << " " << localSupplyData[i].getDateOfArrival().day << " " 
        << localSupplyData[i].getDateOfArrival().month  << " " << localSupplyData[i].getDateOfArrival().year << " " <<  localSupplyData[i].getStatus() << "\n" 
        << localSupplyData[i].nameOfOrigin << "\n" << localSupplyData[i].dateOfDeparture.day << " " << localSupplyData[i].dateOfDeparture.month << " " 
        << localSupplyData[i].dateOfDeparture.year << "\n" << localSupplyData[i].vehicle << "\n" << localSupplyData[i].vehicleRegNo << "\n";
    }
    file.close();
}

LocalSupply::~LocalSupply(){}

class InternationalSupply: public Supply{
    private:
        std::string countyOfOrigin;
        Date arrivalDateAtHarbour;
        int shipNo;
    public:
        InternationalSupply();
        InternationalSupply(std::string name, std::string amount, Date d, std::string s, std::string country, Date arrivalDate, int no);
        void GetData();
        ~InternationalSupply();
};

InternationalSupply::InternationalSupply() {}

InternationalSupply::InternationalSupply(std::string name, std::string amount, Date d, std::string s, std::string country, Date arrivalDate, int no): 
                    Supply(name, amount, d,s ),countyOfOrigin(country), arrivalDateAtHarbour(arrivalDate), shipNo(no){}

void InternationalSupply::GetData(){
	std::string name, amount, country;
	Date date, arrivalDate;
	int no;
    getchar();
	std::cout<<"--- Enter the details of the item ---\n";
	std::cout<<"Name :  ";
	std::getline(std::cin, name);
	std::cout<<"Amount :  ";
	std::cin>>amount;
	do{
        std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        while (!(std::cin >> date.day)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        }
        while (!(std::cin >> date.month)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        }
        while (!(std::cin >> date.year)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
        }
    }while(date.day<1||date.day>30||date.month<1||date.month>12||date.year<1940||date.year>2200);
    
    getchar();
	std::cout<<"Country of origin :  ";
	std::getline(std::cin, country);
	do{
        std::cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
        while (!(std::cin >> arrivalDate.day)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
        }
        while (!(std::cin >> arrivalDate.month)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
        }
        while (!(std::cin >> arrivalDate.year)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
            std::cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
        }
    }while(arrivalDate.day<1||arrivalDate.day>30||arrivalDate.month<1||arrivalDate.month>12||arrivalDate.year<1940||arrivalDate.year>2200);
    while((arrivalDate.year * 365 + arrivalDate.month * 30 + arrivalDate.day) > (date.year * 365 + date.month * 30 + date.day)){
        std::cout << "\nDATE OF ARRIVAL AT HARBOUR CANT BE LATER THAN DATE OF ARRIVAL AT SUPERMARKET\n";
            do{
                std::cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
                while (!(std::cin >> arrivalDate.day)){
                    std::cin.clear(); // clear the fail bit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
                    std::cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
                }
                while (!(std::cin >> arrivalDate.month)){
                    std::cin.clear(); // clear the fail bit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
                    std::cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
                }
                while (!(std::cin >> arrivalDate.year)){
                    std::cin.clear(); // clear the fail bit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
                    std::cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
                }
            }while(arrivalDate.day<1||arrivalDate.day>30||arrivalDate.month<1||arrivalDate.month>12||arrivalDate.year<1940||arrivalDate.year>2200);
    }
    std::cout<<"Ship number :  ";	
    while (!(std::cin >> no)){
        std::cin.clear(); // clear the fail bit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid entry
        std::cout << "Please Enter a valid value:  ";
    }
	InternationalSupply internationalSupply(name, amount, date, "Pending", country, arrivalDate, no);
    internationalSupplyData.emplace_back(internationalSupply);

    std::ofstream file;
    file.open("internationalSupplyData.txt");
    for(int i = 0; i < internationalSupplyData.size(); i++){
        file << internationalSupplyData[i].getItemName() << "\n" <<internationalSupplyData[i].getQuantity() << " " << internationalSupplyData[i].getDateOfArrival().day << " " 
        << internationalSupplyData[i].getDateOfArrival().month  << " " << internationalSupplyData[i].getDateOfArrival().year << " " <<  internationalSupplyData[i].getStatus() << "\n" 
        << internationalSupplyData[i].countyOfOrigin << "\n" << internationalSupplyData[i].arrivalDateAtHarbour.day << " " << internationalSupplyData[i].arrivalDateAtHarbour.month << " " 
        << internationalSupplyData[i].arrivalDateAtHarbour.year << "\n" << internationalSupplyData[i].shipNo << "\n";
    }
    file.close();
}

InternationalSupply::~InternationalSupply(){}

int displayAllFunctions(char pos){
    int j,i = 0;
    std::cout << "Select a function to perform\n\n";
    switch(pos){
        case 'O':
            std::cout << ++i << ") Add New Staff Members\n";
            std::cout << ++i << ") Remove Staff Members\n";
        case 'M':
            std::cout << ++i << ") Add Items To Inventory\n";
            std::cout << ++i << ") Remove Items From Inventory\n";
            std::cout << ++i << ") Check Details Of Staff Members\n";
        case 'C':
            std::cout << ++i << ") Add New Transaction\n";
        case 'F':
            if(pos == 'F'){
                std::cout << ++i << ") Stock Up Items\n";
            }
            std::cout << ++i << ") Sign Out\n";
            std::cout << ++i << ") Exit\n";
            break;
    }
    do{
        std::cout << "\n Enter appropiate no : ";
        std::cin >> j;
    }while(j <= 0 && j > i);
    return j;
}

void ownerFunctions(char pos, std::string userN){
    Owner owner(fullNameMap[userN], userN);
    manageOwner(pos, &owner);
    logIn();
}

void manageOwner(char pos, Owner *owner){
    int i = 0;
    do{
        i = displayAllFunctions(pos);
        switch(i){
            case 1:
                (*owner).userInputFunc();
                break;
            case 2:
                (*owner).removeStaff();
                break;
            case 3:
                (*owner).stockIncrement();
                break;
            case 4:
                (*owner).stockDecrement();
                break;
            case 5:
                (*owner).readStaffDetails();
                break;
            case 6:
                (*owner).makeTransaction((*owner).getFullName());
                break;
            case 8:
                exit(0);
        }
    }while(i != 7);
}

void managerFunctions(char pos, std::string userN){
    Manager manager(fullNameMap[userN], userN);
    manageManager(pos, &manager);
    logIn();
}

void manageManager(char pos, Manager *manager){
    int i = 0;
    do{
        i = displayAllFunctions(pos);
        switch(i){
            case 1:
                (*manager).stockIncrement();
                break;
            case 2:
                (*manager).stockDecrement();
                break;
            case 3:
                (*manager).readStaffDetails();
                break;
            case 4:
                (*manager).makeTransaction((*manager).getFullName());
                break;
            case 6:
                exit(0);
        }
    }while(i != 5);
}

void cashierFunctions(char pos, std::string userN){
    Cashier cashier(fullNameMap[userN], userN);
    manageCashier(pos, &cashier);
    logIn();

}

void manageCashier(char pos, Cashier *cashier){
    int i = 0;
    do{
        i = displayAllFunctions(pos);
        switch(i){
            case 1:
                (*cashier).makeTransaction((*cashier).getFullName());
                break;
            case 3:
                exit(0);
        }
    }while(i != 2);
}

void floorWorkerFunctions(char pos, std::string userN){
    FloorWorker floorWorker(fullNameMap[userN], userN);
    manageFloorWorker(pos, &floorWorker);
    logIn();
}

void manageFloorWorker(char pos, FloorWorker *floorWorker){
    int i = 0;
    do{
        i = displayAllFunctions(pos);
        switch(i){
            case 1:
                (*floorWorker).stockIncrement();
                break;
            case 3:
                exit(0);
        }
    }while(i != 2);
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
                Staff::noOfStaffs++;
                i = -1;
            }
            i++;
           }
        if(Staff::noOfStaffs > 0){
            Staff::isRootCreated = true;
        }
    }
    if(!Staff::isRootCreated){
        Owner owner("dummy", "dummy");
        std::cout << "Looks like there is no root(Owner) in this system. Press Enter to create\n";
        owner.userInputFunc();
    }
}

void retrieveSupplyDetails(){
    std::string name, amount, s, origin, v, regNo;
    int shipNo;
    Date d, departureDate;
    std::ifstream file("localSupplyData.txt");
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
                    localSupplyData.emplace_back(localSupply);
                    i = -1;
                }
                i++;
            }
        }
    }

    {
        std::ifstream file("internationalSupplyData.txt");
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
                    getline(file, v);
                }
                else if(i == 4){
                    file >> shipNo;
                }
                else{
                    InternationalSupply internationalSupply(name, amount, d, s, origin, departureDate, shipNo);
                    internationalSupplyData.emplace_back(internationalSupply);
                    i = -1;
                }
                i++;
            }
        }
    }
}

void saveStaffDetails(){
    std::ofstream file;
    file.open("staffData.txt");
    for(int i = 0; i < staffData.size(); i++){
        file << staffData[i].fullName << "\n" << staffData[i].position << " " << staffData[i].date.day << " "
             << staffData[i].date.month << " " << staffData[i].date.year << " " << staffData[i].userName << "\n" << staffData[i].password << '\n';
    }
    file.close();
}

void logIn(){
    std::string userN, passW;

    std::cout << "\nWELCOME TO SUPERMARKET INVENTORY MANAGEMENT SYSTEM\n\n";

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
    //system cls
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
    // retrieveStaffDetails();
    // retrieveSupplyDetails();
    // initialize_data();
    
    // add_or_remove_stock(1); //add num items
    // add_or_remove_stock(0); //remove num items
    // add_new_item();         //add new item
    // logIn();
    //////STOCK UP VS NEW STOCK UP
    // LocalSupply localSupply;
    // localSupply.GetData();
    InternationalSupply internationalSupply;
    internationalSupply.GetData();
    save_and_exit();
    return 0;
}

