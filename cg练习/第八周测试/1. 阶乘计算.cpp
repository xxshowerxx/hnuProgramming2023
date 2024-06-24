#include<iostream>
using namespace std;
int factorial(int n)
{
	int s=1;
	for(int i=2;i<=n;++i)
	{
		s*=i;
	}
	return s;
}
int main()
{
	int n;
	cin>>n;
	cout<<factorial(n)<<endl;
	return 0;
}
