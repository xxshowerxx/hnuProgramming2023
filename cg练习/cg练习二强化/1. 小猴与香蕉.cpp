#include<iostream>
using namespace std;
int main()
{
	int k,n,w,s;
	cin>>k>>n>>w;
	s=(1+w)*w/2*k;
	if(s<=n)
		cout<<"0"<<endl;
	else
		cout<<s-n<<endl;
	return 0;
}
