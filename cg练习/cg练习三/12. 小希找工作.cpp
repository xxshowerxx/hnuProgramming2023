#include<iostream>
using namespace std;
int main()
{
	int a[3],c[3],s[3];
	char b[3];
	for(int i=0;i<=2;++i)
		{
			cin>>a[i]>>b[i]>>c[i];
			s[i]=a[i]/5000*100;
			if(b[i]='y')	
				s[i]+=20;
			if(c[i]<=2000)
				s[i]+=100;
			else if(c[i]<=4000)
			{
				if(c[i]%200==0)
				s[i]+=100-(c[i]-2000)/200*10;
				else
				s[i]+=100-((c[i]-2000)/200+1)*10;
			}
			else	;
		}
	if(s[0]>=s[1]&&s[0]>=s[2])
		cout<<"A"<<endl;
	else if(s[1]>=s[0]&&s[1]>=s[2])
		cout<<"B"<<endl;
	else
		cout<<"C"<<endl;
	return 0;
}
