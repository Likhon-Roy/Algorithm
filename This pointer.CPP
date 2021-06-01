///Write a program to show returning current object accessing member data of
///current object and returning values of object using pointer

#include<iostream>

using namespace std;

class Myclass
{
private:
    int data1,data2;
public:
    Myclass(int data1, int data2)
    {
	this->data1=data1;
	this->data2=data2;
    }

    Myclass& assign()
    {
	this->data1=300;
	this->data2=400;
	return *this;
    }

    void print()
    {
	cout<<"data1 = "<<data1<<endl;
	cout<<"data2 = "<<data2<<endl;
    }
};





int main()
{
    Myclass obj1(100,200);
    obj1.print();

    cout<<endl;

    Myclass obj2=obj1.assign();
    obj2.print();
    return 0;
}
