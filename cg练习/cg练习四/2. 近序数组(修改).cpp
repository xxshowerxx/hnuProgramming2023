#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1],b[n],dif=0,mid=0,flag=0;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<n;++i)
		if(a[i]>a[i+1])	b[i]=1;
		else	b[i]=-1;
	for(int i=1;i<n-1;++i)
		if(b[i]!=b[i+1])
		{
			dif++;
			if(mid!=0&&i!=mid+1)
			{
				flag=1;
				break;
			}
			else mid=i;
		}
	if(dif<=2&&flag==0)	cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
