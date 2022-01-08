#include<iostream>
#include<list>
using namespace std;
class Hash
{
    static const int table_size=10;
    struct item
    {
        string name;
        string drink;
        item* next;
    };
    item* hash_table[table_size];

public:
    Hash();
    int hash_function(string key);
    void Add_item(string name,string drink);
    int number_of_item(int index);
    void print_table();
    void print_all();


};
Hash::Hash()
{
    for(int i=0;i<table_size;i++){
        hash_table[i]=new item;
        hash_table[i]->name="empty";
        hash_table[i]->drink="empty";
        hash_table[i]->next=NULL;
    }
}

int Hash::hash_function(string key)
{
    int index,h=0;
    index=key.length();

    for(int i=0;i<key.length();i++){
        h+=(int)key[i];
    }
    return h%table_size;
}
void Hash:: Add_item(string name,string drink)
{
    int index=hash_function(name);
    if(hash_table[index]->name=="empty"){
        hash_table[index]->name=name;
        hash_table[index]->drink=drink;
        //hash_table[index]->next=NULL;
    }
    else{
        item* n=new item;
        item* ptr=hash_table[index];
        n->name=name;
        n->drink=drink;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=n;
    }
}

int Hash::number_of_item(int index)
{
    int countt{};
    if(hash_table[index]->name=="empty") return countt;
    else{
        item* ptr=hash_table[index];
        while(ptr->next!=NULL){
            countt++;
            ptr=ptr->next;
        }
    }
    return countt;
}
void Hash::print_table()
{
    int number;
    for(int i=0;i<table_size;i++){
        number=number_of_item(i);
        cout<<"----------\n";
        cout<<"index "<<i<<endl;
        cout<<hash_table[i]->name<<endl;
        cout<<hash_table[i]->drink<<endl;
        cout<<"# of item "<<number<<endl;
        cout<<"----------\n";
    }
}
void Hash::print_all()
{
    item* ptr;
    cout<<"printing all value*************"<<endl;
    for(int i=0;i<table_size;i++){
        if(hash_table[i]->name=="empty") continue;
        ptr=hash_table[i];
        while(ptr!=NULL){
            cout<<ptr->name<<"   "<<ptr->drink<<endl;
            ptr=ptr->next;
        }
    }
}

int main()
{
    Hash H;

    H.Add_item("likhon","cocola");
    H.Add_item("ikhonl","rc");
    H.Add_item("chitra","coffee");
    H.Add_item("kobit","tea");
    H.Add_item("mishi","whiski");
    H.Add_item("sotrugno","bear");
    H.Add_item("chtrai","cold coffee");
    H.Add_item("ram","mild with water");
    H.Add_item("lokhon","juss and sweets");
    H.Add_item("vorot","rakhij");
    H.Add_item("iuif","seven up");

    H.print_table();
    H.print_all();
}
