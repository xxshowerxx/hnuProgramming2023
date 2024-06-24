#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	int n,a,num=0;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a;
		if(a%3==0) num++;
	}
	cout<<num<<endl;
 	return 0;
}

