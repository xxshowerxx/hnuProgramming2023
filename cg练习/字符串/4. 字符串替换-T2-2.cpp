#include<bits/stdc++.h>
using namespace std;
char s[101],old_str[101],new_str[101],ns[202];
int main()
{
	cin.getline(s,101);
	cin.getline(old_str,101);
	cin.getline(new_str,101);
	int t=0;
	for(int i=0;s[i]!=0;++i)
	{
		int x=i,y=0;
		while(old_str[y]!=0&&s[x]==old_str[y])
		{
			x++;
			y++;
		}
		if(old_str[y]==0)
		{
			int j=0;
			while(new_str[j]!=0)
				ns[t++]=new_str[j++];
			i=x-1;
		}
		else
		{
			ns[t++]=s[i];
		}
	}
	cout<<ns<<endl;
	return 0;
}
