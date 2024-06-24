#include<iostream>
using namespace std;
int main()
{
	int x,h,m,t=0;
	cin>>x>>h>>m;
	while(h%10!=7&&m%10!=7)
	{
		while(m<x)
		{
			m+=60;
			h-=1;
			if(h<0)	h=23;
		}
		m-=x;
		t++;
	}
	cout<<t<<endl;
	return 0;
}
