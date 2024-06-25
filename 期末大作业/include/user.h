#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;
class user
{
    friend class library;
    friend class book;
public:
    user();
    user(int i,string n,string p):id(i),name(n),password(p) {}

    void view();
    //UI整合

    bool operator ==(string n)
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

    vector<int>recordId;
    int bookNum=0;
    //借阅数据

    void privateView();
    //包含密码的显示
};

#endif // USER_H
