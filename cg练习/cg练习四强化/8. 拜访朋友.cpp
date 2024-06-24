#include<iostream>
#include<algorithm> 
using namespace std;
struct bus
{
	int a;
	int b;
}box[100001];
bool cmp(bus x,bus y)
{
	return	x.a<y.a;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>box[i].a>>box[i].b;
	sort(box,box+n,cmp);
	int back=0;
	int i=0;
	while(back>=box[i].a&&i<n)
	{
		if(box[i].b>back)	back=box[i].b;
		i++;
	}
	if(back<m)	cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}
