#include<iostream>
using namespace std;
struct People
{
	int sum=0;
	int *vote=new int[101];
};
int main()
{
	int n,m;
	cin>>n>>m;
	People *candidate=new People[n];
	for(int i=0;i<m;++i)
	{
		int max=0,maxj=0;
		for(int j=0;j<n;++j)
		{
			cin>>candidate[j].vote[i];
			if(candidate[j].vote[i]>max)
			{
				max=candidate[j].vote[i];
				maxj=j;
			}
			
		}
		candidate[maxj].sum+=1;
	}
	int maxi=0,max=0;
	for(int i=0;i<n;++i)
		if(candidate[i].sum>max)
		{
			max=candidate[i].sum;
			maxi=i;
		}
	cout<<maxi+1<<endl;
	return 0;
}
