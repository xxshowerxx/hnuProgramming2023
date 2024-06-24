#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,a;
	long long int s=0;
	cin>>n;
	a=abs(n);
	while(a!=0)
	{
		s=s*10+a%10;
		a/=10;
	}
	if(n<0)	s*=-1;
	if(s!=(int)s)
		cout<<"0"<<endl;
	else
		cout<<s<<endl;
	return 0;
}
