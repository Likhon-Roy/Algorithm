#include<iostream>
#include<algorithm>

using namespace std;

class knacksack
{
public:
    int value;
    int waight;
    knacksack(int v,int w): value(v),waight(w){};

};

int fracrional_knacksack_problem(int n,knacksack arr[],int W)
{
    sort(arr,arr+n,[](knacksack x,knacksack y){
            double a=(double)x.value/x.waight;
            double b=(double)y.value/y.waight;
            return a>b;
         });
    int curwaight=0;
    double curvalue=0;
    for(int i=0;i<n;i++){
        if(curwaight+arr[i].waight<=W){
            curwaight+=arr[i].waight;
            curvalue+=arr[i].value;
        }
        else{
            int recent=W-curwaight;
            curvalue+=arr[i].value*((double)recent/arr[i].waight);
            break;
        }
    }
    return curvalue;
}



int main()
{
    knacksack arr[]={{100,20},{120,30},{60,10}};
    int W=50;

    int n=sizeof(arr)/sizeof(arr[0]);
    //cout<<n<<endl;

    cout<< "the result is : "<<fracrional_knacksack_problem(n,arr,W)<<endl;


}
