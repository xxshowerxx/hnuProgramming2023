#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	getline(cin,s);
	getline(cin,t);
	while(s.find(t)!=string::npos)
	{
		cout<<s.substr(0,s.find(t))<<endl;
		s.erase(0,s.find(t)+t.size());
	}
	if(s.size()!=0) cout<<s<<endl;
	return 0;
}
