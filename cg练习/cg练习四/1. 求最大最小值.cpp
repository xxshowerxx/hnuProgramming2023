#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int n,maxi=INT_MIN,mini=INT_MAX;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]>maxi)	maxi=a[i];
		if(a[i]<mini)	mini=a[i];
	}
	cout<<maxi<<" "<<mini<<endl;
	return 0;
}
