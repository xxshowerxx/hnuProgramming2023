#include<bits/stdc++.h>
using namespace std;
struct People
{
	string name;
	int score[7];
	int sum_score=0;
	int min_score=101;
	int max_score=0;
};
bool cmp(People a,People b)
{
	return a.sum_score>b.sum_score;
}
int main()
{
	int n;
	cin>>n;
	People *player=new People[n];
	for(int i=0;i<n;++i)
	{
		cin>>player[i].name;
		for(int j=0;j<7;++j)
		{
			cin>>player[i].score[j];
			if(player[i].score[j]>player[i].max_score)player[i].max_score=player[i].score[j];
			if(player[i].score[j]<player[i].min_score)player[i].min_score=player[i].score[j];
			player[i].sum_score+=player[i].score[j];
		}
		player[i].sum_score=player[i].sum_score-player[i].max_score-player[i].min_score;
	}
	sort(player,player+n,cmp);
	for(int i=0;i<n;++i)
		cout<<player[i].name<<" "<<player[i].sum_score<<endl;
	delete[] player;
	return 0;
}
