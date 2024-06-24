#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;++i)
	{
		int n,m,x1,y1,x2,y2;
		cin>>n>>m>>x1>>y1>>x2>>y2;
		int cnt=0;
		for(int x=1;x<=n;++x)
		{
			for(int y=1;y<=m;++y)
			{
				if(((x+x1-x2>=1)&&(x+x1-x2<=n)&&(y+y1-y2>=1)&&(y+y1-y2<=m))||((x+x2-x1>=1)&&(x+x2-x1<=n)&&(y+y2-y1>=1)&&(y+y2-y1<=m)))
					continue;
				else
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
