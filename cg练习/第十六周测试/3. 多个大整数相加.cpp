#include<bits/stdc++.h>
using namespace std;
string add(string a,string b)
{
	string c="";
	int yu=0;
	for(int i=0;i<int(b.size());++i)
	{
		int ai=*(a.end()-i-1)-'0',bi=*(b.end()-i-1)-'0';
		int sum=ai+bi+yu;
		yu=0;
		if(sum>=10)
		{
			sum-=10;
			yu+=1;
		}
		char d=sum+'0';
		c=c+d;
	}
	for(int i=int(b.size());i<int(a.size());++i)
	{
		int sum=*(a.end()-i-1)-'0'+yu;
		yu=0;
		if(sum>=10)
		{
			sum-=10;
			yu+=1;
		}
		char d=sum+'0';
		c=c+d;
	}
	if(yu!=0) c+='1';
	reverse(c.begin(),c.end());
	return c;
}
int main()
{
	int n;
	string s[101],ans;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>s[i];
	}
	sort(s,s+n,[](string &a,string &b)
	{
		return a.size()>b.size();
	});
	ans=s[0];
	for(int i=1;i<n;++i)
	{
		ans=add(ans,s[i]);
	}
	cout<<ans<<endl;
	return 0;
}

