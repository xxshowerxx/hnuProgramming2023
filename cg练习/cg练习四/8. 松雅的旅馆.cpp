#include<iostream>
using namespace std;
int main()
{
	int n,d,num=0;
	cin>>n>>d;
	int x[n+1];
	for(int i=1;i<=n;++i)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n-1;++i)
	{
		if(x[i+1]-x[i]==2*d)	num++;
		else if(x[i+1]-x[i]>2*d)	num+=2;
	}
	num+=2;
	cout<<num<<endl;
	return 0;
}
