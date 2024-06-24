#include<iostream>
using namespace std;
int main()
{
	int s,k,t,sum;
	cin>>s>>k;
	t=s-5000-k;
	if(t<0)sum=0;
	else if(t<=3000)sum=t*0.03;
	else if(t<=12000)sum=t*0.1-210;
	else if(t<=25000)sum=t*0.2-1410;
	else if(t<=35000)sum=t*0.25-2660;
	else if(t<=55000)sum=t*0.3-4410;
	else if(t<=80000)sum=t*0.35-7160;
	else sum=t*0.45-15160;
	cout<<sum<<endl;
	return 0;
}
