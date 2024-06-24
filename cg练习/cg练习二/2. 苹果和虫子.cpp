#include<iostream>
using namespace std;
int main()
{
	int n,x,y,s;
	cin>>n>>x>>y;
	s=n-(y+x-1)/x;
	if(s<0)
		cout<<"0"<<endl;
	else 
		cout<<s<<endl;
	return 0;
}
