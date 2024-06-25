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
    //运算符重载用于查找
private:
    int id;
    string password;
    string name;
    //基础数据
};

#endif // ADMIN_H
