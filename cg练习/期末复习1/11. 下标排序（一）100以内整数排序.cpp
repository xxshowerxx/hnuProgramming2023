#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	int a[100];
	for(int i=0;i<100;++i)
	{
		cin>>a[i];
	}
	sort(a,a+100,greater<int>());
	for(int i=0;i<100;++i)
	{
		cout<<a[i]<<" ";
	}
 	return 0;
}

