#include<bits/stdc++.h>
using namespace std;
int t;
struct ZB
{
	int x[4],y[4],T,in=0,out=0,flag=0;
	void make4()
	{
		int d[3],flag=0;
		for(int i=0;i<3;++i)
		{
			d[i]=(x[(i+1)%3]-x[(i+2)%3])*(x[(i+1)%3]-x[(i+2)%3])+(y[(i+1)%3]-y[(i+2)%3])*(y[(i+1)%3]-y[(i+2)%3]);
		}
		for(int i=0;i<3;++i)
		{
			if(d[i]==d[(i+1)%3]+d[(i+2)%3])
			{
				flag=i;
				break;
			}
		}
		x[3]=x[(flag+1)%3]+x[(flag+2)%3]-x[flag];
		y[3]=y[(flag+1)%3]+y[(flag+2)%3]-y[flag];
	}
};
int money(const ZB&before,ZB&next,const ZB&final,int&min)
{
	int flag=0;
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			int tmp=(abs(before.x[before.out]-next.x[i])+abs(before.y[before.out]-next.y[i])+abs(final.x[final.in]-next.x[j])+abs(final.y[final.in]-next.y[j]))*t
			+(abs(next.x[i]-next.x[j])+abs(next.y[i]-next.y[j]))*next.T;
			if(tmp<=min)
			{
				next.in=i,next.out=j;
				min=tmp;
				flag=1;
			}
		}
	}
	return flag;
}
int mini(const ZB&a,const ZB&b)
{
	return	(abs(a.x[a.out]-b.x[b.in])+abs(a.y[a.out]-b.y[b.in]))*t+(abs(b.x[b.in]-b.x[b.out])+abs(b.y[b.in]-b.y[b.out]))*b.T;
}
int main()
{
	int s,a,b,first,tfirst;
	cin>>s>>t>>a>>b;
	ZB *port=new ZB[s+1];
	int sum=0;
	port[a].flag=1,port[b].flag=1;
	for(int i=1;i<=s;++i)
	{
		cin>>port[i].x[0]>>port[i].y[0]>>port[i].x[1]>>port[i].y[1]>>port[i].x[2]>>port[i].y[2]>>port[i].T;
		port[i].make4();
	}
	int tmin=INT_MAX;
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			if((abs(port[a].x[i]-port[b].x[j])+abs(port[a].y[i]-port[b].y[j]))*t<tmin)
			{
				tmin=(abs(port[a].x[i]-port[b].x[j])+abs(port[a].y[i]-port[b].y[j]))*t;
				port[a].out=i;
				port[b].in=j;
				port[b].out=j;
			}
		}
	}
	first=tfirst=a;
	do
	{
		first=tfirst;
		for(int i=1;i<=s;++i)
		{
			if(port[i].flag) continue;
			if(money(port[first],port[i],port[b],tmin))
			{
				tfirst=i;
			}
		}
		port[tfirst].flag=1;
		if(tfirst==first) break;
		sum+=mini(port[first],port[tfirst]);
		tmin=mini(port[tfirst],port[b]);
	}while(tfirst!=first);
	sum+=tmin;
	cout<<sum<<'\n';
 	return 0;
}

