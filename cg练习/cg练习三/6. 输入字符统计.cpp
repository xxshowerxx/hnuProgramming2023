#include<iostream>
using namespace std;
int main()
{
	int n,d=0,x=0,s=0,q=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		char a;
		cin>>a;
		if(a>=65&&a<=90)
			d++;
		else if(a>=97&&a<=122)	
			x++;
		else if(a>=48&&a<=57)	
		{
			s++;
			sum+=a-48;
		}
		else 
			q++;
	}
	cout<<d<<" "<<x<<" "<<s<<" "<<q<<endl;
	if(sum!=0)	cout<<sum<<endl;
	return 0;
}
