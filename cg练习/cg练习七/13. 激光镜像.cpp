#include<bits/stdc++.h>
using namespace std;
int net[1001][1001];
struct D
{
	int dx,dy;
}dir[4]={{1,1},{1,-1},{-1,-1},{-1,1}};
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;++i)
	{
		int x,y;
		cin>>x>>y;
		net[x][y]=-1;
	}
	for(int i=0;i<=m+1;++i)
		net[0][i]=-1;
	for(int i=0;i<=n+1;++i)
		net[i][0]=-1;
	for(int i=0;i<=m+1;++i)
		net[n+1][i]=-1;
	for(int i=0;i<=n+1;++i)
		net[i][m+1]=-1;
	int xs,ys,index;
	string s;
	cin>>xs>>ys>>s;
	if(s=="SE") index=0;
	else if(s=="NE") index=1;
	else if(s=="NW") index=2;
	else index=3;
	int sum=1,x=xs,y=ys,index0=index;
	net[xs][ys]=1;
	do
	{
		if(net[x+dir[index].dx][y+dir[index].dy]==-1)
		{
			if((net[x][y+dir[index].dy]==-1&&net[x+dir[index].dx][y]==-1)||(net[x][y+dir[index].dy]!=-1&&net[x+dir[index].dx][y]!=-1))
				index=(index+2)%4;
			else
			{
				if(net[x][y+dir[index].dy]!=-1)
				{
					y+=dir[index].dy;
					if(dir[(index+1)%4].dy==dir[index].dy) index=(index+1)%4;
					else index=(index+3)%4;
				}
				else
				{
					x+=dir[index].dx;
					if(dir[(index+1)%4].dx==dir[index].dx) index=(index+1)%4;
					else index=(index+3)%4;
				}
			}
		}
		else 
		{
			x+=dir[index].dx;
			y+=dir[index].dy;
		} 
		if(net[x][y]==0)
			sum++;
		net[x][y]++;
	}
	while(xs!=x||ys!=y||index!=index0);
	cout<<sum<<endl;
	return 0;
}
