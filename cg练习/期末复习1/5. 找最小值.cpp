#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,min,a;
	cin>>n>>a;
	min=a;
	for(int i=1;i<n;++i)
	{
		cin>>a;
		if(a<min) min=a;
	}
	cout<<min<<endl;
 	return 0;
}

