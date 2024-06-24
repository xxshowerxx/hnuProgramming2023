#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int a[t],b[t];
	bool answer[t];
	for(int i=0;i<t;++i)
	{
		cin>>a[i]>>b[i];
		int x=0,y=0,round=1;
		do
		{
			if(round%2==0)	y+=round;
			else x+=round;
			round++;
		}while(x<=a[i]&&y<=b[i]);
		if(x>a[i])	answer[i]=1;
		else answer[i]=0;
	}
	for(int i=0;i<t;++i)
	{
		if(answer[i]==0)
			cout<<"Limak"<<endl;
		else
			cout<<"Bob"<<endl;
	}
	return 0;
}
