#include<iostream>
using namespace std;
int main()
{
	int n,ans=0,i=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;++i)
		cin>>a[i];
	if(n==2)	ans=1;
	else
	{
		if(a[0]>=a[1])
		{
			int i=1;
			while(i+1<n&&a[i]>=a[i+1])	i++;
			if(i==n-1)	ans=1;
			else
			{	if(i+2<n&&a[i+1]<=a[i+2])
					while(++i+1<n&&a[i]<=a[i+1]);
				else if(i+2<n&&a[i+1]>=a[i+2])
					while(++i+1<n&&a[i]>=a[i+1]);
				else ans=1;
				if(i==n-1)	ans=1;
			}
		}
		if(a[0]<=a[1])
		{
			int i=1;
			while(i+1<n&&a[i]<=a[i+1])	i++;
			if(i==n-1)	ans=1;
			else
			{	
				if(i+2<n&&a[i+1]<=a[i+2])
					while(++i+1<n&&a[i]<=a[i+1]);
				else if(i+2<n&&a[i+1]>=a[i+2])
					while(++i+1<n&&a[i]>=a[i+1]);
				else ans=1;
				if(i==n-1)	ans=1;
			}
		}
	}
	if(ans==1)	cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
