#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class item{
    private:
    string item_name;
    float retail_price;
    float discount;
    float final_price;

    public:
    item();
    item(string a,float b,float c):item_name(a),retail_price(b),discount(c),final_price(b*(100-c)/100){}
    string return_item_name(){ return item_name;}
    float return_retail_price(){return retail_price;}
    float return_discount(){return discount;}
    float return_final_price(){return final_price;}
    virtual ~item();
};

item::item(){
    cout<<"Item Name          : ";
    cin>>item_name;
    cout<<"Retail Price       : ";
    cin>>retail_price;
    cout<<"Discount           : ";
    cin>>discount;
    final_price =retail_price*(100-discount)/100;
    }

class brand{
    private:
    string brand_name;
    string brand_region;

    public:
    brand();
    brand(string a,string b):brand_name(a),brand_region(b){}
    string return_brand_name(){return brand_name;}
    string return_brand_region(){return brand_region;}
    virtual ~brand();
};

brand::brand(){
    cout<<"Enter Brand name   : ";
    cin>>brand_name;
    cout<<"Enter Brand region : ";
    cin>>brand_region;
}

class produce:public item{
    private:
    int number_of_item;

    public:
    produce();
    produce(string a,float b,float c,int d):item(a,b,c),number_of_item(d){}
    int return_number_of_item(){return number_of_item;}
    int*return_pointer_number_of_item(){return &number_of_item;}
    virtual ~produce();
};

produce::produce():item(){
        cout<<"Number of Item     : ";
        cin>>number_of_item;
}

class bakery_frozen_diary_snaks_bevarages_health_condiments:public produce,public brand{
	public:
	bakery_frozen_diary_snaks_bevarages_health_condiments():produce(),brand(){}
	bakery_frozen_diary_snaks_bevarages_health_condiments(string a,float b,float c,int d,string e,string f):produce(a,b,c,d),brand(e,f){}
    virtual ~bakery_frozen_diary_snaks_bevarages_health_condiments();
};

class meat_seafood:public item{
    private:
    double weight_of_item;

    public:
    meat_seafood();
    meat_seafood(string a,float b,float c,double d):item(a,b,c),weight_of_item(d){}
    double return_weight_of_item(){return weight_of_item;}
    double* return_pointer_weight_of_item(){return &weight_of_item;}
    virtual ~meat_seafood();
};

meat_seafood::meat_seafood():item(){
    cout<<"Enter weight of item";
    cin>>weight_of_item;
}

class grain:public meat_seafood,public brand{
	public:
    grain():meat_seafood(),brand(){}
    grain(string a,float b,float c,double d,string e,string f):meat_seafood(a,b,c,d),brand(e,f){}
    virtual ~ grain();
}; 

vector<produce> data_produce;
vector<meat_seafood>data_meat_seafood;
vector<grain>data_grain;
vector<bakery_frozen_diary_snaks_bevarages_health_condiments>data_bakery_product,data_frozen_product,data_diary_product,data_snaks_and_sweets,data_bevarages,data_health_and_beauty,data_condiments_and_spices;
vector <bakery_frozen_diary_snaks_bevarages_health_condiments>* vector_pointer[]={&data_bakery_product,&data_frozen_product,&data_diary_product,&data_snaks_and_sweets,&data_bevarages,&data_health_and_beauty,&data_condiments_and_spices};

string file_name[]={"file_bakery_product.txt","file_frozen_product.txt","file_diary_product.txt","file_snaks_and_sweets.txt","file_bevarages.txt","file_health_and_beauty.txt","file_condiments_and_spices.txt"};
bool change_Category[10]={0,0,0,0,0,0,0,0,0,0};
float retail_price,discount,weight_of_item;
string item_name,brand_name,brand_region;
int number_of_item;
fstream file;

int select_category(){
    char Category;
    cout<<"\n CATEGORY OF ITEMS\n -----------------\n";
    cout<<" A.Produce\n B.Meat seafood\n C.Grain\n D.Bakery product\n E.Frozen product\n F.Diary product\n "
    "G.Snaks and sweets\n H.Bevarages\n I.Health and beauty\n J.Condiments and spices\n\n";
    do{
        cout<<"Select Category of item : "; cin>>Category;
    }while( !((int(Category)>64)&&(int(Category)<75)) && !((int(Category)>96)&&(int(Category)<107)));

    if(int(Category)<75)
    return int(Category)-64;
    else
    return int(Category)-96;
}

