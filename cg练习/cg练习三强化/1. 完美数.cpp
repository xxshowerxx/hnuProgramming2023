#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,sum=1;
	cin>>n;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0&&i!=n/i)sum+=i+n/i;
		if(n%i==0&&i==n/i)	sum+=i;
	}
	if(sum==n)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
