#include<iostream>
using namespace std;
long long dp[21][21];
int dx[9]={1,2,2,1,-1,-2,-2,-1,0},dy[9]={2,1,-1,-2,-2,-1,1,2,0};
int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	dp[0][0]=1;
	for(int i=0;i<9;++i)
	{
		if(x+dx[i]<=n&&x+dx[i]>=0&&y+dy[i]<=m&&y+dy[i]>=0)
			dp[dx[i]+x][dy[i]+y]=-1;
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=m;++j)
		{
			if(dp[i][j]!=-1)
			{
				if(i-1>=0)
					dp[i][j]+=dp[i-1][j];
				if(j-1>=0)
					dp[i][j]+=dp[i][j-1];
			}
			else dp[i][j]=0;
		}
	}
	cout<<dp[n][m]<<endl;
}
