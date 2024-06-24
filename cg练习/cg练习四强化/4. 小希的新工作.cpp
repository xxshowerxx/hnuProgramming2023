#include<iostream>
using namespace std;
int t[10001],l[10001];
int main()
{
	int n,L,a,k=0;
	cin>>n>>L>>a;
	for(int i=1;i<=n;++i)
	{
		cin>>t[i]>>l[i];
	}
	for(int i=1;i<=n-1;++i)
	{
		k+=(t[i+1]-t[i]-l[i])/a;
	}
	k+=(L-t[n]-l[n])/a+t[1]/a;
	cout<<k<<endl;
	return 0;
}
