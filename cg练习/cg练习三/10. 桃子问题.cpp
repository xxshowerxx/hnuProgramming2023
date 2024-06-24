#include<iostream>
using namespace std;
int main()
{
	int n,sum=1;
	cin>>n;
	for(int i=n-1;i>=1;--i)
	{
		sum=(sum+1)*2;
	}
	cout<<sum<<endl;
	return 0;
}
