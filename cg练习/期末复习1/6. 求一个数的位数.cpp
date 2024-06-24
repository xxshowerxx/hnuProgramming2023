#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,num=0;
	cin>>n;
	if(n==0)cout<<1<<endl;
	else
	{
		while(n!=0)
		{
			num++;
			n/=10;
		}
		cout<<num<<endl;
	}
 	return 0;
}

