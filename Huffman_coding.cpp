#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct Min_heap_node
{
    char data;
    unsigned frequency;
    Min_heap_node *left,*right;

    Min_heap_node(unsigned frequency,char data)
    {
        left=right=NULL;
        this->data=data;
        this->frequency=frequency;
    }
};


struct compare
{
    bool operator()(Min_heap_node *l,Min_heap_node *r)
    {
        return l->frequency > r->frequency;
    }
};

void print_code(Min_heap_node *root,string str)
{
    if(!root)
        return;
    if(root->data!='$')
        cout<<root->data<<" : "<<str<<endl;

    print_code(root->left,str+"0");
    print_code(root->right,str+"1");
}

void Huffman_codeing(char data[],int freq[],int n)
{
    Min_heap_node *left,*right,*top;

    priority_queue<Min_heap_node*,vector<Min_heap_node*>,compare> minheap;

    for(int i=0;i<n;i++)
        minheap.push(new Min_heap_node(freq[i],data[i]));

    while(minheap.size()!=1){
        left=minheap.top();
        minheap.pop();

        right=minheap.top();
        minheap.pop();

        top=new Min_heap_node(left->frequency+right->frequency,'$');

        top->left=left;
        top->right=right;

        minheap.push(top);
    }
    print_code(minheap.top(),"");
}

int main()
{
    char data[]={'a','b','c','d','e','f'};
    int freq[]={5,9,12,13,16,45};

    int n=sizeof(data)/sizeof(data[0]);

    Huffman_codeing(data,freq,n);
}
