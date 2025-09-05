#include "Item.h"
#include "BakeryFrozenDiarySnacksBeveragesHealthCondiments.h"
#include "Produce.h"
#include "Meatseafood.h"
#include "../Transaction.h"
#include "Grain.h"
#include "Brand.h"

#include <fstream>

std::vector<Produce> dataProduce;
std::vector<Meatseafood>dataMeatseafood;
std::vector<Grain>dataGrain;
std::vector<BakeryFrozenDiarySnacksBeveragesHealthCondiments>dataBakeryProduct,dataFrozenProduct,dataDiaryProduct,dataSnaksAndSweets,
                dataBevarages,dataHealthAndBeauty,dataCondimentsAndSpices;
std::vector<BakeryFrozenDiarySnacksBeveragesHealthCondiments>* vectorPointer[]={&dataBakeryProduct,&dataFrozenProduct,&dataDiaryProduct,
                &dataSnaksAndSweets,&dataBevarages,&dataHealthAndBeauty,&dataCondimentsAndSpices};
extern void saveSupplyDetails();

bool changeCategory[10]={0,0,0,0,0,0,0,0,0,0};
float retailPrice,discount,weightOfItem;
std::string itemName,brandName,brandRegion;
int numberOfItem;

std::fstream file;
std::string fileName[]={"./test/item/file_bakery_product.txt","./test/item/file_frozen_product.txt","./test/item/file_diary_product.txt","./test/item/file_snaks_and_sweets.txt","./test/item/file_bevarages.txt",
                "./test/item/file_health_and_beauty.txt","./test/item/file_condiments_and_spices.txt"};

Item::Item(){
	getchar();
    std::cout<<"Item Name          : ";
    std::getline(std::cin, itemName);

    do{
        std::cout<<"Retail Price       : ";
        while (!(std::cin >> retailPrice)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Enter a suitable value : ";
        }
    }while (0 >= retailPrice);

    do{
        std::cout<<"Discount           : ";
        while (!(std::cin >> discount)){
            std::cin.clear(); // clear the fail bit
            std::cin.ignore(100, '\n'); // ignore the invalid entry
            std::cout<<"Enter a suitable value : ";
        }
    }while ((discount<0)||(discount>100));

    finalPrice =retailPrice*(100-discount)/100;
}

Item::Item(std::string a,float b,float c):itemName(a),retailPrice(b),discount(c),finalPrice(b*(100-c)/100){}

std::string Item::returnItemName(){ 
    return itemName;
}

float Item::returnRetailPrice(){
    return retailPrice;
}

float Item::returnDiscount(){
    return discount;
}

float Item::returnFinalPrice(){
    return finalPrice;
}

