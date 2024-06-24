#include<iostream>
#include<algorithm>
using namespace std;
struct zuobiao
{
	int x;
	int a;
}zb[1000];
bool cmp(zuobiao m,zuobiao n)
{
	return m.x<n.x;
}
int main()
{
	int n,t,cnt=0;
	cin>>n>>t;
	for(int i=0;i<n;++i)
		{
			cin>>zb[i].x>>zb[i].a;
		}
	sort(zb,zb+n,cmp);
	for(int i=0;i<n-1;++i)
	{
		if(zb[i+1].x-(zb[i+1].a)/2.0-zb[i].x-(zb[i].a)/2.0==t)	cnt++;
		if(zb[i+1].x-(zb[i+1].a)/2.0-zb[i].x-(zb[i].a)/2.0>t)	cnt+=2;
	}
	cnt+=2; 
	cout<<cnt<<endl;
	return 0;
}
