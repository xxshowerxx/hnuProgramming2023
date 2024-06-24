#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a%3==0)
	{
		if(a%5==0)
		{
			if(a%7==0)
				cout<<"It's divisible by 3,5,7"<<endl;
			else
				cout<<"It's divisible by 3,5"<<endl;
		}
		else if(a%7==0)
			cout<<"It's divisible by 3,7"<<endl;
		else
			cout<<"It's divisible by 3"<<endl;
	}
	else if(a%5==0)
	{
		if(a%7==0)
			cout<<"It's divisible by 5,7"<<endl;
		else
			cout<<"It's divisible by 5"<<endl;
	}
	else if(a%7==0)
		cout<<"It's divisible by 7"<<endl;
	else
		cout<<"null"<<endl;
	return 0;
}
