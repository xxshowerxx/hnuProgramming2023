#include<bits/stdc++.h>
using namespace std;
int apple(int m,int n)
{
	if(m<n)	return 0;
	else if(m==n)	return 1;
	else return apple(m-n,n+1)+apple(m,n+1);
}
int main()
{
	int m=0;
	cin>>m;
	cout<<apple(m,1)<<endl;
	return 0;
}
