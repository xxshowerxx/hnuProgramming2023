#include<iostream>
using namespace std; 
class matrix
{
	public:
		matrix();
		matrix(int m,int n);
		matrix(const matrix& A,int m,int n);
		~matrix();
		
		int **p,row,col;
		matrix multi(int x);
		matrix operator+(const matrix& another);
		matrix operator*(const matrix& another);
		void out();
		void in();
		int det();
};
matrix::matrix(int m,int n)
{
	row=m,col=n;
	p=new int *[row];
	for(int i=0;i<row;++i)
	{
		p[i]=new int[col];
	}
}
matrix::matrix(const matrix& A,int m,int n)
{
	row=A.row-1,col=A.col-1;
	p=new int *[row];
	for(int i=0;i<row;++i)
	{
		p[i]=new int[col];
	}
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			p[i][j]=A.p[i][j];
	for(int i=m+1;i<row+1;++i)
		for(int j=0;j<n;++j)
			p[i-1][j]=A.p[i][j];
	for(int i=m+1;i<row+1;++i)
		for(int j=n+1;j<col+1;++j)
			p[i-1][j-1]=A.p[i][j];
	for(int i=0;i<m;++i)
		for(int j=n+1;j<col+1;++j)
			p[i][j-1]=A.p[i][j];
}
matrix::~matrix()
{
	for(int i=0;i<row;++i)
		delete[] p[i];
	delete[] p;
}
matrix matrix::multi(int x)
{
	matrix tmp(row,col);
	for(int i=0;i<row;++i)
		for(int j=0;j<col;++j)
		{
			tmp.p[i][j]=p[i][j]*x;
		}
	return tmp;
}
void matrix::in()
{
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col;++j)
			cin>>p[i][j];
	}
}
void matrix::out()
{
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col;++j)
			cout<<p[i][j]<<" ";
		cout<<endl;
	}
}
matrix matrix::operator+(const matrix& another)
{
	matrix tmp(row,col);
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col;++j)
			tmp.p[i][j]=p[i][j]+another.p[i][j];
	}
	return tmp;
};
matrix matrix::operator*(const matrix& another)
{
	matrix tmp(row,another.col);
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<another.col;++j)
		{
			tmp.p[i][j]=0;
			for(int k=0;k<col;++k)
				tmp.p[i][j]+=p[i][k]*another.p[k][j];
		}
	}
	return tmp;
};
int matrix::det()
{
	if(row==1)
		return p[0][0];
	else
	{
		int result=0,flag;
		for(int i=0;i<col;++i)
		{
			flag=(i%2)?-1:1;
			matrix tmp(*this,0,i);
			result+=flag*p[0][i]*tmp.det();
		}
		return result;
	}
}
int main()
{
	int m,n,x,k,l;
	cin>>m>>n;
	matrix A(m,n);
	A.in();
	cin>>x;
	matrix m1=A.multi(x);
	m1.out();
	cin>>k>>l;
	matrix B(k,l);
	B.in();
	if(m==k&&n==l)
	{
		matrix m2=A+B;
		m2.out();
	}
	if(n==k)
	{
		matrix m3=A*B;
		m3.out();
	}
	if(m==n)
		cout<<A.det()<<endl;
	if(k==l)
		cout<<B.det()<<endl;
	return 0;
}
