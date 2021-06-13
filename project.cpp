#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class item{
    public:
    string item_name;
    float retail_price;
    float discount;
    float final_price=retail_price*(100-discount);
    item(){}
    item(bool x){
        cout<<"Item Name    : ";
        cin>>item_name;
        cout<<"Retail Price : ";
        cin>>retail_price;
        cout<<"Discount     : ";
        cin>>discount;
    }
    item(string a,float b,float c):item_name(a),retail_price(b),discount(c){}
};

class brand{
    public:
    string brand_name;
    string brand_region;
    brand(){}
    brand(string a,string b):brand_name(a),brand_region(b){}
};

class produce:public item{
    public:
    int number_of_item;
    produce(){}
    produce(bool x){
        item(0);
        cout<<"Number of Item : ";
        cin>>number_of_item;
    }
    produce(string a,float b,float c,int d):item(a,b,c),number_of_item(d){}
};

class bakery_product:public produce,public brand{
	public:
	bakery_product(){}
	bakery_product(string a,float b,float c,int d,string e,string f):produce(a,b,c,d),brand(e,f){}
};

class meat_seafood:public item{
    public:
    double weight_of_item;
    meat_seafood(){}
    meat_seafood(string a,float b,float c,double d):item(a,b,c),weight_of_item(d){}
    };

class grain:public meat_seafood,public brand{
	public:
    grain(){}
    grain(string a,float b,float c,double d,string e,string f):meat_seafood(a,b,c,d),brand(e,f){}
}; 

class frozen_product:public bakery_product{
    public:
    frozen_product(string a,float b,float c,int d,string e,string f):bakery_product(a,b,c,d,e,f){}
};
class diary_product:public bakery_product{
    public:
    diary_product(string a,float b,float c,int d,string e,string f):bakery_product(a,b,c,d,e,f){}
};
class snaks_and_sweets:public bakery_product{
    public:
    snaks_and_sweets(string a,float b,float c,int d,string e,string f):bakery_product(a,b,c,d,e,f){}
};
class bevarages:public bakery_product{
    public:
    bevarages(string a,float b,float c,int d,string e,string f):bakery_product(a,b,c,d,e,f){}
};
class health_and_beauty:public bakery_product{
    public:
    health_and_beauty(string a,float b,float c,int d,string e,string f):bakery_product(a,b,c,d,e,f){}
};
class condiments_and_spices:public bakery_product{
    public:
    condiments_and_spices(string a,float b,float c,int d,string e,string f):bakery_product(a,b,c,d,e,f){}
};

