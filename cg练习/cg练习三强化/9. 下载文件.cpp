#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;++i)
	{
		int n,k;
		cin>>n>>k;
		int T[n],D[n],time=0,sum=0,j;
		for(j=0;j<n;++j)
		{
			cin>>T[j]>>D[j];
			if(time+T[j]<=k)	time+=T[j];
			else 
			{
				T[j]=time+T[j]-k;
				sum+=T[j]*D[j];
				break;
			}
		}
		for(j=j+1;j<n;++j)
		{
			cin>>T[j]>>D[j];
			sum+=T[j]*D[j];
		}
		cout<<sum<<endl;
	}
	return 0;
}
