#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n,[](int x,int y){
		if(x%3==0&&y%3==0) return x>y;
		else if(x%3!=0&&y%3!=0) return x<y;
		else return x%3<y%3;
	});
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";
 	return 0;
}

