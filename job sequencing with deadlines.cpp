//job sequencing with deadlines
#include<iostream>
#include<algorithm>

using namespace std;

struct job
{
    char id;
    int profit;
    int deadline;
};

job_sequence_function(job arr[], int n)
{
    sort(arr,arr+n,[](job a,job b){
            return a.profit>b.profit;
         });
    int result[n];
    bool slot[n];

    for(int i=0;i<n;i++) slot[i]=false;

    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--){

            if(slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(slot[i]){
            cout<<arr[result[i]].id<<endl;
            sum+=arr[result[i]].profit;
        }
    }
    cout<<"the maximum profit is  "<<sum<<endl;
}

int main()
{
    job arr[]={
        {'a',100,2},{'b',19,1},{'c',27,2},{'d',25,1},{'e',15,3}
    };
    int n=sizeof(arr)/sizeof(arr[0]);

    job_sequence_function(arr,n);

}
