#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s, a, b;
	getline(cin, s);
	int i, j;
	cin>>i>>j;
	for(int n=0;n<=i;n++)
      a+=s[n];
    for(int m=j;m<=s.length();m++)
      b+=s[m];
    if(a>b)
      cout<<b<<endl<<a<<endl;
    else
      cout<<a<<endl<<b<<endl;
    return 0;
}
