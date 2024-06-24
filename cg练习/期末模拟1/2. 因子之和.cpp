#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,sum=0;
	cin>>x;
	int i;
	for(i=1;i<sqrt(x);++i)
	{
		if(x%i==0)sum+=i+x/i;
	}
	if(i*i==x)sum+=i;
	cout<<sum<<endl;
 	return 0;
}

