#include<iostream>
using namespace std;
int main()
{
	char a[3];
	char b[5][3];
	bool flag=0;
	cin>>a;
	for(int i=0;i<=4;i++)
	{
		cin>>b[i];
		if(a[0]==b[i][0]||a[1]==b[i][1])
			flag=1;
	}
	if(flag==1)	cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
