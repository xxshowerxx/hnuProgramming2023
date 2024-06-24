#include<iostream>
#include<algorithm>
using namespace std;
int x[10001];
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		int n,k,max=0;
		cin>>n>>k;
		int t;
		for(int i=0;i<k;++i)
			cin>>x[i];
		sort(x,x+k);
		for(int i=0;i<k;++i)
		{
			t=(x[i+1]-x[i])/2+1;
			if(t>max)	max=t;
		}
		if(x[0]>max)	max=x[0];
		if(n-x[k-1]+1>max)	max=n-x[k-1]+1;
		cout<<max<<endl;
	}

	return 0;
}
