#include<iostream>
using namespace std;
int main()
{
	int a,b,c=0,n;
	cin>>a>>b>>n;
	if(a>b)	cout<<a/b<<".";
	else cout<<"0.";
	while(c<n)
	{
		a=a%b*10;
		cout<<a/b;
		c++;
	}
	return 0;
}
