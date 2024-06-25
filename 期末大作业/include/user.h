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
    //UI����

    bool operator ==(string n)
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

    vector<int>recordId;
    int bookNum=0;
    //��������

    void privateView();
    //�����������ʾ
};

#endif // USER_H
