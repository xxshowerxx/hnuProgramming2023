#include<iostream>
using namespace std;
int main()
{
	int n,day=0;
	cin>>n;
	int s[n+1],d[n+1];
	for(int i=1;i<=n;++i)
		cin>>s[i]>>d[i];
	for(int i=1;i<=n;++i)
	{
		if(day<=s[i])
		{
			day=s[i];
		}
		else
		{
			day+=d[i]-(day-s[i])%d[i];
		}
	}
	cout<<day<<endl;
	return 0;
}
