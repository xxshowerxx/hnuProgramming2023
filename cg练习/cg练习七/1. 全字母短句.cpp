#include<bits/stdc++.h>
using namespace std;
int zm[26];
string s;
int main()
{
	int flag=0,t;
	cin>>t;
	cin.ignore();
	for(int i=0; i<t; ++i)
	{
		getline(cin,s);
		for(int j=0; j<26; ++j)
			if(s.find(char(j+'A'))==string::npos&&s.find(char(j+'a'))==string::npos)
			{
				flag=1;
				zm[j]=1;
			}
		if(flag==0)cout<<"Yes"<<'\n';
		else
		{
			cout<<"No ";
			for(int j=0; j<26; ++j)
				if(zm[j]!=0)
				{
					cout<<(char)(j+'A')<<" ";
					zm[j]=0;
				}
			cout<<'\n';
		}
		flag=0;
	}
	return 0;
}
