//����Ĵ��붨���˽ṹָ�룬ͨ���ṹָ�������ʽṹ��Ա
#include<iostream>
#include<string>
#include <cstring>
using namespace std;
struct Person
{
	char name[20];
	unsigned long id;
	float salary;
};
int main()
{
	Person pr1;
	Person *prPtr=&pr1;
	char a[20];
	cin>>a;
	strcpy(prPtr->name,a);
	cin>>prPtr->id;
	cin>>prPtr->salary;
	cout<<prPtr->name<<" "<<prPtr->id<<" "<<prPtr->salary<<endl;
}
