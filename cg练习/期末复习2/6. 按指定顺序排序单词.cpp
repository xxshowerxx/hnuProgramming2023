#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
int main()
{
	
	string s,a[9];
	getline(cin,s);
	stringstream sstream;
	sstream<<s;
	int i=0;
	while(sstream>>a[i])
	{
		i++;
	}
	i-=1;
	sort(a,a+i+1,[](string x,string y)
	{
		return x[(int)x.size()-1]<y[(int)y.size()-1];
	});
	for(int j=0;j<i;++j)
	{
		a[j].pop_back();
		cout<<a[j]<<" ";
	}
	a[i].pop_back();
	cout<<a[i];
 	return 0;
}

