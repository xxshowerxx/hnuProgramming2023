#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[3],x[4];
	for(int i=0;i<=3;++i)
		cin>>x[i];
	sort(x,x+4,greater<int>());
	for(int i=0;i<=2;++i)
		a[i]=x[0]-x[i+1];
	sort(a,a+3);
	for(int i=0;i<=2;++i)
		cout<<a[i]<<" ";
	return 0;
 } 
