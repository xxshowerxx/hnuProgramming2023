#include<iostream>
using namespace std;
int main()
{
	int n;
	double a1,a2;
	cin>>n;
	a1=27+23+n/3.0;
	a2=n/1.2;
	if(a1<a2)cout<<"Bike"<<endl;
	else if(a1>a2)cout<<"Walk"<<endl;
	else cout<<"All"<<endl;
	return 0;
}
