#include <iostream>
using namespace std;
struct Person
{
	char name[20];
	unsigned long id;
	float salary;
};// ��д�Խṹ��ֵ��Ϊ�βεĺ�������ָ����ʽ��ӡ�ṹ������
void print(Person pr)
{
	cout<<pr.name<<" "<<pr.id<<" "<<pr.salary<<endl;
}
Person allone[6]= { {"jone",12345,339.0}, {"david",13916,449.0}, {"marit",27519,311.0}, {"jasen",42876,623.0}, {"peter",23987,400.0}, {"yoke",12335,511.0} };
int main()
{

// ѭ������print������ӡallone����
	for(int i=0; i<6; ++i)
	{
		print(allone[i]);
	}
	return 0;
}

