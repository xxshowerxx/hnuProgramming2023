#include<iostream>
#include<algorithm>
using namespace std;
int t[10001];
int main()
{
	int n,m,a,d,cnt=0,time=0,status=0,mark=0;
	cin>>n>>m>>a>>d;
	for(int i=0;i<m;++i)
		cin>>t[i];
	for(int i=m;i<m+n;++i)
		t[i]=(i-m+1)*a;
	sort(t,t+m+n);
	for(int i=0;i<m+n;i++)
	{
		time=t[i];
		if(status==1&&time>mark+d)	status=0;
		if(status==0)
		{
			cnt++;
			mark=time;
			status=1;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
