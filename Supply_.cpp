#include<iostream>
#include<string>

using namespace std;

enum Status{pending, approved};

struct Date{
	int Day, Month, Year;
};

class Supply {
private:
	string Quantity="";
	Date DateOfArrival;
	string ItemName ="";
	Status status;	
public:
	Supply():ItemName(""),Quantity(""), DateOfArrival(), status(pending) {}
	Supply(string name="" , string amount="" , Date d = {}, Status s= pending ):ItemName(name), Quantity(amount), DateOfArrival(d), status(s) {}
	virtual void SetData(string name, string amount, Date date) = 0;
	virtual~Supply(){}
};

void Supply::SetData(string name, string amount,Date date){
	ItemName = name;
	Quantity = amount;
	DateOfArrival = date;
}


class LocalSupply: public Supply{
private:
	string NameOfOrigin;
	Date DateOfDeparture;
	string Vehicle;
	string VehicleRegNo;
public:
	LocalSupply(string name="" , string amount="" , Date d = {}, Status s= pending, string origin="", Date departureDate = {}, string v ="", string regNo="" ): Supply(name, amount, d,s ),NameOfOrigin(origin), DateOfDeparture(departureDate), Vehicle(v), VehicleRegNo(regNo){}
	void SetData(string name, string amount, Date date, string origin, Date departureDate, string Vehicle, string VehicleRegNo);
	~LocalSupply(){}
};

	void LocalSupply::SetData(string name, string amount, Date date, string origin, Date departureDate, string v, string regNo){
	Supply:: SetData("name", "amount", date);
	NameOfOrigin = origin;
	DateOfDeparture = departureDate;
	Vehicle= v;
	VehicleRegNo = regNo;
}

class InternationalSupply: public Supply{
private:
	string CountryOfOrigin;
	Date ArrivalDateAtHarbour;
	int ShipNo;
public:
	InternationalSupply(string name="" , string amount="" , Date d = {}, Status s= pending, string country="", Date arrivalDate = {}, int no =0): Supply(name, amount, d,s ),CountryOfOrigin(country), ArrivalDateAtHarbour(arrivalDate), ShipNo(no){}
	void SetData(string name, string amount, Date date, string country, Date arrivalDate, int no);
	~InternationalSupply(){}
}; 

	void InternationalSupply::SetData(string name, string amount, Date date, string country, Date arrivalDate, int no){
	Supply:: SetData("name", "amount", date);
	CountryOfOrigin = country;
	ArrivalDateAtHarbour = arrivalDate;
	ShipNo= no;
}


int main() {
	
//LocalSupply L1();

return 0;
}
