#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	getline(cin,s);
	getline(cin,t);
	if(s.find(t)==string::npos) cout<<"-1"<<endl;
	else cout<<s.find(t)<<endl;
	return 0;
}
