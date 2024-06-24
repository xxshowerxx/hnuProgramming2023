#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string s1,s2,a;
	getline(cin,a);
	int i;
	for(i=0;i<(int)a.size();++i)
		if(a[i]>='0'&&a[i]<='9')
			continue;
		else if(a[i]==' ') break;
		else if(a[i]<='Z')s1+=a[i]-'A'+'a';
		else s1+=a[i];
	for(i=i+1;i<(int)a.size();++i)
		if(a[i]>='0'&&a[i]<='9')
			continue;
		else if(a[i]<='Z')s2+=a[i]-'A'+'a';
		else s2+=a[i];
	cout<<s2<<s1<<endl;
 	return 0;
}

