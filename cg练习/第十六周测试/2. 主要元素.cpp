#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
	int n,t;
	cin>>n;
	for(int i=0;i<n;++i)
	{	
		cin>>t;
		a[t]++;
	}
	for(int i=0;i<10000;++i)
	{
		if(a[i]>n*0.5)	cout<<i<<endl;
	}
	return 0;
}

