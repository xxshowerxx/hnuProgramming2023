#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	char c;
	cin>>n;
	vector<vector<int>> a(n,vector<int>(2));
	for(int i=0;i<n;++i)
		cin>>a[i][0]>>c>>a[i][1];
	sort(a.begin(),a.end(),[](vector<int>x,vector<int>y)
	{
		if(x[0]!=y[0])return x[0]<y[0];
		else return x[1]<y[1];
	});
	int mini=60*24;
	for(int i=0;i<n-1;++i)
		if(((a[i+1][0]-a[i][0])*60+a[i+1][1]-a[i][1])<mini)
			mini=(a[i+1][0]-a[i][0])*60+a[i+1][1]-a[i][1];
	if(((a[0][0]+24-a[n-1][0])*60+a[0][1]-a[n-1][1])<mini)
		mini=(a[0][0]+24-a[n-1][0])*60+a[0][1]-a[n-1][1];
	cout<<mini<<endl;
 	return 0;
}

