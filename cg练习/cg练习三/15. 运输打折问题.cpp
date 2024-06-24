#include<iostream>
using namespace std;
int main()
{
	int s,t;
	double sum=0,discount;
	cin>>t>>s;
	if(s<250)
		discount=1;
	else if(s<500)
		discount=0.98;
	else if(s<1000)
		discount=0.95;
	else if(s<2000)
		discount=0.92;
	else if(s<3000)
		discount=0.9;
	else
		discount=0.85;
	sum=s*t*discount;
	cout<<(int)sum<<endl;
	return 0;
 } 
