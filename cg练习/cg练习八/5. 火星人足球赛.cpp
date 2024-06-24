#include<iostream>
#include<algorithm>
using namespace std;
string h,a;
struct people
{
	int id,time;
	char color,team;
};
string name(char c)
{
	if(c=='h')return h;
	else return a;
}
bool cmp(people a,people b)
{
	if(a.time!=b.time)return a.time<b.time;
	if(a.team!=b.team)return a.team>b.team;
	return a.id>b.id;
}
int main()
{
	cin>>h>>a;
	int n;
	cin>>n;
	people *player=new people[n];
	for(int i=0;i<n;++i)
	{
		cin>>player[i].time>>player[i].team>>player[i].id>>player[i].color;
		if(player[i].color=='y')
		{
			for(int j=0;j<i;++j)
			{
				if(player[j].team==player[i].team&&player[j].id==player[i].id)
				{
					player[i].color='r';
					break;
				}
			}
		}
	}
	sort(player,player+n,cmp);
	int flag=0;
	for(int i=0;i<n;++i)
	{
		if(player[i].color!='y')
		{	
			flag=1;
			cout<<name(player[i].team)<<" "<<player[i].id<<" "<<player[i].time<<endl;
		}
	}
	if(flag==0)cout<<"No Red Card"<<endl;
}
