#include<iostream>
#include<string>
using namespace std;

struct Date{
	int Day, Month, Year;
};

class Supply {
private:
	string Quantity;
	Date DateOfArrival;
	string ItemName ;
	string Status;

public:
	Supply( string name =""  , string amount="" , Date d={0,0,0}, string s="Pending" ):ItemName(name), Quantity(amount), DateOfArrival(d),Status(s) {}
	~Supply(){}
	void SetData(string name, string amount, Date date);
};
	void Supply:: SetData(string name, string amount,Date date){
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
	LocalSupply(string name="" , string amount="" , Date d={0,0,0} , string s="Pending", string origin="", Date departureDate={0,0,0} , string v="" , string regNo="" ): Supply(name, amount, d,s ),NameOfOrigin(origin), DateOfDeparture(departureDate), Vehicle(v), VehicleRegNo(regNo){}
	~LocalSupply(){	}
	void SetData(string name, string amount, Date date, string origin, Date departureDate, string v, string regNo);
	void GetData();
};

	void LocalSupply::SetData(string name, string amount, Date date, string origin, Date departureDate, string v, string regNo){
	Supply:: SetData(name, amount, date);
	NameOfOrigin = origin;
	DateOfDeparture = departureDate;
	Vehicle= v;
	VehicleRegNo = regNo;
	//details should be saved in text file here.
	}
	
	void LocalSupply::GetData(){
		string name, amount, origin, v, regNo;
		Date date, departureDate;
		cout<<"--- Enter the details of the item ---"<<endl;
		cout<<"Name :  ";
		cin>>name;
		cout<<"Amount :  ";
		cin>>amount;
		cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";							//date error checking needed if enter char...
		cin>>date.Day>>date.Month>>date.Year;
			while(date.Day<1||date.Day>30||date.Month<1||date.Month>12){
			cout<<"Error! Please enter a valid date"<<endl;
			cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
			cin>>date.Day>>date.Month>>date.Year; 
			}
		cout<<"Name of origin(Farm/Factory) :  ";
		cin>>origin;
		cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
		cin>>departureDate.Day>>departureDate.Month>>departureDate.Year;
			while(departureDate.Day<1||departureDate.Day>30||departureDate.Month<1||departureDate.Month>12){
			cout<<"Error! Please enter a valid date"<<endl;
			cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
			cin>>departureDate.Day>>departureDate.Month>>departureDate.Year;
			}
			while(1){
			if(departureDate.Year>date.Year){
			cout<<"Error! Departure date should be before the Arrival date"<<endl;
			cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
			cin>>departureDate.Day>>departureDate.Month>>departureDate.Year;
			}
			if(departureDate.Month>date.Month&&departureDate.Year<=date.Year){
			cout<<"Error! Departure date should be before the Arrival date"<<endl;
			cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
			cin>>departureDate.Day>>departureDate.Month>>departureDate.Year;
			}
			if(departureDate.Day>date.Day&&departureDate.Month<=date.Month&&departureDate.Year<=date.Year){
			cout<<"Error! Departure date should be before the Arrival date"<<endl;
			cout<<"Date of departure from the Farm/Factory(dd mm yy) :  ";
			cin>>departureDate.Day>>departureDate.Month>>departureDate.Year;
			}
			if(departureDate.Day<=date.Day&&departureDate.Month<=date.Month&&departureDate.Year<=date.Year){
			break;
			}
			}
		cout<<"Vehicle used for the transportation(Large trucks/Small trucks/Vans) :  ";			
		cin>>v;
		cout<<"Vehicle registration number :  ";
		cin>>regNo;
		cout<<endl;
		LocalSupply::SetData(name,amount,date,origin,departureDate,v,regNo);	
	}



class InternationalSupply: public Supply{
private:
	string CountryOfOrigin;
	Date ArrivalDateAtHarbour;
	int ShipNo;
public:
	InternationalSupply(string name="" , string amount="" , Date d={0,0,0} , string s="Pending", string country="", Date arrivalDate={0,0,0} , int no=0): Supply(name, amount, d,s ),CountryOfOrigin(country), ArrivalDateAtHarbour(arrivalDate), ShipNo(no){}
	~InternationalSupply(){}
	void SetData(string name, string amount, Date date, string country, Date arrivalDate, int no);
	void GetData();
}; 

	void InternationalSupply::SetData(string name, string amount, Date date, string country, Date arrivalDate, int no){
	Supply:: SetData(name, amount, date);
	CountryOfOrigin = country;
	ArrivalDateAtHarbour = arrivalDate;
	ShipNo= no;
	//details should be saved in text file here.
	}

	void InternationalSupply::GetData(){
		string name, amount, country;
		Date date, arrivalDate;
		int no;
		cout<<"--- Enter the details of the item ---"<<endl;
		cout<<"Name :  ";
		cin>>name;
		cout<<"Amount :  ";
		cin>>amount;
		cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
		cin>>date.Day>>date.Month>>date.Year; 									//Assuming that all the 12 months are made up of 30 days
			while(date.Day<1||date.Day>30||date.Month<1||date.Month>12){
			cout<<"Error! Please enter a valid date"<<endl;
			cout<<"Date of arrival at the Supermarket(dd mm yy) :  ";
			cin>>date.Day>>date.Month>>date.Year; 
			}
		cout<<"Country of origin :  ";
		cin>>country;
		cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
		cin>>arrivalDate.Day>>arrivalDate.Month>>arrivalDate.Year;
			while(arrivalDate.Day<1||arrivalDate.Day>30||arrivalDate.Month<1||arrivalDate.Month>12){
			cout<<"Error! Please enter a valid date"<<endl;
			cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
			cin>>arrivalDate.Day>>arrivalDate.Month>>arrivalDate.Year;
			}
			while(1){
			if(arrivalDate.Year>date.Year){
			cout<<"Error! Arrival date at the local harbour should be before the Arrival date at the Supermarket"<<endl;
			cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
			cin>>arrivalDate.Day>>arrivalDate.Month>>arrivalDate.Year;
			}
			if(arrivalDate.Month>date.Month&&arrivalDate.Year<=date.Year){
			cout<<"Error! Arrival date at the local harbour should be before the Arrival date at the Supermarket"<<endl;
			cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
			cin>>arrivalDate.Day>>arrivalDate.Month>>arrivalDate.Year;
			}
			if(arrivalDate.Day>date.Day&&arrivalDate.Month<=date.Month&&arrivalDate.Year<=date.Year){
			cout<<"Error! Arrival date at the local harbour should be before the Arrival date at the Supermarket"<<endl;
			cout<<"Date of arrival at the local harbour(dd mm yy) :  ";
			cin>>arrivalDate.Day>>arrivalDate.Month>>arrivalDate.Year;
			}
			if(arrivalDate.Day<=date.Day&&arrivalDate.Month<=date.Month&&arrivalDate.Year<=date.Year){
			break;
			}
			}
		cout<<"Ship number :  ";														//int error checking needed
		cin>>no;
		cout<<endl;
		InternationalSupply::SetData(name,amount,date,country,arrivalDate,no);	
	}


int main() {
	
LocalSupply L1("","");
InternationalSupply L2;
L2.GetData();

return 0;
}
