#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s,s1;
	cin>>s;
	s1=s;
	reverse(s.begin(),s.end());
	if(s1==s)cout<<"Yes";
	else cout<<"No";
	return 0;
}
