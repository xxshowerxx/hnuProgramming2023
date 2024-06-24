#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	cin>>a;
	long long c=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		  c=10*c+(a[i]-'0');
	}
	cout<<c/9527<<endl;
	return 0;
}
