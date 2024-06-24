#include<bits/stdc++.h>
using namespace std;
char s[10001];
int main()
{
	int i,end=0,first=0;
	cin>>s>>i;
	for(int j=i;s[j]!=0;++j)
	{
		int cnt=0;
		while(s[j]<='9'&&s[j]>='0')
		{
			cnt++;
			j++;
		}
		if(cnt!=0)
		{
			end=j-1;
			first=end-cnt+1;
			break;
		}
	}
	cout<<first<<" "<<end<<endl;
	return 0;
}
