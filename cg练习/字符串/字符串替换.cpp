#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s, old_str, new_str;
	getline(cin,s);
	getline(cin,old_str);
	getline(cin,new_str);
	while(1)
	{
		int n=s.find(old_str);
		if(n!=-1)
		{
			s.replace(n,old_str.length(),new_str);
		}
		else 
		  break;
	}
	cout<<s<<endl;
	return 0;
}
