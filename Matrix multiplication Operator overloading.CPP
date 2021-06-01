///Write a program to perform multiplication of two matrix using
///operator overloading

#include<iostream>

using namespace std;

class Matrix
{
    int a[50][50],m,n;
public:
    void input_matrices();
    void output_matrices();
    Matrix operator*(Matrix x);
};

void Matrix::input_matrices()
{
    cout<<"Enter matrix row number: ";
    cin>>m;
    cout<<"Enter matrix column number: ";
    cin>>n;
    for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	    cin>>a[i][j];
	}
    }
}

void Matrix::output_matrices()
{
    for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	    cout<<a[i][j]<<"    ";
	}
	cout<<endl;
    }
}

Matrix Matrix::operator*(Matrix x)
{
    Matrix c;
    int i,j,k;
    if(n==x.m){
	c.m=m;
	c.n=x.n;
	for(i=0;i<m;i++){
	    for(j=0;j<x.n;j++){
		c.a[i][j]=0;
		for(k=0;k<m;k++){
		    c.a[i][j]+=a[i][k]*x.a[k][j];
		}
	    }
	}
	return c;
    }
    else{
	cout<<"Multiplication is not possible"<<endl;
    }
}



int main()
{
    Matrix x,y,z;
    cout<<"Enter first matrix"<<endl;
    x.input_matrices();
    x.output_matrices();
    cout<<"Enter second matrix"<<endl;
    y.input_matrices();
    y.output_matrices();

    z=x*y;
    cout<<"The result is: "<<endl;
    z.output_matrices();

    return 0;
}
