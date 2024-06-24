#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a;
	cin>>n;
	unordered_map<int, int> map;
	for(int i=0;i<n;++i)
	{
		cin>>a;
		if(map.find(a)==map.end())
			map[a]=1;
		else
			map[a]+=1;
	}
	vector<pair<int, int>> order;
    for (auto it = map.begin();it!= map.end();it++) 
	{
        order.push_back(make_pair(it->first, it->second));
   	}
   	sort(order.begin(),order.end(),[](pair<int, int>a, pair<int, int>b)
	{
		return a.first>b.first;
	});
	for(auto it = order.begin();it!=order.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
 	return 0;
}
