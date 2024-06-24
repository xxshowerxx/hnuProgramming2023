#include<iostream>
using namespace std;
//¸´ÊýÀà
class intMyComplex
{
	public:
	friend istream& operator>>(istream&,intMyComplex&);
	friend ostream& operator<<(ostream&,intMyComplex&);
	intMyComplex& operator+(intMyComplex&other)
	{
		real+=other.real;
		imag+=other.imag;
		return *this;
	}
	private:
	int  real;
	int  imag;
};

//²¹³ä´úÂë
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
	b=a+b;
	cout<<b;
	return 0;
}

