#include <iostream>
#include <cstring>
using namespace std;
struct student
{
	int no;
	char name[20];
	char sex;
	float score;
	student *next;
};
student *head=NULL,*p;
//����ͷָ�붨��
void create(int No, char *Name, char Sex, float Score);
void show();
int main()
{
	int No;
	char Sex, Name[20];
	float Score;
	while(cin>>No>>Name>>Sex>>Score)
	{
		create(No, Name, Sex, Score);
	}
	show();
	return 0;
}
void create(int No, char *Name, char Sex, float Score)
{
	student *newNode;
	newNode=new student;
	newNode->no=No;
	strcpy(newNode->name,Name);
	newNode->sex=Sex;
	newNode->score=Score;
	newNode->next=NULL; // �����½ڵ�
	if (head==NULL)
	{
		head=newNode;
		return;
	}
	if(head->next==NULL)p=head;
	p->next=newNode;
	p=p->next; //�½ڵ��������
}
void show()
{
	student *pi=head;
	while(pi!=NULL)
	{
		cout<<pi->no<<" "<<pi->name<<" ";
		if(pi->sex=='f')cout<<"Girl ";
		else cout<<"Boy ";
		cout<<pi->score<<endl;
		pi=pi->next;
	} // ���
}
