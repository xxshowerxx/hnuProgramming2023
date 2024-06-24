#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int n=a.length(),max=0;
	for(int i=0;i<n*2-1;++i)
	{
		int l=i/2,r=(i+1)/2;
		while(l>=0&&r<=n-1&&a[l]==a[r])
		{
			l--;
			r++;
		}
		int cnt=r-l-1;
		if(cnt>max)max=cnt;
	}
	cout<<max<<endl;
	return 0;
}
