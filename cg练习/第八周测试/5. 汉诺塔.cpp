#include<stdio.h>
#include<iostream>
using namespace std;
void hnt(int n,char a,char b,char c)
{
	if(n==1)
		printf("Move %d:from %c to %c\n",n,a,c);
	else
	{
		hnt(n-1,a,c,b);
		printf("Move %d:from %c to %c\n",n,a,c);
		hnt(n-1,b,a,c);
	}
}
int main()
{
	int n;
	cin>>n;
	hnt(n,'A','B','C');
	return 0;
}
