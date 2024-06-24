#include<iostream>
using namespace std;
int ladder(int n)
{
	if(n==1)
		return 1;
	else if(n==2)	return 1+ladder(n-1);
	else return ladder(n-1)+ladder(n-2);
}
int main()
{
	int n;
	cin>>n;
	cout<<ladder(n);
	return 0;
}
