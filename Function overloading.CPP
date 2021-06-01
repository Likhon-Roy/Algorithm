///Program to find the aria and volume of respective figures using Function Overloading

#include<iostream>

using namespace std;

const double PI=3.1416;

class Measure
{
public:
    void shape(double r)
    {
	cout<<"Area of circle = "<<PI*r*r<<endl;
	cout<<"Volume of circle = "<<(4/3)*PI*r*r*r<<endl;
    }
    void shape(int l,int b,int h)
    {
	cout<<"Area of rectangle = "<<l*b<<endl;
	cout<<"Volume of a rectangle = "<<l*b*h<<endl;
    }
    void shape(int s)
    {
	cout<<"Area of square = "<<s*s<<endl;
	cout<<"Volume of a cube = "<<s*s*s<<endl;
    }
};





int main()
{
    Measure m;
    int side,breadth,height,length;
    double radius;

    cout<<"Enter radius of circle: ";
    cin>>radius;
    m.shape(radius);

    cout<<endl<<"Enter length, breadth and height of rectangle: ";
    cin>>length>>breadth>>height;
    m.shape(length,breadth,height);

    cout<<endl<<"Enter a side of a square: ";
    cin>>side;
    m.shape(side);

    return 0;
}
