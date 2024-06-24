#include<bits/stdc++.h>
using namespace std;
int s[101];
int main()
{
	string a;
	cin>>a;
	int j=0,sum=0;
	for(int i=0;i<(int)a.size();++i)
	{
		while((a[i]>'9'||a[i]<'0')&&a[i]!=0)	i++;
		if(a[i]!=0)
		{
			while(a[i]<='9'&&a[i]>='0')
				s[j]=s[j]*10+a[i++]-'0';
			j++;
		}
	}
	for(int i=0;i<j;++i)
		sum+=s[i];
	cout<<sum<<endl;
	return 0;
}
