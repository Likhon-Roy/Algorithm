///Write a program to calculate aria and circumference of circle using
/// inline function


#include<iostream>

using namespace std;

const double PI=3.14159;


inline float circum(float x)
{
    return (2*PI*x);
}
inline float area(float x)
{
    return (PI*x*x);
}

int main()
{
    float r;
    cout<<"Enter the radius of the circle: ";
    cin>>r;
    cout<<endl<<"Circumference : "<<circum(r)<<endl;
    cout<<endl<<"Aria : "<<area(r)<<endl;
}
