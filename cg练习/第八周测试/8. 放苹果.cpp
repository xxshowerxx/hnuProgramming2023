#include<bits/stdc++.h>
using namespace std;
int apple(int m,int n,int t)
{
	if(n==0&&m==0)return 1;
	if(t>m)	return 0;
	if(n==0&&m!=0)return 0;
	int s=0;
	for(int i=t;i<=m;++i)
	{
		s+=apple(m-i,n-1,i);
	}
	return s;
}
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<apple(m,n,0);
	return 0;
}
