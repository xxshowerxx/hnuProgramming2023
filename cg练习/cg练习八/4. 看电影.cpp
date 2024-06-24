#include<iostream>
using namespace std;
struct People
{
	int a;
};
struct Object
{
	int b,c;
	int happy=0,satisfied=0;
};
int index[1001];
int main()
{
	int n;
	cin>>n;
	People *scientist=new People [n];
	for(int i=0;i<n;++i)
		cin>>scientist[i].a;
	int m;
	cin>>m;
	Object *film=new Object[m];
	for(int i=0;i<m;++i)
		cin>>film[i].b;
	for(int i=0;i<m;++i)
		cin>>film[i].c;
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(scientist[j].a==film[i].b)
				film[i].happy++;
			if(scientist[j].a==film[i].c)
				film[i].satisfied++;
		}
	}
	int maxi=0,sum=0;
	for(int i=0;i<m;++i)
	{
		if(film[i].happy>film[maxi].happy)
		{
			maxi=i;
			sum=1;
			index[sum]=i+1;
		}
		else if(film[i].happy==film[maxi].happy&&film[i].satisfied>film[maxi].satisfied)
		{
			maxi=i;
			sum=1;
			index[sum]=i+1;
		}
		else if(film[maxi].happy!=0&&film[i].happy==film[maxi].happy&&film[i].satisfied==film[maxi].satisfied)
		{
			sum++;
			index[sum]=i+1;
		}
	}
	if(sum!=0)
	{
		for(int i=1;i<=sum;++i)
			cout<<index[i]<<" ";
	}
	else
		cout<<"unsatisfied"<<endl;
	return 0;
}
