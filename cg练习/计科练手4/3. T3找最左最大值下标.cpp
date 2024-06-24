#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],maxi=0;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]>a[maxi])maxi=i;
	}
	cout<<maxi<<endl;
	return 0;
}
