#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,t=1,flag=0;
	cin>>n;
	if(n==1)
		cout<<"1"<<endl;
	else
	{
		int i;
		for(i=2;i<=sqrt(n);++i)
		{
			if(n%i==0)
			{
				n/=i;
				if(n%i==0)
				{
					flag=1;
					break;
				}
				else
					t++;//经过调试研究，由于n的值动态发生变化，所以有且仅有最后一个素数是不能被判断到的，累加次数比真正素数个数少1，所以t设初值1 
			}
		}
		if(flag==1)	cout<<"0\n";
		//经过调试研究，这边不能再通过比较i和sqrt(n)的大小来输出0，因为n的值动态发生变化
		//可以直接在循环中输出并结束或者标记退出判断 
		else if(t%2!=0)	cout<<"-1\n";
		 
		else	cout<<"1\n";
	}
	return 0;
}
