#include<iostream>
using namespace std;
int main()
{
	int a,c,t=0;
	char b;
	cin>>a>>b>>c;
	if(a>=5000)t++;
	if(b=='y')t++;
	if(c<=2000)t++;
	if(t>=2)cout<<"Accept"<<endl;
	else cout<<"Refuse"<<endl;
	return 0;
}
