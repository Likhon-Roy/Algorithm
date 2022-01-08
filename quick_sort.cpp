#include<iostream>
using namespace std;

int partitionn(int A[],int low,int high)
{
    int i,j,temp;
    int pivot=A[high];

    for(i=low-1,j=low;j<high;j++){
        if(A[j]<pivot){
            i++;
            temp=A[j];
            A[j]=A[i];
            A[i]=temp;
        }
    }
    i++;
    temp=A[high];
    A[high]=A[i];
    A[i]=temp;
    return i;
}

void quick_sort(int A[],int low,int high)
{
    if(low>=high) return;

    int middle;
    middle=partitionn(A,low,high);

    quick_sort(A,low,middle-1);
    quick_sort(A,middle+1,high);
}

int main()
{
    int n;
    cin>>n;
    int A[10];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    quick_sort(A,0,n-1);

    for(int i=0;i<n;i++){
        cout<<A[i]<<"  ";
    }

}
