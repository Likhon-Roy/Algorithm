#include<iostream>
#include<list>
using namespace std;
// this is my first program of hash_table;

class hash_table
{
    static const int hash_group=10;
    list<pair<int,string>>table[hash_group];
public:
    bool Is_empty() const;
    int hash_function(int key);
    void hash_insert(int key,string value);
    void hash_delete(int key);
    void display();
};

bool hash_table::Is_empty() const
{
    int sum{};
    for(int i{};i<hash_group;i++) sum+=table[i].size();
    if(!sum) return true;
    return false;
}

int hash_table::hash_function(int key)
{
    return key%hash_group;
}

void hash_table::hash_insert(int key,string value)
{
    int hash_value=hash_function(key);
    auto& cell=table[hash_value];
    auto it=begin(cell);
    bool key_exists=false;
    for(it;it!=end(cell);it++){
        if(it->first==key){
            key_exists=true;
            cout<<"[worning] key is already exists, value has been changed"<<endl;
            it->second=value;
            break;
        }
    }
    if(!key_exists) cell.emplace_back(key,value);
    return;
}

void hash_table:: hash_delete(int key)
{
    int hash_value=hash_function(key);
    auto& cell=table[hash_value];
    auto it=begin(cell);
    bool key_exists=false;
    for(it;it!=end(cell);it++){
        if(it->first==key){
            key_exists=true;
            cout<<"Item is deleted"<<endl;
            it=cell.erase(it);
            break;
        }
    }
    if(!key_exists) cout<<"[worning] item is not found"<<endl;
    return;
}

void hash_table:: display()
{
    for(int i{};i<hash_group;i++){
        if(table[i].size()==0) continue;
        for(auto it=table[i].begin();it!=table[i].end();it++){
            cout<<"key : "<<it->first<<"  value : "<<it->second<<endl;
        }
    }
    return;
}

int main()
{
    hash_table H;
    if(H.Is_empty()) cout<<"The table is empty, let's insert the value"<<endl;
    else cout<<"Oh oh, something is wrong, please chack your code"<<endl;

    H.hash_insert(5,"likhon");
    H.hash_insert(45,"chitra");
    H.hash_insert(6565,"manosi");
    H.hash_insert(259,"roy");
    H.hash_insert(78,"pallob");
    H.hash_insert(10,"kollan");
    H.hash_insert(369,"khokon");
    H.hash_insert(6,"raton");
    H.hash_insert(657,"rangon");
    H.hash_insert(251,"boiddo");
    H.hash_insert(985,"jojo");
    H.hash_insert(201,"kabir");
    H.hash_insert(213,"bahuboli");
    H.hash_insert(4,"monpura");
    H.hash_insert(254,"sunny");
    H.hash_insert(254,"leone");

    H.display();

    H.hash_delete(4);
    H.hash_delete(6);
    H.hash_delete(78);
    H.hash_delete(251);

    H.display();

    if(H.Is_empty())cout<<"[worning] something is wrong, table should not be empty"<<endl;
    else cout<<"your table is full. great job"<<endl;

}
