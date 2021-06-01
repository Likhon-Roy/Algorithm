///Write a program to sort elements using templates.


#include<iostream>
using namespace std;

template<class T>
void bubble(T a[],int n)
{
    int i,j;
    T temp;
    for(i=0;i<=n-1;i++){
	for(j=i+1;j<n;j++){
	    if(a[i]>a[j]){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	    }
	}
    }
}


int main()
{
    int arr[5]={50,60,32,11,44};
    char c[5]={'a','i','o','u','e'};
    bubble(arr,5);
    cout<<"Sorted order num: "<<endl;
    for(int i=0;i<5;i++){
	cout<<arr[i]<<"  ";
    }
    cout<<endl<<endl;

    bubble(c,5);
    cout<<"Sorted order charecter: "<<endl;
    for(int j=0;j<5;j++){
	cout<<c[j]<<"  ";
    }
    cout<<endl;
    return 0;
}
