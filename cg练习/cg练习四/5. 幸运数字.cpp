#include<iostream>
using namespace std;
int main()
{
	int n,sum=0;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]%4==0||a[i]%7==0)
			sum+=a[i];
	}
	cout<<sum<<endl;
	return 0;
}
