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
					t++;//���������о�������n��ֵ��̬�����仯���������ҽ������һ�������ǲ��ܱ��жϵ��ģ��ۼӴ�������������������1������t���ֵ1 
			}
		}
		if(flag==1)	cout<<"0\n";
		//���������о�����߲�����ͨ���Ƚ�i��sqrt(n)�Ĵ�С�����0����Ϊn��ֵ��̬�����仯
		//����ֱ����ѭ����������������߱���˳��ж� 
		else if(t%2!=0)	cout<<"-1\n";
		 
		else	cout<<"1\n";
	}
	return 0;
}
