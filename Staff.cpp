#include <iostream>
#include <string>

struct Date{
    int day;
    int month;
    int year;
};

class Owner;

class Staff{
    private:
        std::string userName;
        std::string password;
        std::string fullName;
        std::string position;
        Date date;                      //DEBUG
        Staff(std::string userName, std::string password, std::string fullName, std::string position, Date date): userName("null"), password("null"), fullName("null"), position("null"), date(date) {}
        friend class Owner; 
};

class Owner{
    public:
        void addStaff(Staff** staff, std::string userName, std::string password, std::string fullName, std::string position, Date date){
            Staff* newStaff = new Staff(userName, password, fullName, position, date);
            *staff = newStaff;
        }
        void removeStaff(Staff *staff){
            Staff *temp = staff;
            delete temp;
        }
};

class FloorWorker: public Owner{
    public:
        void stockIncrement(){
            //stock++;
        }
};

class Cashier: public Owner{
    public:
        //TRANSACTIONS
        void stockDecrement(){
            //stock--;
        }
};

class Manager: public FloorWorker, public Cashier{
    public:
        void checkStaffDetails(){

        }
};







