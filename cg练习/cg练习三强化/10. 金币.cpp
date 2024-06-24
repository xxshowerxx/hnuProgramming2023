#include<iostream>
using namespace std;
int main()
{
	int day,sum=0,single=1,t=0;
	cin>>day;
	for(int i=1;i<=day;++i)
	{
		if(t<single)	
		{
			sum+=single;
			t++;
		}
		else
		{
			single++;
			sum+=single;
			t=1;
		}
	}
	cout<<sum<<endl;
	return 0;
}
