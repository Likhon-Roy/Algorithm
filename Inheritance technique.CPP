///Write a program to create a student report using inheritance technique


#include<iostream>

using namespace std;

class Student
{
    int roll;
    string name;
    string address;
    string city;

public:
    student()
    {
	cout<<"Welcome to the student information system "<<endl<<endl;
    }
    void getdata()
    {
	cout<<"Enter student roll num: "<<endl;
	cin>>roll;
	cout<<"Enter student name: "<<endl;
	cin>>name;
	cout<<"Enter student address: "<<endl;
	cin>>address;
	cout<<"Enter student city: "<<endl;
	cin>>city;
    }
    void putdata()
    {
	cout<<"Student roll num : "<<roll<<endl;
	cout<<"Student name : "<<name<<endl;
	cout<<"Student address : "<<address<<endl;
	cout<<"Student city : "<<city<<endl;
    }
};

class Marks:public Student
{
    int sub1,sub2,sub3,per;

public:
    void input()
    {
	getdata();
	cout<<endl<<"Enter the marks1 : ";
	cin>>sub1;
	cout<<endl<<"Enter the marks2 : ";
	cin>>sub2;
	cout<<endl<<"Enter the marks3 : ";
	cin>>sub3;
    }

    void output()
    {
	cout<<"Student detais "<<endl;
	putdata();
	cout<<"Marks1 : "<<sub1<<endl;
	cout<<"Marks2 : "<<sub2<<endl;
	cout<<"Marks3 : "<<sub3<<endl;
    }
    void calculate()
    {
	per=(sub1+sub2+sub3)/3;
	cout<<endl<<"Total percentage : "<<per;
	if(per>=85){
	    cout<<"Grade A+ "<<endl;
	}
	else if(per>=60){
	    cout<<"Grade A"<<endl;
	}
	else if(per>=50){
	    cout<<"Grade B"<<endl;
	}
	else{
	    cout<<"Grade C"<<endl;
	}
    }

};




int main()
{
    Marks m;
    m.input();
    m.output();
    m.calculate();
    return 0;
}
