#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const long double Pi=3.1415926535;
int main()
{
	long double x,ans,t;
	int i=1;
	cin>>x;
	while(x>2*Pi)
		x-=2*Pi;
	while(x<-2*Pi)
		x+=2*Pi;
	ans=x;
	t=x;
	while(abs(t)>=5e-14)
	{
		t*=-1*x*x/(2*i)/(2*i+1);
		ans+=t;
		i++;
	}
	cout<<fixed<<setprecision(13)<<ans<<endl;
	return 0;
}
