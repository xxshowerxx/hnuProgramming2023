#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,old_str,new_str;
	getline(cin,s);
	getline(cin,old_str);
	getline(cin,new_str);
	while(s.find(old_str)!=string::npos)
		s.replace(s.find(old_str),old_str.size(),new_str);
	cout<<s<<endl;
	return 0;
}
