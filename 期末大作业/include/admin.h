#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
using namespace std;
class admin
{
    friend class library;
public:
    admin(int i,string n,string p):id(i),name(n),password(p) {}
    void view();
    bool operator ==(const string n)
    {
        return (this->name==n);
    }
    bool operator ==(const int i)
    {
        return (this->id==i);
    }
    //������������ڲ���
private:
    int id;
    string password;
    string name;
    //��������
};

#endif // ADMIN_H
