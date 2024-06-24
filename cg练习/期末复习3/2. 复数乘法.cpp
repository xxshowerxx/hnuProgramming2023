#include<iostream>
using namespace std;
//������
class intMyComplex
{
	public:
	friend istream& operator>>(istream&,intMyComplex&);
	friend ostream& operator<<(ostream&,intMyComplex&);
	intMyComplex operator*(intMyComplex&other)
	{
		intMyComplex tmp;
		tmp.real=real*other.real-imag*other.imag;
		tmp.imag=imag*other.real+real*other.imag;
		return tmp;
	}
	private:
	int  real;
	int  imag;
};

//�������
istream& operator>>(istream& in,intMyComplex& c)
{
	in>>c.real>>c.imag;
	return in;
}
ostream& operator<<(ostream& out,intMyComplex& c)
{
	out<<c.real<<'+'<<c.imag<<'i';
	return out;
}
int    main()
{
	intMyComplex a,b;
	cin>>a;
	cin>>b;
	b=a*b;
	cout<<b;
	return 0;
}

