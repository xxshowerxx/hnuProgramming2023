# include "yang.h"
using namespace std;
void PrintBlank(int num)
{
	for(int i=1;i<=num;++i)
		cout<<" ";
}
void PrintCombine(int n)
{
	int t=1;
	cout<<t<<" ";
	for(int i=2;i<=n;++i)
	{
		t=t*(n-i+1)/(i-1);
		cout<<t<<" ";
	}
}
