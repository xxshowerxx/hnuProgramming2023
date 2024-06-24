#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
	if(x<y)swap(x,y);
	if(x%y==0)return y;
	else return gcd(y,x%y);
}
void fs(string s,long long &fz,long long &fm,int flag)
{
	fz=atoi(s.c_str());
	if(fz==0)return;
	fm=pow(10,s.size())-flag;
	long long ys=gcd(fm,fz);
	fm/=ys,fz/=ys;
	return;
}
void addfs(long long *fz,long long *fm)
{
	if(fz[0]==0)
	{
		fz[2]=fz[1],fm[2]=fm[1];
		cout<<fz[2]<<"/"<<fm[2]<<endl;
		return;
	}
	if(fz[1]==0)
	{
		fz[2]=fz[0],fm[2]=fm[0];
		cout<<fz[2]<<"/"<<fm[2]<<endl;
		return;
	}
	long long ys1=gcd(fm[0],fm[1]);
	fm[2]=fm[0]*fm[1]/ys1;
	fz[2]=fm[0]*fz[1]/ys1+fm[1]*fz[0]/ys1;
	long long ys2=gcd(fm[2],fz[2]);
	fz[2]/=ys2,fm[2]/=ys2;
	cout<<fz[2]<<"/"<<fm[2]<<endl;
	return;
}
int main()
{
	int N;
	cin>>N;
	getchar();
	for(int i=0;i<N;++i)
	{
		string s;
		getline(cin,s);
		long long fz[3]={0,0,0},fm[3]={0,0,0};
		string sub[2];
		if(s.find('(')==string::npos)
		{
			sub[0]=s.substr(2);
			sub[1]='0';
		}
		else
		{
			if(s[2]=='(')
			{       
				sub[0]='0';
				sub[1]=s.substr(3,s.size()-4);
			}
			else
			{
				sub[0]=s.substr(2,s.find('(')-2);
				sub[1]=s.substr(s.find('(')+1,s.size()-4-sub[0].size());
			}
		}
		for(int j=0;j<2;++j)
			fs(sub[j],fz[j],fm[j],j);
		if(sub[0]!="0"&&sub[1]!="0")
			fm[1]*=pow(10,sub[0].size());
		addfs(fz,fm);
	}
	return 0;
}
