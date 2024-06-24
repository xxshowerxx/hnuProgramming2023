#include<bits/stdc++.h>
using namespace std;
char s[10001];
int type(int t)
{
	if(t>='0'&&t<='9')return 1;
	else if(t>='a'&&t<='z')return 2;
	else if(t>='A'&&t<='Z')return 3;
	else return 4;
}
int main()
{
	cin.getline(s,10001);
	int first=0,t=1;
	for(int i=1;s[i]!=0;++i)
	{
		if(type(s[i])==type(s[first]))
		{
			t++;
		}
		else
		{
			if(t>1)	sort(s+first,s+first+t);
			t=1,first=i;
		}
	}
	if(t>1)	sort(s+first,s+first+t);
	cout<<s<<endl;
	return 0;
}
