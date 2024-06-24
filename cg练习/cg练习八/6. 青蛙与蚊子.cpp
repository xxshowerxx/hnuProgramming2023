#include<iostream>
#include<algorithm>
using namespace std;
struct Frog
{
	int x,t,sum=0,num;
};
struct Mi
{
	int p,b,live=1;
};
bool cmp1(Frog a,Frog b)
{
	return a.x<b.x;
}
bool cmp2(Frog a,Frog b)
{
	return a.num<b.num;
}
int main()
{
	int n,m;
	cin>>n>>m;
	Frog *frog=new Frog[n];
	Mi *mi=new Mi[m];
	for(int i=0; i<n; ++i)
	{
		cin>>frog[i].x>>frog[i].t;
		frog[i].num=i;
	}
	sort(frog,frog+n,cmp1);
	for(int i=0; i<m; ++i)
	{
		cin>>mi[i].p>>mi[i].b;
	}
	int flag=1;
	while(flag)
	{
		flag=0;
		for(int i=0; i<m;++i)
			for(int j=0; j<n; ++j)
			{
				if(mi[i].live&&frog[j].x<=mi[i].p&&(frog[j].x+frog[j].t)>=mi[i].p)
				{
					frog[j].sum++;
					frog[j].t+=mi[i].b;
					mi[i].live=0;
					flag=1;
					break;
				}
			}
	}
	sort(frog,frog+n,cmp2);
	for(int i=0; i<n; ++i)
		cout<<frog[i].sum<<" "<<frog[i].t<<endl;
	return 0;
}
