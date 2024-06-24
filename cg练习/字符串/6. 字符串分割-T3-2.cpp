#include<bits/stdc++.h>
using namespace std;
char s[101],t[101];
int main()
{
	cin.getline(s,101);
	cin.getline(t,101);
	for(int i=0;s[i]!=0;++i)
	{
		int x=i;
		while(t[x-i]!=0&&s[x]==t[x-i])
		{
			x++;
		}
		if(t[x-i]==0)
		{
			i=x-1;
			cout<<endl;
		}
		else cout<<s[i];
	}
	return 0;
}
