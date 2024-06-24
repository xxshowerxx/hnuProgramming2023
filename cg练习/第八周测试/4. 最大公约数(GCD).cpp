#include<iostream>
#include<stdio.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)	return a;
	else return gcd(b,a%b);
}
int main()
{
	int a,b;
	scanf("%d,%d",&a,&b);
	if(a<b)
		swap(a,b);
	int r=gcd(a,b);
	cout<<r<<endl;
	return 0;
}
