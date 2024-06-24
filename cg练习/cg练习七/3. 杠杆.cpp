#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;++i)
	{
		string s;
		int lweight=0,rweight=0,point;
		cin>>s;
		point=s.find('^');
		for(int j=0;j<point;++j)
		{
			if(s[j]!='=')
			{
				lweight+=(s[j]-'0')*(point-j);
			}
		}
		for(int j=point+1;j<(int)s.length();++j)
		{
			if(s[j]!='=')
			{
				rweight+=(s[j]-'0')*(j-point);
			}
		}
		if(lweight==rweight)cout<<"balance"<<endl;
		else if(lweight>rweight)cout<<"left"<<endl;
		else cout<<"right"<<endl;
	}
	return 0;
}
