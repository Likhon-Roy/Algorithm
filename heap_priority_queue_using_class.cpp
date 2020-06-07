#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Max_heap
{
private:
    int _size=0;
    vector<int>vec ={-1};
    int p(int n) {return n/2;}
    int l(int n) {return n*2;}
    int r(int n) {return (n*2)+1;}
public:
    bool is_Empty(int s){
        //if(vec.size()==s+1) return true;
        return false;
    }
    void insert_node(int value);
    void shift_up(int i);
    void heap_print()
    {
        for(int i=1;i<=_size;i++) cout<<vec[i]<<" ";
        //for(auto it=vec.begin()+1;it!=vec.end();it++) cout<<*it<<" ";
    }
    void shift_down(int i);
    int extract_heap();

};

void Max_heap::shift_up(int i)
{
    if(i>_size) return;
    if(i==1) return;

    if(vec[p(i)]<vec[i]){
        swap(vec[p(i)],vec[i]);
    }
    shift_up(p(i));
}

void Max_heap::insert_node(int value)
{
    if(_size==0) vec[++_size]=value;
    else{
        vec[++_size]=value;
        shift_up(_size);
    }
}

void Max_heap::shift_down(int i)
{
    int large;

    if(l(i)<_size && vec[i]<vec[l(i)]) large=l(i);
    else large=i;
    if(r(i)<_size && vec[large]<vec[r(i)]) large=r(i);

    if(large!=i){
        swap(vec[i],vec[large]);

        shift_down(large);
    }
}

int Max_heap:: extract_heap()
{
    int temp=vec[1];
    vec[1]=vec[_size];
    _size--;

    shift_down(1);

    return temp;
}

int main()
{
    Max_heap* H=new Max_heap();

    H->insert_node(12);
    H->insert_node(7);
    H->insert_node(1);
    H->insert_node(3);
    H->insert_node(10);
    H->insert_node(17);
    H->insert_node(19);
    H->insert_node(2);
    H->insert_node(5);

    H->heap_print();


    int item=H->extract_heap();
    cout<<endl<<item<<endl;
    H->heap_print();
    cout<<endl;

    H->extract_heap();
    H->extract_heap();
    H->extract_heap();
    H->heap_print();
}
