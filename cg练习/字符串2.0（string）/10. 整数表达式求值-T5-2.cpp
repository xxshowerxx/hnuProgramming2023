#include<bits/stdc++.h>
using namespace std;
char s[101];
int t[101],sig[101];
int main()
{
	int ans=0,cnt=0;
	cin>>s;
	sig[0]=1;
	for(int i=0;s[i]!=0;++i)
	{
		while(s[i]<='9'&&s[i]>='0')
		{
			t[cnt]=t[cnt]*10+s[i]-'0';
			i++;
		}
		cnt++;
		if(s[i]=='+')sig[cnt]=1;
		else if(s[i]=='-')sig[cnt]=-1;
	}
	for(int i=0;i<cnt;++i)
		ans+=sig[i]*t[i];
	cout<<ans<<endl;
	return 0;
}
