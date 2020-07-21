#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left,*right;
};

struct compare
{
    bool operator()(Node *l,Node *r)
    {
        return l->freq > r->freq;
    }
};

Node* Getnode(char ch,int freq,Node *left,Node *right)
{
    Node *n=new Node();
    n->ch=ch;
    n->freq=freq;
    n->left=left;
    n->right=right;

    return n;
}

void Encode(Node *root,string str,unordered_map<char,string> &huffman)
{
    if(!root) return;

    if(!root->left && !root->right)
        huffman[root->ch]=str;

    Encode(root->left,str+"0",huffman);
    Encode(root->right,str+"1",huffman);

}

void Decode(Node *root,int &position, string str)
{
    if(!root) return ;
    if(!root->left && !root->right){
        cout<<root->ch;
        return;
    }
    position++;
    if(str[position]=='0')
        Decode(root->left,position,str);
    else
        Decode(root->right,position,str);
}

void Huffman_code(string text)
{
    unordered_map<char,int> freq;
    for(char ch:text) freq[ch]++;

    priority_queue<Node*,vector<Node*>,compare> pq;
    for(auto f:freq) pq.push(Getnode(f.first,f.second,nullptr,nullptr));

    while(pq.size()!=1){
        Node *left=pq.top(); pq.pop();
        Node *right=pq.top(); pq.pop();

        pq.push(Getnode('\0',left->freq+right->freq,left,right));
    }
    Node *root=pq.top();

    unordered_map<char,string> huffman;
    Encode(root,"",huffman);

    for(auto h:huffman) cout<<h.first<<" : "<<h.second<<endl;
    cout<<"Print the huffman code......"<<endl<<endl<<endl;
    string str="";
    for(char ch:text)str+=huffman[ch];
    cout<<str<<endl<<endl<<endl<<"print the decode of huffman code......."<<endl<<endl<<endl;

    int position=-1;
    while(position<(int)str.size()-2){
        Decode(root,position,str);
    }
    cout<<endl<<endl;


}


int main()
{
    string str="This is likhon roy, and i am the writer of the code";

    Huffman_code(str);
}
