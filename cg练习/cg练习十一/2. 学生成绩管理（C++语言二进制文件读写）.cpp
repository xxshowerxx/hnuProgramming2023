#include <iostream>
#include <fstream>
using namespace std;
/* ����ṹ��student���ڱ�ʾѧ���Ļ�����Ϣ����������ṹ*/
struct student
{
	int no; // ѧ��
	char name[20], sex; // �����Լ��Ա�, ��˼�������name[20]�޸�Ϊ*name������������������ʺϱ���Ĵ���ʽ��
	int age; // ����
	float chinese, computer; // ��ʾ���ſγ̵ĳɼ�
	student *next;
	bool operator<(const student &another) const // ��������� < (С��)�����ڽṹ�����֮��ıȽϣ���LinkSort�бȽ�����������ڵ��С
	{
		return (chinese+computer)<(another.chinese+another.computer);
	}
};
student* ReadFile(ifstream& infile, student *head, int &n); // �Ӷ������ļ�(�ļ�ָ��Ϊfp)�н��������ݶ��룬�洢����headΪͷָ���������
void display(student *head); // ������ʾ���������
void WriteFile(ofstream& outfile, student *head); // ����headΪͷָ��������е�����д��������ļ�(�ļ�ָ��Ϊfp)
student* input(student *head, int &n); // �����µ����ݣ������������ӵ�����ĩβ
student* LinkSort(student *head, const int &n); // ʵ�ֶ���������򣬰��ܳɼ��Ӵ�С���У�ð������
void swapNode(student *s, student *q); // ʵ�ֶ�����ڵ�����ݽ�������������, �ں���LinkSort�е���
int main()
{
	int n = 0;
	student *head = NULL;
	ifstream getf;
	getf.open("grade.bin",ios::binary);
	head = ReadFile(getf, head, n);
	display(head);
	getf.close();
	head = input(head, n);
	head = LinkSort(head, n);
	ofstream putf;
	putf.open("grade.bin",ios::binary);
	WriteFile(putf, head);
	putf.close();
	return 0;
}
student* ReadFile(ifstream& infile, student* head, int &n) 
{
	student *q=head;
	if(head)
	{
		while(q->next)q=q->next;
	}
	while(1)
	{
		student *p=new student;
		if(!infile.read(reinterpret_cast<char*>(p), sizeof(p)))
		{
			delete p;
			break;
		}
		p->next=NULL;
		if(!head) head=p;
		else q->next=p;
		q=p;
		n++;
	}
	return head;
} 
void display(student* head)
{
	student *p = head;
	while(p)
	{
		printf("No: %d\n", p->no);
		printf("Name: %s\n", p->name);
		printf("Sex: %c\n", p->sex);
		printf("Age: %d\n", p->age);
		printf("Scores: %f %f\n\n", p->chinese, p->computer);
		p = p->next;
	}
}
student* input(student* head, int &n)
{
	student *q = head;
	if (head) while(q->next) q = q->next;
	while(1)
	{
		printf("Input continue(y/n)?");
		if (getchar() != 'y') break;
		student *p = new student;
		printf("No: ");
		scanf("%d", &p->no);
		getchar();
		printf("Name: "); //
		gets(p->name);
		cin.getline(p->name, 20);
		printf("Sex(M/F): ");
		p->sex = getchar();
		printf("Age: ");
		scanf("%d", &p->age);
		printf("Chinese score: ");
		scanf("%f", &p->chinese);
		printf("Computer score: ");
		scanf("%f", &p->computer);
		p->next = NULL;
		getchar();
		if (!head) head = p;
		else q->next = p;
		q = p;
		n++;
	}
	return head;
}
student* LinkSort(student* head, const int &n)
{
	student *p;
	for(int i = 1; i <= n - 1; i++)
	{
		p = head;
		for(int j = 1; j <= n - i; j++)
		{
			if (*p < *p->next)
			{
				swapNode(p,p->next);
			}
			p = p->next;
		}
	}
	return head;
}
void swapNode(student* s, student* q)
{
	student *snext = s->next, *qnext = q->next, tmp;
	tmp = *s;
	*s = *q;
	*q = tmp;
	s->next = snext;
	q->next = qnext;
}
void WriteFile(ofstream& outfile, student* head)
{
 	while(head)
 	{
 		outfile.write(reinterpret_cast<const char*>(head), sizeof(head)); 
 		head=head->next;
	}
}
