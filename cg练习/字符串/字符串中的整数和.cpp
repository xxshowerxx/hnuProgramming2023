#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	cin>>a;
	long long c=0, sum=0;
	for(int i=0;i<=a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		  c=c*10+(a[i]-'0');
		else
		{
			sum+=c;
			c=0;
		}
	}
	cout<<sum<<endl;
	return 0;
} 
