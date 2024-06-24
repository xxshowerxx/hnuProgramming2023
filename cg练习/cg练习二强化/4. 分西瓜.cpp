#include<iostream>
using namespace std;
int main()
{
	long long int w;
	cin>>w;
	if(w==2)
		cout<<"No"<<endl;
	else 
	{
		if(w%2==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
