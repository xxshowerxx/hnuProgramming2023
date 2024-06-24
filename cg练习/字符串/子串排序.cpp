#include<iostream> 
#include<algorithm>
using namespace std;
int main()
{
	string a;
	getline(cin, a);
	int i, j;
	cin>>i>>j;
	for(int m=i;m<j;m++)
	{
		for(int n=i;n<j;n++)
	    {
	    	if(a[n]>a[n+1])
	    	  swap(a[n], a[n+1]);
		}
	}
	cout<<a<<endl;
	return 0;
}
