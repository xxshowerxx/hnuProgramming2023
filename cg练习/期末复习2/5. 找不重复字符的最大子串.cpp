#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int l=0,r=1,sum=1,max=0;
	while(r<(int)s.size())
	{
		int temp;
		for(temp=l;temp<r;++temp)
		{
			if(s[temp]==s[r])
				break;
		}
		if(temp<r)
		{
			if(sum>max)max=sum;
			l=temp+1;
			sum=r-l+1;
			r=r+1;
		}
		else
		{
			sum++;
			r++;
		}
	}
	if(sum>max)max=sum;
	cout<<max<<endl;
 	return 0;
}

