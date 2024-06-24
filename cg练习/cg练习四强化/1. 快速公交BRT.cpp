#include<iostream>
using namespace std;
int main()
{
	int n,g,r,q;
	cin>>n>>g>>r;
	int t[n+2];
	for(int i=1;i<=n+1;++i)
		cin>>t[i];
	cin>>q;
	int begin[q+1];
	for(int i=1;i<=q;++i)
		cin>>begin[i];
	for(int i=1;i<=q;++i)
	{
		for(int j=1;j<=n;++j)
		{
			begin[i]+=t[j];
			if(begin[i]%(g+r)>=g)	begin[i]+=g+r-begin[i]%(g+r);
		}
		begin[i]+=t[n+1];
		cout<<begin[i]<<" ";
	}
	return 0;
}
