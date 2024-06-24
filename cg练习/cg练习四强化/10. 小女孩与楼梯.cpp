#include<iostream>
using namespace std;
int a[10001],b[10001];
int main()
{
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			b[cnt]=a[i-1];
			cnt++;
		}
	}
	b[cnt]=a[n];
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;++i)
		cout<<b[i]<<" ";
	return 0;
}
