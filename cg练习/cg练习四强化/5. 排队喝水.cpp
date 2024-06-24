#include<iostream>
using namespace std;
int l[1001],r[1001],t[1001];
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;++i)
	{
		int n;
		cin>>n;
		int time=0;
		for(int j=1;j<=n;++j)
			cin>>l[j]>>r[j];
		for(int j=1;j<=n;++j)
		{
			if(time>r[j])
				t[j]=0;
			else if(time<l[j])	
			{
				time=l[j]+1;
				t[j]=time-1;
			}
			else 
			{
				time+=1;
				t[j]=time-1;
			}
		}
		for(int j=1;j<=n;++j)
			cout<<t[j]<<" ";
		cout<<'\n';
	}
	return 0;
}
