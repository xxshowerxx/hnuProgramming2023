#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double f,c;
	cin>>f;
	c=5.0*(f-32)/9.0;
	cout<<fixed<<setprecision(5)<<c<<endl;
	return 0;
}
