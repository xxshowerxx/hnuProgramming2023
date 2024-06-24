#include<iostream>
using namespace std;
int main()
{
	int n,s;
	cin>>n;
	if(n>=10)
		cout<<n<<" ";
	do
	{
		s=1;
		while(n!=0)
		{
			if(n%10!=0)
				s*=(n%10);
			n/=10;
		}
		n=s;
		cout<<s<<" ";
	}while(s/10!=0);
	return 0;
}
