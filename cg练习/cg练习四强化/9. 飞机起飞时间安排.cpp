#include<iostream>
using namespace std;
int h[100],m[100],t[100];
int main()
{
	int n,s;
	cin>>n>>s;
	for(int i=0; i<n; ++i)
	{
		cin>>h[i]>>m[i];
	}
	for(int i=0; i<n+1; ++i)
	{
		int ti,hi,mi;
		if(i==0||i==n)	ti=(h[0]-h[n-1]+24)*60+m[0]-m[n-1];
		else ti=(h[i]-h[i-1])*60+m[i]-m[i-1];
		if(ti>=2*s+2)
		{
			if(i-1>=0)
			{
				mi=m[i-1]+s+1;
				hi=h[i-1];
			}
			else
			{
				mi=m[n-1]+s+1;
				hi=h[n-1];
			}
			while(mi>=60)
			{
				mi-=60;
				hi+=1;
			}
			if(hi>=24)	hi-=24;
			else if(hi<24&&i==0)	continue;
			cout<<hi<<" "<<mi<<endl;
			return 0;
		}
	}
	//尝试使用取余的方法成环，然后发现负数除以正数的余数是负数...... 
	return 0;
}
