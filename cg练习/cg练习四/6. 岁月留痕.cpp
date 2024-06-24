#include<iostream>
using namespace std;
int main()
{
	int n;
	bool ans=0;
	cin>>n;
	int a[n],b[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(int i=0;i<12;++i)
	{
		int j;
		for(j=0;j<n;++j)
		{
			if(a[j]==29)
			{
				if(j-12>=0&&a[j-12]==28) continue;
				if(j+12<n&&a[j+12]==28)	continue;
				if(j-12<0&&j+12>=n)	continue;
			}
			if(a[j]!=b[(i+j)%12])
				break;
		}
		if(j==n)	ans=1;
	}
	if(ans==1)	cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
