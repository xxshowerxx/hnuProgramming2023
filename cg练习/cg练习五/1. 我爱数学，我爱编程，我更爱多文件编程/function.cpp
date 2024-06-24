#include<cmath>
bool prime(int a)
{
	int i;
	for(i=2;i<=sqrt(a);++i)
		if(a%i==0)	break;
	if(i<=sqrt(a))return 0;
	else return 1;
}
bool plalindrome(int a)
{
	int s=a,t=0;
	while(a!=0)
	{
		t=t*10+a%10;
		a/=10;
	}
	if(t==s)
		return 1;
	else
		return 0;
}
