//����ĳ���˵���˷��ʽṹ��Ա�ķ���
#include<iostream>
using namespace std;
struct Weather
{
	double Temp,Wind;
};
int main()
{
	Weather today;//������Ŀ��ȫ����
	cin>>today.Temp>>today.Wind;
	cout<<"Temp="<<today.Temp<<endl<<"Wind="<<today.Wind<<endl;
}
