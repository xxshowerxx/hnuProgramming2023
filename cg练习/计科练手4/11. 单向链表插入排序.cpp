#include<bits/stdc++.h>
using namespace std;
struct List
{
	int id,age;
	string name,sex;
	List *next;
};
int main()
{
	List *head=new List,*pE=head;
	for(int i=0;i<10;++i)
	{
		List *temp=new List;
		cin>>temp->name>>temp->id>>temp->sex>>temp->age;
		pE->next=temp;
		pE=temp;
		if(i==9) pE->next=NULL;
	}
	cout<<"Before ordering(id|age|name|sex)\n";
	List *p=head->next;
	for(int i=0;i<10;++i)
	{
		printf("(%d|%d|%s|%s)\n",p->id,p->age,p->name.c_str(),p->sex.c_str());
		p=p->next;
	}
	List *prev=head,*last=head->next,*cur=last->next;
	int n=1; 
	while(cur!=NULL)
	{
		if(last->id<=cur->id)
		{
			last=last->next;
			cur=last->next;
		}
		else
		{
			prev=head;
			while(prev->next->id<=cur->id)
				prev=prev->next;
			last->next=cur->next;
			cur->next=prev->next;
			prev->next=cur;
			cur=last->next;
			cout<<n++<<endl;
			p=head->next;
			for(int i=0;i<10;++i)
			{
				printf("(%d|%d|%s|%s)\n",p->id,p->age,p->name.c_str(),p->sex.c_str());
				p=p->next;
			}
		}
	}
	cout<<"After ordering(id|age|name|sex)\n";
	p=head->next;
	for(int i=0;i<10;++i)
	{
		printf("(%d|%d|%s|%s)\n",p->id,p->age,p->name.c_str(),p->sex.c_str());
		p=p->next;
	}
	return 0;
}
