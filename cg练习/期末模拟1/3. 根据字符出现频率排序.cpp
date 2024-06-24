#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	map<char,int> a;
	for(int i=0;i<(int)s.size();++i)
	{
		a[s[i]]++;
	}
	vector<pair<char,int>> b;
	for (auto it = a.begin();it!= a.end();it++) 
	{
        b.push_back(make_pair(it->first, it->second));
   	}
	sort(b.begin(),b.end(),[](const pair<char,int>&x,const pair<char,int>&y)
	{
		if(x.second!=y.second) return x.second>y.second;
		else return x.first>y.first;
	});
	for(auto it=b.begin();it<b.end();it++)
	{
		for(int i=0;i<it->second;i++)
			cout<<it->first;
	}
 	return 0;
}

