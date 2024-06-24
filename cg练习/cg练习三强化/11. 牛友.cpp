#include<iostream>
#include<cmath>
using namespace std;
int sumFactor(int x)
{
	int sum=1;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0&&i!=x/i)	sum+=i+x/i;
		if(x%i==0&&i==x/i)	sum+=i;
	}
	return sum;
}
int main()
{
	int s;
	cin>>s;
	while(1)
	{
		if(s==sumFactor(sumFactor(s))&&sumFactor(s)!=s)
		{
			cout<<s<<" "<<sumFactor(s)<<endl;
			break;
		}
		s++;
	}
	return 0;
}
