#include<bits/stdc++.h>
using namespace std;
unordered_map<char,string> period;
int x[3]={1,1,0},y[3]={0,1,1};
char a[10001][10001];
int r,c;
vector<char> qfirst;
void near(int xi,int yi)
{
	for(int i=0;i<3;++i)
		if(xi+x[i]<r&&yi+y[i]<c&&a[xi+x[i]][yi+y[i]]!=a[xi][yi])
		{
			if(period.find(a[xi+x[i]][yi+y[i]])==period.end()||period[a[xi+x[i]][yi+y[i]]].find(a[xi][yi])==string::npos)
				period[a[xi+x[i]][yi+y[i]]]+=a[xi][yi];
			if(period.find(a[xi][yi])==period.end()||period[a[xi][yi]].find(a[xi+x[i]][yi+y[i]])==string::npos)
				period[a[xi][yi]]+=a[xi+x[i]][yi+y[i]];
		}
}
int step(char first,char next)
{
	if(first==next) return 0;
	if(period[first].find(next)!=string::npos) return 1;
	int min=INT_MAX-1;
	for(int i=0;i<(int)period[first].size();++i)
	{
		if(qfirst.empty()||find(qfirst.begin(),qfirst.end(),period[first][i])==qfirst.end())
		{
			qfirst.push_back(first);
			int t=step(period[first][i],next)+1;
			if(t<min) min=t;
			qfirst.pop_back();
		}
	}
	return min;
}
int main()
{
	string s;
	cin>>r>>c;
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
			cin>>a[i][j];
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
			near(i,j);
	cin>>s;
	char t=a[0][0];
	int ans=0;
	for(int i=0;i<(int)s.size();++i)
	{
		ans+=step(t,s[i])+1;
		t=s[i];
	}
	ans+=step(t,'*');
	cout<<ans<<endl;
 	return 0;
}

