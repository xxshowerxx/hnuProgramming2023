#include<iostream>
using namespace std;
char a[10001];
int main()
{
	int s=0;
	cin>>a;
	for(int i=0;a[i]!='\0';++i)
	{
		if(a[i]>='0'&&a[i]<='9')
			s=s*10+a[i]-'0';
	}
	cout<<s/9527<<endl;
	return 0;
}
