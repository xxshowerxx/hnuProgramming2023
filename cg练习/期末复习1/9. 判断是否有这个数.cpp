#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,a,flag=0;
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		cin>>a;
		if(a==k)flag=1;
	}
	cout<<flag<<endl;
 	return 0;
}

