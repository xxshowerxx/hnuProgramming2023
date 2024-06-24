#include<iostream>
using namespace std;
int main()
{
	int in,ft=0,yd=0,mi=0;
	cin>>in;
	ft=in/12;
	in%=12;
	yd=ft/3;
	ft%=3;
	mi=yd/1760;
	yd%=1760;
	if(mi!=0)
		cout<<mi<<" mi ";
	if(yd!=0)
		cout<<yd<<" yd ";
	if(ft!=0)
		cout<<ft<<" ft ";
	if(in!=0)
		cout<<in<<" in ";
	return 0;
}
