#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],mini=0;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]<a[mini])mini=i;
	}
	cout<<mini<<endl;
	return 0;
}
