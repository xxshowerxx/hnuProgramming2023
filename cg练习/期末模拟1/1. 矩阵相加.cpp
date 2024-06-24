#include  <iostream>
using  namespace  std;
class  Matrix
{
	public:
	friend istream& operator>>(istream&in,Matrix&x);
	friend ostream& operator<<(ostream&in,Matrix&x);
	Matrix operator+(const Matrix&x)
	{
		Matrix tmp;
		for(int i=0;i<2;++i)
		{
			for(int j=0;j<3;++j)
				tmp.mat[i][j]=this->mat[i][j]+x.mat[i][j];
		}
		return tmp;
	}
	private:
		int  mat[2][3];
};
istream& operator>>(istream&in,Matrix&x)
{
	for(int i=0;i<2;++i)
	{
		for(int j=0;j<3;++j)
			cin>>x.mat[i][j];
	}
}
ostream& operator<<(ostream&in,Matrix&x)
{
	for(int i=0;i<2;++i)
	{
		for(int j=0;j<3;++j)
			cout<<x.mat[i][j]<<" ";
		cout<<endl;
	}
}

int  main()
{
	Matrix  a,  b,  c;
	cin  >>  a  >>  b;
	c=a+b;
	cout<<c;
	return  0;
}

