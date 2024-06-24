#include <iostream>
using namespace std;
int getCandy(int, int);
int main()
{
	int k, r;
	cin>>k>>r;
	int result=getCandy(k,r);
	cout<<result<<endl;
	return 0;
}
int getCandy(int k,int r)
{
	int cnt=1,t=k%10;
	while(t%10!=r&&t%10!=0)
	{
		t+=k;
		cnt++;
	}
	return cnt;
}
