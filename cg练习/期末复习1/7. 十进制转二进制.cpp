#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n;
	do
	{
		s+='0'+n%2;
		n/=2;
	}while(n!=0);
	reverse(s.begin(),s.end());
	cout<<s<<endl;
 	return 0;
}

