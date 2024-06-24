#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *cnt=new int[200005];
	int *b=new int[600005];
	for(int i=0;i<=600000;++i)
		b[i]=0;
	for(int i=1;i<=n;++i)
	{
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;++j)
			b[j]++;
	}
	for(int i=0;i<=600000;++i)
		cnt[b[i]]++;
	for(int i=1;i<=n;++i)
		cout<<cnt[i]<<" ";
	return 0;
}
