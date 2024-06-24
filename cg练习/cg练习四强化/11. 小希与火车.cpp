#include<iostream>
using namespace std;
int main()
{
	int T,L,v,l,r;
	cin>>T;
	for(int i=1;i<=T;++i)
	{
		cin>>L>>v>>l>>r;
		int p=v,cnt=0;
		while(p<=L)
		{
			if(p<l||p>r)
				cnt++;
			p+=v;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
