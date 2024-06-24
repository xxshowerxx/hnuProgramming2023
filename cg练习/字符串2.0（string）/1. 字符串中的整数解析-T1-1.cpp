#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<26;++i)
	{
		s.erase(remove(s.begin(),s.end(),(char)i+'a'),s.end());
		s.erase(remove(s.begin(),s.end(),(char)i+'A'),s.end());
	}
	int a=atoi(s.c_str());
	cout<<a/9527<<endl;
	return 0;
 } 
