#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int i,j;
	string s,s1,s2;
	cin>>s>>i>>j;
	s1=s.substr(i,j-i+1);
	s2=s1;
	reverse(s1.begin(),s1.end());
	if(s1==s2) cout<<"Yes";
	else cout<<"No";
	return 0;
}
