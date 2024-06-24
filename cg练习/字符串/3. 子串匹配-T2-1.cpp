#include<iostream>
using namespace std;
char s[10001],t[10001];
int main()
{
	cin>>s>>t;
	for(int i=0;s[i]!=0;++i)
	{
		int x=i,y=0;
		while(t[y]!=0&&s[x]==t[y])
		{
			x++;
			y++;
		}
		if(t[y]==0)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
