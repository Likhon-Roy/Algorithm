#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void pls_algorithm(char *patt,int *pls, int m);
void kmp_algorithm(char *text, char *patt)
{
    int m,n,i=0,j=0;
    m=strlen(patt);
    n=strlen(text);
    int *pls;
    pls=(int*)malloc(m*sizeof(int));

    pls_algorithm(patt,pls,m);

    while(i<n){
        if(patt[j]==text[i]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"the match found at position "<<i-j;
            j=pls[j-1];
        }
        else if(text[i]!=patt[j] && i<n){
            if(j!=0){
                j=pls[j-1];
            }
            else{
                i++;
            }
        }
    }

}

void pls_algorithm(char *patt,int *pls, int m)
{
    int i,j,len;

    pls[0]=0;
    i=1;
    len=0;
    while(i<m){
        if(patt[len]==patt[i]){
            len++;
            pls[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=pls[len-1];
            }
            else{
                pls[i]=len;
                i++;
            }
        }
    }
    for(int j=0;j<m;j++){
        cout<<pls[j]<<"\t";
    }
    cout<<endl;
}

int main()
{
    char text[60],patt[50];
    cout<<"enter the two string\n";
    cin>>text>>patt;
    kmp_algorithm(text,patt);

}



















