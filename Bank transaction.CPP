///Write a program to perform bank transaction.


#include<iostream>

using namespace std;

class Bank
{
    int Accno;
    string AccName;
    char AccType;
    float BalanceAmt;

public:
    void get_account_details()
    {
	cout<<"Please Enter account details "<<endl;
	cout<<"Account Number: ";
	cin>>Accno;
	cout<<"Account Holder Name: ";
	cin>>AccName;
	cout<<"Account Type(c/s): ";
	cin>>AccType;
	cout<<"Balance Amount: ";
	cin>>BalanceAmt;
    }

    void print_account_details()
    {
	cout<<"Account Holder Details..."<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"Account Number: "<<Accno<<endl;
	cout<<"Name: "<<AccName<<endl;
	cout<<"Account Type: "<<AccType<<endl;
	cout<<"Balance Amount: "<<BalanceAmt<<endl;
	cout<<"-------------------------"<<endl;
    }

    void do_transaction()
    {

	char type;
	float tamt;
	cout<<"Transaction process"<<endl;
	cout<<"-------------------"<<endl;
	cout<<"Get Transacion Amount: ";
	cin>>tamt;
	cout<<"Get Transaction type(w=withdrawl, d=deposit): ";
	cin>>type;
	if(type=='w'|| type=='W'){
	    if(BalanceAmt-tamt>0){
		BalanceAmt=BalanceAmt-tamt;
		cout<<"Transaction Completed";
		cout<<"Your current balance is "<<BalanceAmt<<endl;
	    }
	    else{
		cout<<"Sorry ! Insufficient found in your account"<<endl;
	    }
	}
	else if(type=='D'||type=='d'){
	    BalanceAmt+=tamt;
	    cout<<"Your current Balance is "<<BalanceAmt<<endl;
	}
    }
};
int main()
{
    Bank b;

    b.get_account_details();
    cout<<"---------------------"<<endl;
    cout<<"Account details before transaction"<<endl;
    b.print_account_details();

    b.do_transaction();
    cout<<"---------------------"<<endl;
    cout<<"Account details after transaction"<<endl;
    b.print_account_details();

    return 0;
}
