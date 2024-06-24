#include <iostream>
using namespace std;
struct Student
{
	string name;
	Student* next;
};
void addStudent(Student* head, Student* s)
{
// 编写函数实现题目所描述的功能
	Student* p=head->next;
	while(p->next!=NULL)
	{
		if(p->next->name=="jone")
		{
			s->next=p->next;
			p->next=s;
			return;
		}
		p=p->next;
	}
	p->next=s;
	return;
}
int main()
{
	Student* head = new Student;
	head->next = nullptr;
	head->name = "";
	Student* pre = head;
	for (int i = 0; i < 5; i++)
	{
		Student* s = new Student;
		string temp;
		cin >> temp;
		s->name = temp;
		s->next = nullptr;
		pre->next = s;
		pre = s;
	}
	string name;
	cin >> name;
	Student* s = new Student;
	s->name = name;
	s->next = nullptr;
	addStudent(head,s);
	for(Student* p = head->next; p; p = p->next)
		// 循环输出
	{
		cout<< p->name << " ";
	}
	return 0;
}

