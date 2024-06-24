#include<bits/stdc++.h>
using namespace std;
char s[101];
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;++i)
	{
		int n,st=0,ts=0;
		cin>>n>>s;
		for(int j=0;j<n-1;++j)
		{
			if(s[j]=='T'&&s[j+1]=='S') ts++;
			if(s[j]=='S'&&s[j+1]=='T') st++;
		}
		if(st>ts)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
