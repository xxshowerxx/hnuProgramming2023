#include<bits/stdc++.h>
using namespace std;
int main() 
{
	string s;
	getline(cin,s);
	while(s.find("WUB")==0)
		s.erase(0,3);
	while(s.rfind("WUB")==s.size()-3)
		s.erase(s.size()-3,3);
	while(s.find("WUB")!=string::npos)
		s.replace(s.find("WUB"),3," ");
	while(s.find("  ")!=string::npos)
		s.replace(s.find("  "),2," ");
	cout<<s<<endl;
    return 0;
}