int main()
{
    vector<produce> data_produce;
    vector<bakery_product>data_bakery_product;
    vector<meat_seafood>data_meat_seafood;
    vector<grain>data_grain;
    vector<frozen_product>data_frozen_product;
    vector<diary_product>data_diary_product;
    vector<snaks_and_sweets>data_snaks_and_sweets;
    vector<bevarages>data_bevarages;
    vector<health_and_beauty>data_health_and_beauty;
    vector<condiments_and_spices>data_condiments_and_spices;

    string item_name,brand_name,brand_region;
    float retail_price,discount,weight_of_item;
    int number_of_item;

    fstream file_produce,file_bakery_product,file_meat_seafood,file_grain,file_frozen_product;
    fstream file_diary_product,file_snaks_and_sweets,file_bevarages,file_health_and_beauty,file_condiments_and_spices;

    file_produce.open("file_produce.txt");
    if(!file_produce){
        cout<<"File not found";
    }
    else while(!file_produce.eof()){
    file_produce>>item_name>>retail_price>>discount>>number_of_item;
    produce temp(item_name,retail_price,discount,number_of_item);
    data_produce.push_back(temp);
    }
    file_produce.close();

    file_bakery_product.open("file_bakery_product.txt");
    if(!file_bakery_product){
        cout<<"File not found";
    }
    else while(!file_bakery_product.eof()){
    file_bakery_product>>item_name>>retail_price>>discount>>number_of_item>>brand_name>>brand_region;
    bakery_product temp(item_name,retail_price,discount,number_of_item,brand_name,brand_region);
    data_bakery_product.push_back(temp);
    }

    

    file_meat_seafood.open("file_meat_seafood.txt");
    if(!file_meat_seafood){
        cout<<"File not found";
    }
    else while(!file_meat_seafood.eof()){
    file_meat_seafood>>item_name>>retail_price>>discount>>weight_of_item;
    meat_seafood temp(item_name,retail_price,discount,weight_of_item);
    data_meat_seafood.push_back(temp);
    }

     

    file_grain.open("file_grain.txt");
    if(!file_grain){
        cout<<"File not found";
    }
    else while(!file_grain.eof()){
    file_grain>>item_name>>retail_price>>discount>>weight_of_item>>brand_name>>brand_region;
    grain temp(item_name,retail_price,discount,weight_of_item,brand_name,brand_region);
    data_grain.push_back(temp);
    }

 

    file_frozen_product.open("file_frozen_product.txt");
    if(!file_frozen_product){
        cout<<"File not found";
    }
    else while(!file_frozen_product.eof()){
    file_frozen_product>>item_name>>retail_price>>discount>>number_of_item>>brand_name>>brand_region;
    frozen_product temp(item_name,retail_price,discount,number_of_item,brand_name,brand_region);
    data_frozen_product.push_back(temp);
    }

    

    file_diary_product.open("file_diary_product.txt");
    if(!file_diary_product){
        cout<<"File not found";
    }
    else while(!file_diary_product.eof()){
    file_diary_product>>item_name>>retail_price>>discount>>number_of_item>>brand_name>>brand_region;
    diary_product temp(item_name,retail_price,discount,number_of_item,brand_name,brand_region);
    data_diary_product.push_back(temp);
    }



    file_snaks_and_sweets.open("file_snaks_and_sweets.txt");
    if(!file_snaks_and_sweets){
        cout<<"File not found";
    }
    else while(!file_snaks_and_sweets.eof()){
    file_snaks_and_sweets>>item_name>>retail_price>>discount>>number_of_item>>brand_name>>brand_region;
    snaks_and_sweets temp(item_name,retail_price,discount,number_of_item,brand_name,brand_region);
    data_snaks_and_sweets.push_back(temp);
    }

   

    file_bevarages.open("file_bevarages.txt");
    if(!file_bevarages){
        cout<<"File not found";
    }
    else while(!file_bevarages.eof()){
    file_bevarages>>item_name>>retail_price>>discount>>number_of_item>>brand_name>>brand_region;
    bevarages temp(item_name,retail_price,discount,number_of_item,brand_name,brand_region);
    data_bevarages.push_back(temp);
    }

   

    file_health_and_beauty.open("file_health_and_beauty.txt");
    if(!file_health_and_beauty){
        cout<<"File not found";
    }
    else while(!file_health_and_beauty.eof()){
    file_health_and_beauty>>item_name>>retail_price>>discount>>number_of_item>>brand_name>>brand_region;
    health_and_beauty temp(item_name,retail_price,discount,number_of_item,brand_name,brand_region);
    data_health_and_beauty.push_back(temp);
    }



    file_condiments_and_spices.open("file_condiments_and_spices.txt");
    if(!file_condiments_and_spices){
        cout<<"File not found";
    }
    else while(!file_condiments_and_spices.eof()){
    file_condiments_and_spices>>item_name>>retail_price>>discount>>number_of_item>>brand_name>>brand_region;
    condiments_and_spices temp(item_name,retail_price,discount,number_of_item,brand_name,brand_region);
    data_condiments_and_spices.push_back(temp);
    }
    cout<<data_condiments_and_spices[0].item_name;


    //insert new item
     produce add(0);
     data_produce.push_back(add);
     file_produce.open("file_produce.txt");
     file_produce<<" "<<add.item_name<<" "<<(add.retail_price)<<" "<<(add.discount)<<" "<<(add.number_of_item);
     file_produce.close();
  



}