int selectCategory(){
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

int addOrRemoveStock(int x, Transaction *transaction ){
    int Category =selectCategory();
    int iNo,addOrGet, price,i=0;
    std::cout<<"List of Items";
    changeCategory[Category-1]=true;

    if(Category==1){
        for(;i<dataProduce.size();i++)
            std::cout<<"\n"<<i+1<<"."<<dataProduce[i].returnItemName();
    }else if(Category==2){
        for(;i<dataMeatseafood.size();i++)
            std::cout<<"\n"<<i+1<<"."<<dataMeatseafood[i].returnItemName();
    }else if(Category==3){
        for(;i<dataGrain.size();i++)
            std::cout<<"\n"<<i+1<<"."<<dataGrain[i].returnItemName();
    }else{
        for(;i<(*vectorPointer[Category-4]).size();i++)
            std::cout<<"\n"<<i+1<<"."<<(*vectorPointer[Category-4])[i].returnItemName();
    }
    std::cout << "\n";
    
    if(x == 1){
    	std::cout << "\n*If item is not in stock use add item function to add that item. Only managers and owners have access to that function contact them to add new item*\n";
    	std::cout << "Press 0 to go back\n";
    	do{
	        std::cout << "\nSelect Item (No. within range) : ";
	        while (!(std::cin >> iNo)){
	            std::cin.clear(); // clear the fail bit
	            std::cin.ignore(100, '\n'); // ignore the invalid entry
	            std::cout << "Enter a suitbale item number : ";
	        }
	        if(iNo == 0){
	        	return 0;
			}
    	}while (0 > iNo || i < iNo);
	}
    
    else{
    	std::cout << "\n**Press 0 to go back\n";
	    do{
	        std::cout << "\nSelect Item (No. within range) : ";
	        while (!(std::cin >> iNo)){
	            std::cin.clear(); // clear the fail bit
	            std::cin.ignore(100, '\n'); // ignore the invalid entry
	            std::cout << "Enter a suitbale item number : ";
	        }
	        if(iNo == 0){
	        	return 0;
			}
	    }while (0 > iNo || i < iNo);
	}
    bool underFlow;
	do{
		underFlow = false;
	    do{
	    	if(x==1) std::cout<<"Enter the numbers of item to increase : ";
	    	else     std::cout<<"Enter the numbers of item to remove   : ";
		    while (!(std::cin >> addOrGet)){
		        std::cin.clear(); // clear the fail bit
		        std::cin.ignore(100, '\n'); // ignore the invalid entry
		        std::cout << "Enter a suitbale item number : ";
		    }
		}while(addOrGet < 0);
	
	    if(Category==1){
	        if(x==1)
	        *(dataProduce[iNo-1].returnPointerNumberOfItem()) +=addOrGet;
	        else if(*(dataProduce[iNo-1].returnPointerNumberOfItem())>=addOrGet){
	            *(dataProduce[iNo-1].returnPointerNumberOfItem()) -=addOrGet;
	            if(transaction){
	            	(*transaction).items.emplace_back(std::make_pair(dataProduce[iNo-1].returnItemName(), addOrGet));
	            	price = dataProduce[iNo-1].returnFinalPrice();
				}
	        }
	        else{
	        	if(*(dataProduce[iNo-1].returnPointerNumberOfItem())==0)
	            std::cout<<"No items in the stock\n";
	            else{
	            std::cout<<"Not enough items in the Stock\n";
	            underFlow = true;
				}
			}	
	    }else if(Category==2){
	        if(x==1)
	        *(dataMeatseafood[iNo-1].returnPointerWeightOfItem()) +=addOrGet;
	        else if(*(dataMeatseafood[iNo-1].returnPointerWeightOfItem())>=addOrGet){
	            *(dataMeatseafood[iNo-1].returnPointerWeightOfItem()) -=addOrGet;
	            if(transaction){
	            	(*transaction).items.emplace_back(std::make_pair(dataMeatseafood[iNo-1].returnItemName(), addOrGet));
	            	price = dataMeatseafood[iNo-1].returnFinalPrice();
				}
	        }
	        else{
	            if(*(dataMeatseafood[iNo-1].returnPointerWeightOfItem())==0)
	            std::cout<<"No items in the stock\n";
	            else{
	            std::cout<<"Not enough items in the Stock\n";
	            underFlow = true;
	            }
	        }
	    }else if(Category==3){
	        if(x==1)
	        *(dataGrain[iNo-1].returnPointerWeightOfItem()) +=addOrGet;
	        else if(*(dataGrain[iNo-1].returnPointerWeightOfItem())>=addOrGet){
	            *(dataGrain[iNo-1].returnPointerWeightOfItem()) -=addOrGet;
	            if(transaction){
	            	(*transaction).items.emplace_back(std::make_pair(dataGrain[iNo-1].returnItemName(), addOrGet));
	            	price = dataGrain[iNo-1].returnFinalPrice();
				}
	        }
	        else{
	            if(*(dataGrain[iNo-1].returnPointerWeightOfItem())==0)
	            std::cout<<"No items in the stock\n";
	            else{
	            std::cout<<"Not enough items in the Stock\n";
	            underFlow = true;
	            }
	        }
	    }else{
	        if(x==1)
	        *((*vectorPointer[Category-4])[iNo-1].returnPointerNumberOfItem()) +=addOrGet;
	        else if(*((*vectorPointer[Category-4])[iNo-1].returnPointerNumberOfItem())>=addOrGet){
	            *((*vectorPointer[Category-4])[iNo-1].returnPointerNumberOfItem()) -=addOrGet;
	            if(transaction){
	            	(*transaction).items.emplace_back(std::make_pair((*vectorPointer[Category-4])[iNo-1].returnItemName(), addOrGet));
	            	price = (*vectorPointer[Category-4])[iNo-1].returnFinalPrice();
				}
	        }	
	        else{
	            if(*((*vectorPointer[Category-4])[iNo-1].returnPointerNumberOfItem())==0)
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
	return (addOrGet * price);
}

void addNewItem(int Category){
    std::cout<<"Enter item Details\n";
    changeCategory[Category-1]=true;
    char order;
    do{
        if(Category==1)      dataProduce.push_back(Produce());
        else if(Category==2) dataMeatseafood.push_back(Meatseafood());
        else if(Category==3) dataGrain.push_back(Grain());
        else                 (*vectorPointer[Category-4]).push_back(BakeryFrozenDiarySnacksBeveragesHealthCondiments());

        do{
        std::cout<<"ENTER N/n to add a new item\nENTER E/e TO EXIT\n";
        std::cin>>order;
        if((order!='N')&&(order!='n')&&(order!='E')&&(order!='e'))
            std::cout<<"Enter a correct option.\n";
        else
            break;
        }while(true);
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
    }while((order!='E')&&(order!='e'));
}

void saveAndExit(){
    for(int i=0;i<10;i++){
    if(changeCategory[i]==1){
        if(i==0){
            file.open("./test/item/file_produce.txt");
            for(int k=0;k<dataProduce.size();k++)
            file<<dataProduce[k].returnItemName()<<"\n"<<dataProduce[k].returnRetailPrice()<<" "<<dataProduce[k].returnDiscount()
			<<" "<<dataProduce[k].returnNumberOfItem()<<"\n";}
        else if(i==1){
            file.open("./test/item/file_meat_seafood.txt");
            for(int k=0;k<dataMeatseafood.size();k++)
            file<<dataMeatseafood[k].returnItemName()<<"\n"<<dataMeatseafood[k].returnRetailPrice()<<" "<<dataMeatseafood[k].returnDiscount()
			<<" "<<dataMeatseafood[k].returnWeightOfItem()<<"\n";}
        else if(i==2){
            file.open("./test/item/file_grain.txt");
            for(int k=0;k<dataGrain.size();k++)
            file<<dataGrain[k].returnItemName()<<"\n"<<dataGrain[k].returnRetailPrice()<<" "<<dataGrain[k].returnDiscount()<<" "
			<<dataGrain[k].returnWeightOfItem()<<"\n"<<dataGrain[k].returnBrandName()<<"\n"<<dataGrain[k].returnBrandRegion()<<"\n";}
        else{
            file.open(fileName[i-3]);
            for(int k=0;k<(*vectorPointer[i-3]).size();k++)
            file<<(*vectorPointer[i-3])[k].returnItemName()<<"\n"<<(*vectorPointer[i-3])[k].returnRetailPrice()<<" "<<
			(*vectorPointer[i-3])[k].returnDiscount()<<" "<<(*vectorPointer[i-3])[k].returnNumberOfItem()<<"\n"<<(*vectorPointer[i-3])[k].returnBrandName()<<
			"\n"<<(*vectorPointer[i-3])[k].returnBrandRegion()<<"\n";}
        file.close();
    }
    }
    saveSupplyDetails();
    exit(0);
}
 
void initializeData(){
	std::string dummy;
    file.open("./test/item/file_produce.txt");
    int i;
    if(!file){
        std::cout<<"File_produce.txt not found\n";
        std::ofstream newfile("./test/item/file_produce.txt");
        addNewItem(1);
        newfile.close();
    }
    else{
    	i = 0;
        while(!file.eof()){
        	if(i == 0){
        		getline(file, itemName);
			}
			else if(i == 1){
				file>>retailPrice>>discount>>numberOfItem;
				getline(file, dummy);
			}
			else{
				dataProduce.push_back(Produce (itemName,retailPrice,discount,numberOfItem));
				i = -1;
			}
			i++;
        }
    }
    file.close();
    
    file.open("./test/item/file_meat_seafood.txt");
    if(!file){
        std::cout<<"File_meat_seafood.txt not found\n";
        std::ofstream newfile("./test/item/file_meat_seafood.txt");
        addNewItem(2);
        newfile.close();
    }
    else{
    	i = 0;
        while(!file.eof()){
        	if(i == 0){
        		getline(file, itemName);
			}
			else if(i == 1){
				file>>retailPrice>>discount>>numberOfItem;
				getline(file, dummy);
			}
			else{
				dataMeatseafood.push_back(Meatseafood (itemName,retailPrice,discount,numberOfItem));
				i = -1;
			}
			i++;
        }
    }
    file.close();
 
    file.open("./test/item/file_grain.txt");
    if(!file){
        std::cout<<"File_grain.txt not found\n";
        std::ofstream newfile("./test/item/file_grain.txt");
        addNewItem(3);
        newfile.close();
    }
    else{
    	i = 0;
        while(!file.eof()){
        	if(i == 0){
        		getline(file, itemName);
			}
			else if(i == 1){
				file>>retailPrice>>discount>>weightOfItem;
				getline(file, brandName);
			}
			else if(i == 2){
				getline(file, brandName);
			}
			else if(i == 3){
				file>>brandRegion;
				getline(file, dummy);
			}
			else{
				dataGrain.push_back(Grain (itemName,retailPrice,discount,weightOfItem,brandName,brandRegion));
				i = -1;
			}
			i++;
        }
    }
    file.close();

    for(int j=0;j<7;j++){
        file.open(fileName[j]);
        if(!file){
            std::cout<<fileName[j]<<" not found\n";
            std::ofstream newfile(fileName[j]);
            addNewItem(j+4);
            newfile.close();
        }
        else{
        	i = 0;
        	while(!file.eof()){
        	if(i == 0){
        		getline(file, itemName);
			}
			else if(i == 1){
				file>>retailPrice>>discount>>numberOfItem;
				getline(file, brandName);
			}
			else if(i == 2){
				getline(file, brandName);
			}
			else if(i == 3){
				file>>brandRegion;
				getline(file, dummy);
			}
			else{
				(*vectorPointer[j]).push_back(BakeryFrozenDiarySnacksBeveragesHealthCondiments (itemName,retailPrice,discount,numberOfItem,brandName,brandRegion));
				i = -1;
			}
			i++;
        }
        }
        file.close();
    }
}


