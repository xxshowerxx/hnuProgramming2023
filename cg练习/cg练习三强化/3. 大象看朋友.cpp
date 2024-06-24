#include<iostream>
using namespace std;
int m;
int step(int x,int s)
{
	if(x<=2*m-1)
	{
		if(x==0)	s=s;
		else if(x%2==0)s+=2;
		else s+=1;
	}
	else
	{
		s+=x/(2*m-1);
		x%=2*m-1;
		s=step(x,s);
	}
	return s;
}
int main()
{
	int x,s;
	cin>>x>>m;
	if(x<0)	x*=-1;
	s=step(x,0);
	cout<<s<<endl;
	return 0;
}
