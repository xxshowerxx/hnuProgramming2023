#include <iostream>
using namespace std;
class person
{
	private:
		int no; /* �˵ı�� */ 
		person *next; /* ָ�����ڵ���һ���� */
	public:
		person(int num)
		{
			no=num;
			next=NULL;
		} 
		void setNext(person *p)
		{
			next=p;
		} 
		int getNo()
		{
			return no;
		} 
		person *getNext()
		{
			return next;
		}
};
class cycle
{
	private:
		person *start; /* ��ʼ������λ�� */ 
		int out; /* ���������� */ 
		int inQueue; /* �������������� */
	public:
		cycle(int num, int from, int whoOut)
		{
			inQueue=num, out=whoOut;
			person *prv=NULL, *first=NULL;
			for(int i=1; i<=num; i++)
			{
				person *p=new person(i);
				if (i==1) first=p;
				if (i==from) start=p;
				if (i>1) prv->setNext(p);
				prv=p;
			}
			prv->setNext(first);
		} 
		int getInQueue()
		{
			return inQueue;
		} 
		void cnt() /* ������ĿҪ��������ȷ�����е��ˣ������˴�Ȧ���޳� */
		{ 
			person *prv=start,*Next=start;
			while(prv->getNext()!=start)
				prv=prv->getNext();
			for(int i=1;i<out;++i)
			{
				prv=prv->getNext();
				Next=Next->getNext();
			}
			prv->setNext(Next->getNext());
			delete Next;
			inQueue--;
		} 
		person *getStart()
		{
			return start;
		} 
		~cycle()
		{
			delete start;
		}
};
int main()
{
	int n,k, m ; /* n Ȧ������ k ��ʼ���� m �������� */ 
	cin>>n>>k>>m;
	cycle *p=new cycle(n,k,m);
	while(p->getInQueue()>1) 
		p->cnt();
	person *winer=p->getStart();
	cout<<winer->getNo()<<endl;
	delete p;
	return 0;
}
