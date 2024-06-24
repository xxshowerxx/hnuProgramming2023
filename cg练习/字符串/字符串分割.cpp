#include<iostream>
#include<string> 
using namespace std;
int main()
{
	string s, t;
	getline(cin, s);
	getline(cin, t);
	while(s.find(t)!=-1)
	{
		string a=s.substr(0, s.find(t));
		cout<<a<<endl;
        s.erase(0,s.find(t)+t.length());
	}
	cout<<s<<endl;
	return 0;
} 
