#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int r[n+1],t[n+1];
	for(int i=1;i<=n;++i)
	{
		cin>>r[i];
		t[i]=0;
	}
	for(int i=1;i<=k;++i)
	{
		int x,y;
		cin>>x>>y;
		if(r[x]>r[y])	t[x]--;
		if(r[x]<r[y])	t[y]--;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
			if(r[i]>r[j])	t[i]++;
			else if(r[i]<r[j])	t[j]++;
	}
	for(int i=1;i<=n;++i)
		cout<<t[i]<<" ";
	return 0;
}
