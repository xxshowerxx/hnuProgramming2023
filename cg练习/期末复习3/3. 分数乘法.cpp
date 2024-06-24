#include<iostream>
using namespace std;
//整型向量类
class myfraction
{
	public:
		friend istream& operator>>(istream&,myfraction&);
		friend ostream& operator<<(ostream&,myfraction&);
		myfraction& operator*(myfraction& other)
		{
			numerator*=other.numerator;
			denominator*=other.denominator;
			return *this;
		}
	private:
		int  numerator;
		int  denominator;
};
istream& operator>>(istream& in,myfraction& f)
{
	in>>f.numerator>>f.denominator;
	return in;
}
ostream& operator<<(ostream& out,myfraction& f)
{
	out<<f.numerator<<'/'<<f.denominator;
	return out;
}
int main()
{
	myfraction  a,  b,  c;
	cin>>a>>b;
	c=a*b;
	cout<<c;
	return 0;
}


//补充代码



