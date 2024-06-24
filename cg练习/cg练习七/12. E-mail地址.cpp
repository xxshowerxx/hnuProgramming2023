#include<bits/stdc++.h>
using namespace std;
int typechar(char c)
{
	if(c>='0'&&c<='9')return 1;
	else if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))return 2;
	else if(c=='.') return 3;
	else if(c=='@') return 4;
	else return 0;
}
int main()
{
	string s;
	cin>>s;
	int sum=0;
	while(s.find('@')!=string::npos&&s.find('.')!=string::npos)
	{
		if(s.find('.')<s.find('@'))
		{
			s.erase(s.begin(),s.begin()+s.find('.')+1);
		}
		else
		{
			int t=s.find('@'),suml=0,sumr=0,flag=1,i;
			for(i=0;i<t;++i)
			{
				if(typechar(s[i])==2)
				{
					suml++;
				}
			}
			i++;
			for(;i<(int)s.find('.');++i)
			{
				if(typechar(s[i])>2)
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				while(typechar(s[++i])==2) sumr++;
			}
			sum+=suml*sumr;
			s.erase(s.begin(),s.begin()+s.find('.')+1);
		}
	}
	cout<<sum<<endl;
	return 0;
}
