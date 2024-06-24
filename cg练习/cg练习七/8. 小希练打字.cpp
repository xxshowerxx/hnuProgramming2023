#include<bits/stdc++.h>
using namespace std;
string l="qwertasdfgzxcvbQWERTASDFGZXCVB";
string s[1001];
double a[1001];
int main() 
{
	int N;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>s[i];
		for(int j=0;j<i;++j)
			if(s[j]==s[i])
			{
				a[i]=a[j]/2.0;
				break;
			}
		if(a[i]==0)
		{
			a[i]=0.2;
			int flag;
			if(l.find(s[i][0])!=string::npos)
			{
				flag=-1;
			}
			else flag=1;
			for(int j=1;j<(int)s[i].size();++j)
			{
				if(l.find(s[i][j])!=string::npos&&flag==-1)
					a[i]+=0.4;
				else if(l.find(s[i][j])==string::npos&&flag==1)
					a[i]+=0.4;
				else
				{
					a[i]+=0.2;
					flag*=-1;
				}
			}
		}
	}
	double sum=0;
	for(int i=0;i<N;++i)
		sum+=a[i];
	sum*=10;
	cout<<sum<<endl;
    return 0;
}

