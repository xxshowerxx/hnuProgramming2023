#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	long long int a[t],b[t],k[t],s[t];
	for(int i=0;i<t;++i)
	{
		cin>>a[i]>>b[i]>>k[i];
		if(k[i]%2==0)
			s[i]=(a[i]-b[i])*k[i]/2;
		else
			s[i]=(a[i]-b[i])*(k[i]/2)+a[i]; 
	}
	for(int i=0;i<t;++i)
		cout<<s[i]<<endl;
	return 0;
}
