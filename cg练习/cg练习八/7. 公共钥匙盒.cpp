#include<iostream>
#include<algorithm>
using namespace std;
struct Teacher
{
	int w,s,c,e;
};
bool cmp1(Teacher a,Teacher b)
{
	return a.s<b.s;
}
bool cmp2(Teacher a,Teacher b)
{
	if(a.e==b.e) return a.w<b.w;
	return a.e<b.e;
}
int main()
{
	int N,K;
	cin>>N>>K;
	int *a=new int[N];
	Teacher *take=new Teacher[K];
	Teacher *back=new Teacher[K];
	for(int i=0;i<N;++i)
		a[i]=i+1;
	for(int i=0;i<K;++i)
	{
		cin>>take[i].w>>take[i].s>>take[i].c;
		take[i].e=take[i].s+take[i].c;
		back[i]=take[i];
	
	}
	sort(take,take+K,cmp1);
	sort(back,back+K,cmp2);
	int i=0,j=0;
	while(j<K)
	{
		while(j<K&&(i==K||(back[j].e<=take[i].s)))
		{
			for(int t=0;t<N;++t)
			{
				if(a[t]==0)
				{
					a[t]=back[j].w;
					break;
				}
			}
			j++;
		}
		while(i<K&&take[i].s<back[j].e)
		{
			for(int t=0;t<N;++t)
			{
				if(a[t]==take[i].w)
				{	
					a[t]=0;
					break;
				}
			}
			i++;
		}
	}
	for(int i=0;i<N;++i)
		cout<<a[i]<<" ";
	delete[]a;
	delete[]take;
	delete[]back;
	return 0;
}
