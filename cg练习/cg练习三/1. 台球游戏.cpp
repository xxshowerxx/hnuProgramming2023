#include<iostream>
using namespace std;
int main()
{
	int n,sum=0;
	char a;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		if(a=='r')
		{
			int t;
			cin>>t;
			sum+=t;
		}
		else if(a=='y')
			sum+=2;
		else if(a=='g')
			sum+=3;
		else if(a=='c')
			sum+=4;
		else if(a=='b')
			sum+=5;
		else if(a=='p')
			sum+=6;
		else
			sum+=7;
	}
	cout<<sum<<endl;
	return 0;
}
