#include<iostream>
#include<algorithm>
using namespace std;
struct bir
{
	int time;
	char name;
}s[3];
bool cmp(bir x,bir y)
{
	return x.time<y.time;
}
int main()
{
	int y[3],m[3],d[3];
	for(int i=0;i<=2;++i)
		{
			cin>>y[i]>>m[i]>>d[i];
			s[i].time=y[i]*10000+m[i]*100+d[i];
			s[i].name=i+65;
		}
	sort(s,s+3,cmp);
	for(int i=0;i<=2;++i)
	{
		cout<<s[i].name;
	}
	return 0;
}
