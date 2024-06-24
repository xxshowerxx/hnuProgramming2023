#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int T;
	cin>>T;
	for(int i=0;i<T;++i)
	{
		string s;
		cin>>s;
		int flag=0;
		for(int j=0;j<(int)s.size();++j)
		{
			if(s[j]!='.'&&s[j]!='0')
			{
				for(int k=1;k<=s[j]-'0';++k)
				{
					if(j-k>=0)
					{
						if(s[j-k]!='.')
						{
							flag=1;
							break;
						}
						else s[j-k]='0';
					}
					if(j+k<(int)s.size())
					{
						if(s[j+k]!='.')
						{
							flag=1;
							break;
						}
						else s[j+k]='0';
					}
				}
			}
		}
		if(flag==1)cout<<"unsafe"<<endl;
		else cout<<"safe"<<endl; 
	}
    return 0;
}

