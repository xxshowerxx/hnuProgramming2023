#include<iostream>
using namespace std;
int gys(int x,int y)
{
	if(x<y)swap(x,y);
	if(x%y==0)	return y;
	else
	{
		return gys(y,x%y);
	}
}
int main()
{
	long long int m,n,d,cnt;
	cin>>m>>n;
	d=gys(m,n);
	cnt=m*n/(d*d);
	cout<<cnt<<" "<<d<<endl;
	return 0;
}
