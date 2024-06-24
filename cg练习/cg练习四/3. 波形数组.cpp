#include<iostream>
using namespace std;
int main()
{
	int n,t,a[1001],b[1001];
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n;
		int flag=0;
		for(int j=1;j<=n;++j)
			cin>>a[j];
		for(int j=1;j<=n-1;++j)
			if(a[j]>a[j+1])	b[j]=1;
			else if(a[j]==a[j+1])b[j]=0;
			else b[j]=-1;
		for(int j=1;j<=n-2;++j)
			if(b[j]==b[j+1]||b[j]==0||b[j+1]==0)
			{
				flag=1;
				break;
			}
		if(flag==1)	cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
