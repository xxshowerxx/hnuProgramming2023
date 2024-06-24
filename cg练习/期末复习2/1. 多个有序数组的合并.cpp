#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int *a=new int[n*m]();
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			cin>>a[i*m+j];
	}
	sort(a,a+n*m);
	for(int i=0;i<n*m;++i)
		cout<<a[i]<<" ";
 	return 0;
}

