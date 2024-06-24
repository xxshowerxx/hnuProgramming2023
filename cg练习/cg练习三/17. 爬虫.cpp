#include<iostream>
using namespace std;
int main()
{
	int n,u,d,s[101],t=0;
	while(cin>>n>>u>>d,n!=0)
	{
		t++;
		s[t]=1;
		if(n>u&&(n-u)%(u-d)==0) s[t]+=(n-u)/(u-d)*2;
		if(n>u&&(n-u)%(u-d)!=0) s[t]+=(n-u)/(u-d)*2+2;
	}
	for(int i=1;i<=t;++i)
		cout<<s[i]<<'\n'; 
	return 0;
 } 
