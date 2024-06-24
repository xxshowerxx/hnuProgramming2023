#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,s1,s2;
	cin>>s;
	int i,j;
	cin>>i>>j;
	s1=s.substr(0,i+1);
	s2=s.substr(j);
	if(s1>s2)swap(s1,s2);
	cout<<s1<<endl<<s2<<endl;
	return 0;
}
