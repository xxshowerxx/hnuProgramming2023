#include<bits/stdc++.h>
using namespace std;
char s[10001],xs1[10001],xs2[10002];
int main()
{
	int i,j;
	cin>>s>>i>>j;
	for(int k=0;k<=i;++k)
	{
		xs1[k]=s[k];
	}
	for(int k=j;s[k]!=0;++k)
	{
		xs2[k-j]=s[k];
	}
	if(strcmp(xs1,xs2)<=0)
		cout<<xs1<<endl<<xs2<<endl;
	else
		cout<<xs2<<endl<<xs1<<endl;
	return 0;
}
