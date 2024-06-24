#include<iostream>
using namespace std;
int main()
{
	int n,k,m,d,x,max=0;
	cin>>n>>k>>m>>d;
	for(int i=m;i>0&&(n/i+k-1)/k<=d;i--)
	{
		x=(n/i+k-1)/k*i;
		if(x>max)	max=x;
	}
	cout<<max<<endl;
	return 0;
}
