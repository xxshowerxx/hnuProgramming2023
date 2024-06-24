#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a;
	double b;
	cin>>a>>b;
	cout<<setfill('0')<<setw(8)<<a<<endl;
	cout<<fixed<<setprecision(2)<<b<<endl;
	return 0;
}
