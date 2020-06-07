#include<iostream>
using namespace std;

int left_child(int n)
{
    return n*2;
}
int right_child(int n)
{
    return (n*2)+1;
}
int parent(int n)
{
    return n/2;
}

int is_max_heap(int A[],int heap_size)
{
    int p;
    for(int i=heap_size;i>1;i--){
        p=parent(i);
        cout<<"i = "<<i<<", p = "<<p<<"\tA[i] = "<<A[i]<<", A[p] = "<<A[p]<<endl;
        if(A[p]<A[i]) return 0;
    }
    return 1;
}

void Max_heapify(int heap[],int _size,int i)
{
    int l,r,large,temp;
    l=left_child(i);
    r=right_child(i);
    if(l<=_size && heap[l]>heap[i]) large=l;
    else large=i;
    if(r<=_size && heap[r]>heap[large]) large=r;

    if(large!=i){
        temp=heap[i];
        heap[i]=heap[large];
        heap[large]=temp;

        Max_heapify(heap,_size,large);
    }
}

void built_max_heap(int heap[],int _size)
{
    for(int i=_size/2;i>=1;i--){
        Max_heapify(heap,_size,i);
    }
}
//function for queue sort
void heap_sort(int heap[],int _size)
{
    int temp;
    for(int i=_size;i>1;i--){
        temp=heap[i];
        heap[i]=heap[1];
        heap[1]=temp;

        _size--;

        Max_heapify(heap,_size,1);
    }
}

//function for priority queue
int extract_max(int heap[],int _size)
{
    int temp;
    temp=heap[1];
    heap[1]=heap[_size];
    //heap[_size]=temp;

    _size--;

    Max_heapify(heap,_size,1);

    return temp;
}

//function for insert in heapp or priority queue

int insert_node(int heap[],int _size,int item)
{
    int i,temp;
    _size++;
    heap[_size]=item;
    i=_size;
    while(i>1 && heap[parent(i)]<heap[i]){
        temp=heap[parent(i)];
        heap[parent(i)]=heap[i];
        heap[i]=temp;

        i=parent(i);
    }

    return _size;
}

int main()
{
    int n=12;
    int A[n+1]={0,99,2,1,4,0,44,235,64,23,6,3,25};

    if(is_max_heap(A,n)) cout<<"max heap"<<endl;
    else{
        cout<<"not max heap"<<endl;
        built_max_heap(A,n);
    }

    for(int i=1;i<=n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    int item=extract_max(A,n);
    cout<<endl<<item<<endl;

    n--;
    for(int i=1;i<=n;i++){
        cout<<A[i]<<" ";
    }

    n=insert_node(A,n,100);
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<A[i]<<" ";
    }

    cout<<endl;
    heap_sort(A,12);
    for(int i=1;i<=12;i++){
        cout<<A[i]<<" ";
    }
}
