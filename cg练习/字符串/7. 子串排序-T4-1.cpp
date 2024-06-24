#include<bits/stdc++.h>
using namespace std;
char s[10001];
int main()
{
	cin.getline(s,10001);
	int i,j;
	cin>>i>>j;
	sort(s+i,s+j+1);
	cout<<s<<endl;
	return 0;
}
