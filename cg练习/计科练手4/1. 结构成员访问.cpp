//下面的程序说明了访问结构成员的方法
#include<iostream>
using namespace std;
struct Weather
{
	double Temp,Wind;
};
int main()
{
	Weather today;//按照题目补全代码
	cin>>today.Temp>>today.Wind;
	cout<<"Temp="<<today.Temp<<endl<<"Wind="<<today.Wind<<endl;
}
