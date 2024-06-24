#include<bits/stdc++.h>
using namespace std;
char y[6]={'a','o','u','i','e','n'};
int main()
{
	string s;
	int flag=0;
	cin>>s;
	for(int i=0;i<(int)s.length();++i)
	{
		int j;
		for(j=0;j<6;++j)
		{
			if(s[i]==y[j])	break;
		}
		if(j==6)
		{
			if(i==(int)s.length()-1) flag=1;
			else
			{
				i++;
				int t;
				for(t=0;t<5;++t)
				{
					if(s[i]==y[t])
						break;
				}
				if(t==5)
				{
					flag=1;
					break;
				}
			}
		}
	}
	if(flag==1)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}
