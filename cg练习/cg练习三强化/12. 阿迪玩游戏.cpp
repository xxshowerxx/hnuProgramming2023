#include<iostream>
using namespace std;
int main()
{
	int n,m,t=1,direction=1;
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		int a;
		cin>>a;
		while(t+direction*a>n||t+direction*a<1)
		{
			if(t+direction*a>n)
			{
				a-=n-t;
				t=n;
				direction=-1;
			}
			else
			{
				a-=t-1;
				t=1;
				direction=1;
			}
		}
		t+=direction*a;
	}
	cout<<t<<endl;
	return 0;
}
