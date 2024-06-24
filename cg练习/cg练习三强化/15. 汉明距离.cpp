#include<iostream>
using namespace std;
int main()
{
	int x,y,n,t=0;
	cin>>x>>y;
	n=x^y;
	while(n!=0)
	{
		t+=(n&1);
		n>>=1;
	}
	cout<<t<<endl;
	return 0;
}
