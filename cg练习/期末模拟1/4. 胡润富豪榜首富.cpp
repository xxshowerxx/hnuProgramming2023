#include<bits/stdc++.h>
using namespace std;
struct Candidate
{
	string name;
	int property;
};
int main()
{
	int N;
	cin>>N;
	Candidate *can=new Candidate[N];
	for(int i=0;i<N;++i)
		cin>>can[i].name>>can[i].property;
	sort(can,can+N,[](const Candidate&x,const Candidate&y)
	{
		return x.property>y.property;
	});
	cout<<can[0].name<<" "<<can[0].property<<endl;
 	return 0;
}

