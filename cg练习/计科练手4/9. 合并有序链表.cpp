#include <iostream>
using namespace std;
typedef struct LNode* PtrToLNode;
struct LNode
{
	int data;
	PtrToLNode next;
};
PtrToLNode mergeList(PtrToLNode head1, PtrToLNode head2)
{
	PtrToLNode head3=new LNode;
	PtrToLNode pa=head1->next,pb=head2->next,pc=head3;
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pc->next;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pc->next;
			pb=pb->next;
		}
	}
	if(pa!=NULL)pc->next=pa;
	else pc->next=pb;
	return head3;
}
void printList(PtrToLNode head)
{
	PtrToLNode p = head->next;
	while(p!=NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	int data[2][8] = {{-484, 0, 10, 45, 371, 425, 895, 908},{0, 3, 12, 50, 900, 999, 1024, 2048}};
	int arrSize = sizeof(data[0])/sizeof(data[0][0]); // ������ data ������ͷ����Ϊһ����������
	PtrToLNode head1, head2, p, tail;
	head1 = tail = new struct LNode;
	for(int i = 0; i < arrSize; i++)
	{
		p = new struct LNode;
		p->data = data[0][i];
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	
	head2 = tail = new struct LNode;
	for(int i = 0; i < arrSize; i++)
	{
		p = new struct LNode;
		p->data = data[1][i];
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	// �ϲ���������
	PtrToLNode head = mergeList(head1, head2); // ˳���ӡ������������и����ڵ��data����
	printList(head);
// �ͷ�����ռ�
	while(head->next!=NULL)
	{
		p = head->next;
		head->next = p->next;
		delete p;
	}
	delete head;
	return 0;
}
