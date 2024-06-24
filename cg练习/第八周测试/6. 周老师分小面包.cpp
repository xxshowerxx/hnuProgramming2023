#include<bits/stdc++.h>
using namespace std;
int bread(int m)
{
	if(m==1)
		return 1;
	else if(m==2)
		return 1+bread(m-1);
	else if(m==3)
		return 1+bread(m-2)+bread(m-1);
	else	return bread(m-3)+bread(m-2)+bread(m-1);
}
int main()
{
	int m;
	cin>>m;
	cout<<bread(m)<<endl;
	return 0;
}
