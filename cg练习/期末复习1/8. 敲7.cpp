#include<iostream>
using namespace std;
bool seven(int i)
{
	while(i!=0)
	{
		if(i%10==7) return 1;
		i/=10;
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		if(i%7==0||seven(i))
			cout<<i<<endl;
	}
 	return 0;
}

