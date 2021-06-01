///Write a program to prepare a shopping list.


#include<iostream>
#include <iomanip>

using namespace std;

class ShoppingList
{
    string itemname;
    int qty;
    float rate;

public:
    void read_item()
    {
	cout<<"Enter the item name: ";
	cin>>itemname;
	cout<<"Enter the rate: ";
	cin>>rate;
	cout<<"Enter the quantity: ";
	cin>>qty;
    }

    void print_item()
    {
	cout<<setw(15)<<itemname;
	cout<<setw(10)<<qty;
	cout<<setw(5)<<rate;
	cout<<setw(8)<<rate*qty<<endl;
    }
};

int main()
{
    ShoppingList items[50];
    int n;
    cout<<"Enter the amount of item: ";
    cin>>n;

    for(int i=0;i<n;i++){
	items[i].read_item();
    }

    cout<<setw(30)<<"Shopping List"<<endl;
    cout<<setw(15)<<"Item name"<<setw(10)<<"Quantity"<<setw(5)<<"Rate"<<setw(8)<<"Amount"<<endl;


    for(int j=0;j<n;j++){
	items[j].print_item();
    }

    return 0;
}
