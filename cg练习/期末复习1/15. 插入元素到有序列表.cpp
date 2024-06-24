#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int a[1000001];
int main()
{
	int n,i;
	cin>>n>>i;
	for(int j=0;j<n;++j)
		cin>>a[j];
	a[n]=i;
	sort(a,a+n+1,greater<int>());
	for(int j=0;j<n+1;++j)
		cout<<a[j]<<' ';
 	return 0;
}

