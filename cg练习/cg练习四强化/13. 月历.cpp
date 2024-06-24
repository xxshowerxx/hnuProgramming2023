#include<iostream>
#include<iomanip>
using namespace std;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int y,m,day,run;
	cin>>y>>m;
	run=(y-1)/4-(y-1)/100+(y-1)/400;
	day=run+(y-1)*365;
	if(y%4==0&&(y%100!=0||y%400==0))
		mon[2]=29;
	for(int i=1;i<=m-1;++i)
		day+=mon[i];
	day=(day-6)%7;
	cout<<" Sun Mon Tus Wed Thu Fri Sat"<<'\n';
	int p=0,t=1;
	while(t<=mon[m])
	{
		if(day!=p)	cout<<setw(4)<<" ";
		else
		{
			cout<<setw(4)<<t;
			t++;
			day=(day+1)%7;
		}
		p=(p+1)%7;
		if(p==0)	cout<<'\n';
	}
	return 0;
}
