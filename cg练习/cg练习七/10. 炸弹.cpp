#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int T;
	cin>>T;
	for(int i=0;i<T;++i)
	{
		int n,m,markx[2],marky[2],flag[2]={0,0},t=0;
		cin>>n>>m;
		char map[1001][1001];
		for(int x=0;x<n;++x)
		{
			for(int y=0;y<m;++y)
			{
				cin>>map[x][y];
				if(map[x][y]=='*')
				{
					if(t<2)
					{
						markx[t]=x;
						marky[t]=y;
						t++;
					}
					else
					{
						if(markx[0]==markx[1])
						{
							if(x==markx[0])	continue;
							else
							{
								if(y!=marky[0]) flag[0]=1;
								if(y!=marky[1]) flag[1]=1;
							}
						}
						else if(marky[0]==marky[1])
						{
							if(y==marky[0])	continue;
							else
							{
								if(x!=markx[0]) flag[0]=1;
								if(x!=markx[1]) flag[1]=1;
							}
						}
						else 
						{
							if(x!=markx[0]||y!=marky[1]) flag[0]=1;
							if(x!=markx[1]||y!=marky[0]) flag[1]=1;
						}
					}
				}
			}
		}
		if(flag[0]==0||flag[1]==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
    return 0;
}

