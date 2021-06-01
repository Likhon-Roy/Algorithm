///Write a program to swap two numbers using friend function

#include<iostream>

using namespace std;

class SwapNumbers
{
private:
    int x,y;
public:
    void getnum()
    {
	cout<<"Enter the first number: ";
	cin>>x;
	cout<<"Enter the second num: ";
	cin>>y;
    }
    void shownum()
    {
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
    }
    friend void swap(SwapNumbers &s);
};

void swap(SwapNumbers &s)
{
    int temp;
    temp=s.x;
    s.x=s.y;
    s.y=temp;
}


int main()
{
    SwapNumbers s;
    s.getnum();
    cout<<"Before swaping: "<<endl;
    s.shownum();

    cout<<endl<<"After swaping: "<<endl;
    swap(s);
    s.shownum();
    return 0;
}
