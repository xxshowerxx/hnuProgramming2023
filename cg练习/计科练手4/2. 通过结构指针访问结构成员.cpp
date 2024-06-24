//下面的代码定义了结构指针，通过结构指针来访问结构成员
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
