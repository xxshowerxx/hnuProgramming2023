#include<iostream>
using namespace std;
int main()
{
	int y,m;
	cin>>y>>m;
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		cout<<"31"<<'\n';
	if(m==4||m==6||m==9||m==11)
		cout<<"30"<<'\n';
	if(m==2)
	{
		if((y%4==0&&y%100!=0)||(y%400==0))
			cout<<"29"<<'\n';
		else
			cout<<"28"<<'\n';
	}
	return 0;
 } 
