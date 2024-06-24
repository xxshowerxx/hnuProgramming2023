#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int i,j;
	cin>>s>>i>>j;
	string s1=s.substr(i,j+1-i);
	sort(s1.begin(),s1.end());
	s.replace(i,s1.size(),s1);
	cout<<s<<endl;
	return 0;
}
