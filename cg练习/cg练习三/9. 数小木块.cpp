#include<iostream>
using namespace std;
int main()
{
	int n,a=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		a+=i;
		sum+=a;
	}
	cout<<sum<<endl;
	return 0;
}
