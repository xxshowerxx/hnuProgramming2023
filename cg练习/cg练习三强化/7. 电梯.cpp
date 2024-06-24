#include<iostream>
using namespace std;
int main()
{
	int n,t=0,time=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]>t)	time+=6*(a[i]-t);
		else time+=4*(t-a[i]);
		time+=5;
		t=a[i];
	}
	cout<<time<<endl;
	return 0;
}
