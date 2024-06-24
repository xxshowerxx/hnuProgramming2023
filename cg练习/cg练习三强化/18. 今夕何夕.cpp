#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d\n",&t);
	for(int i=1;i<=t;++i)
	{
		int y,m,d,s=0;
		scanf("%d-%d-%d",&y,&m,&d);
		while(m==2&&d==29)
		{
			y+=4;
			if(y%100==0&&y%400!=0)
				s+=365*4;
			else
				s+=365*3+366;
			if(s%7==0)	break;
		}
		while(m==1||(m==2&&d!=29))
		{
			if((y%4==0&&y%100!=0)||y%400==0)
				s+=366;
			else
				s+=365;
			y++;
			if(s%7==0)	break;
		}
		while(m>=3)
		{
			y++;
			if((y%4==0&&y%100!=0)||y%400==0)
				s+=366;
			else
				s+=365;
			if(s%7==0)	break;
		}
		printf("%d\n",y);
	}
	return 0;
}
