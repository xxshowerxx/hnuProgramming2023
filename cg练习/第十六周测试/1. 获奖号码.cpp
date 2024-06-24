#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,max=INT_MIN,tmp;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>tmp;
		if(tmp>max&&tmp%2==0) max=tmp;
	}
	cout<<max<<endl;
 	return 0;
}

