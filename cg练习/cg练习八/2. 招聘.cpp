#include<bits/stdc++.h>
using namespace std;
struct People
{
	int K,I,E;
};
int main()
{
	int n,sum=0;
	cin>>n;
	People *candidate=new People[n];
	for(int i=0;i<n;++i)
		cin>>candidate[i].K;
	for(int i=0;i<n;++i)
		cin>>candidate[i].I;
	for(int i=0;i<n;++i)
		cin>>candidate[i].E;
	int *flag=new int[n];
	memset(flag,0,sizeof(int)*n);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i==j) continue;
			if(flag[i]!=1&&candidate[i].K<candidate[j].K&&candidate[i].I<candidate[j].I&&candidate[i].E<candidate[j].E)
			{
				flag[i]=1;
				sum++;
			}
		}
	}
	cout<<sum<<endl;
	delete[]candidate;
	delete[]flag;
	return 0;
}