void add_or_remove_stock(int x){
    int Category =select_category();
    int i_no,add_or_get;
    cout<<"List of Items";
    change_Category[Category-1]=true;

    switch(Category){
        case 1:{
            for(int i=0;i<data_produce.size();i++)
            cout<<endl<<i+1<<"."<<data_produce[i].return_item_name();
            cout<<"\nSelect Item : "; cin>>i_no;
            cout<<"Enter the numbers of item to ";
            if(x==1) cout<<"increase : ";
            else cout<<"remove : ";
            cin>>add_or_get;

            if(x==1) *(data_produce[i_no-1].return_pointer_number_of_item()) +=add_or_get;
            else     *(data_produce[i_no-1].return_pointer_number_of_item()) -=add_or_get;
            break;
        }
        case 2:{
            for(int i=0;i<data_meat_seafood.size();i++)
            cout<<endl<<i+1<<"."<<data_meat_seafood[i].return_item_name();
            cout<<"\nSelect Item : "; cin>>i_no;
            cout<<"Enter the weight of item to ";
            if(x==1) cout<<"increase : ";
            else     cout<<"decrease : ";
            cin>>add_or_get;

            if(x==1) *(data_meat_seafood[i_no-1].return_pointer_weight_of_item()) +=add_or_get;
            else     *(data_meat_seafood[i_no-1].return_pointer_weight_of_item()) -=add_or_get;
            break;
        }
        case 3:{
            for(int i=0;i<data_grain.size();i++)
            cout<<endl<<i+1<<"."<<data_grain[i].return_item_name();
            cout<<"\nSelect Item : "; cin>>i_no;
            cout<<"Enter the weight of item to ";
            if(x==1) cout<<"decrease : ";
            else     cout<<"remove : ";
            cin>>add_or_get;

            if(x==1) *(data_grain[i_no-1].return_pointer_weight_of_item()) +=add_or_get;
            else     *(data_grain[i_no-1].return_pointer_weight_of_item()) -=add_or_get;
            break;
        }
        default:{
            for(int i=0;i<(*vector_pointer[Category-4]).size();i++)
            cout<<endl<<i+1<<"."<<(*vector_pointer[Category-4])[i].return_item_name();
            cout<<"\nSelect Item : "; cin>>i_no;
            cout<<"Enter the numbers of item to ";
            if(x==1) cout<<"increase : ";
            else     cout<<"remove : ";
            cin>>add_or_get;

            if(x==1) *((*vector_pointer[Category-4])[i_no-1].return_pointer_number_of_item()) +=add_or_get;
            else     *((*vector_pointer[Category-4])[i_no-1].return_pointer_number_of_item()) -=add_or_get;
            break;
        }
    }
}

void add_new_item(){
    int Category =select_category();
    cout<<"Enter item Details\n";
    change_Category[Category-1]=true;

    if(Category==1)      data_produce.push_back(produce());
    else if(Category==2) data_meat_seafood.push_back(meat_seafood());
    else if(Category==3) data_grain.push_back(grain());
    else                 (*vector_pointer[Category-4]).push_back(bakery_frozen_diary_snaks_bevarages_health_condiments());
}

void save_and_exit(){
    for(int i=0;i<10;i++){
    if(change_Category[i]==1){
        if(i==0){
            file.open("file_produce.txt");
            for(int k=0;k<data_produce.size();k++)
            file<<data_produce[k].return_item_name()<<" "<<data_produce[k].return_retail_price()<<" "<<data_produce[k].return_discount()<<" "<<data_produce[k].return_number_of_item()<<endl;}
        else if(i==1){
            file.open("file_meat_seafood.txt");
            for(int k=0;k<data_meat_seafood.size();k++)
            file<<data_meat_seafood[k].return_item_name()<<" "<<data_meat_seafood[k].return_retail_price()<<" "<<data_meat_seafood[k].return_discount()<<" "<<data_meat_seafood[k].return_weight_of_item()<<endl;}
        else if(i==2){
            file.open("file_grain.txt");
            for(int k=0;k<data_grain.size();k++)
            file<<data_grain[k].return_item_name()<<" "<<data_grain[k].return_retail_price()<<" "<<data_grain[k].return_discount()<<" "<<data_grain[k].return_weight_of_item()<<" "<<data_grain[k].return_brand_name()<<" "<<data_grain[k].return_brand_region()<<endl;}
        else{
            file.open(file_name[i-3]);
            for(int k=0;k<(*vector_pointer[i-3]).size();k++)
            file<<(*vector_pointer[i-3])[k].return_item_name()<<" "<<(*vector_pointer[i-3])[k].return_retail_price()<<" "<<(*vector_pointer[i-3])[k].return_discount()<<" "<<(*vector_pointer[i-3])[k].return_number_of_item()<<" "<<(*vector_pointer[i-3])[k].return_brand_name()<<" "<<(*vector_pointer[i-3])[k].return_brand_region()<<endl;}
        file.close();
    }
    }
}

void initialize_data(){
    
    file.open("file_produce.txt");
    if(!file){
    cout<<"File not found";
    }
    else while(!file.eof()){
    file>>item_name>>retail_price>>discount>>number_of_item;
    data_produce.push_back(produce (item_name,retail_price,discount,number_of_item));
    }
    data_produce.pop_back();
    file.close();

    file.open("file_meat_seafood.txt");
    if(!file){
    cout<<"File not found";
    }
    else while(!file.eof()){
    file>>item_name>>retail_price>>discount>>weight_of_item;
    data_meat_seafood.push_back(meat_seafood (item_name,retail_price,discount,weight_of_item));
    }
    data_meat_seafood.pop_back();
    file.close();
 
    file.open("file_grain.txt");
    if(!file){
        cout<<"File not found";
    }
    else while(!file.eof()){
    file>>item_name>>retail_price>>discount>>weight_of_item>>brand_name>>brand_region;
    data_grain.push_back(grain (item_name,retail_price,discount,weight_of_item,brand_name,brand_region));
    }
    data_grain.pop_back();
    file.close();

    for(int i=0;i<7;i++){
    file.open(file_name[i]);
    if(!file){
    cout<<"File not found";
    }
    else while(!file.eof()){
    file>>item_name>>retail_price>>discount>>number_of_item>>brand_name>>brand_region;
    (*vector_pointer[i]).push_back(bakery_frozen_diary_snaks_bevarages_health_condiments (item_name,retail_price,discount,number_of_item,brand_name,brand_region));
    }
    (*vector_pointer[i]).pop_back();
    file.close();
    }
}

int main()
{
    initialize_data();
    add_or_remove_stock(1); //add num items
    add_or_remove_stock(0); //remove num items
    add_new_item();         //add new item
    save_and_exit();        //save
}
