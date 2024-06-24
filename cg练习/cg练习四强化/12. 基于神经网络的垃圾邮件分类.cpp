#include<iostream>
using namespace std;
int w[10001],b[10001];
int main()
{
	int T,N,minX,maxX;
	cin>>T;
	for(int i=1;i<=T;++i)
	{
		cin>>N>>minX>>maxX;
		int oddtrash=1,eventrash=2,odd,even,yes=0,no=0;
		for(int j=1;j<=N;++j)
		{
			cin>>w[i]>>b[i];
			oddtrash=w[i]*oddtrash+b[i];
			eventrash=w[i]*eventrash+b[i];
		}
		oddtrash%=2;
		eventrash%=2;
		if(minX%2==0||maxX%2==0)
		{
			even=(maxX-minX)/2+1;
			odd=maxX-minX+1-even;
		}
		else
		{
			even=(maxX-minX)/2;
			odd=maxX-minX+1-even;
		}
		if(oddtrash)	yes+=odd;
		else no+=odd;
		if(eventrash)	yes+=even;
		else no+=even;
		cout<<no<<" "<<yes<<endl;
	}
	return 0;
}
