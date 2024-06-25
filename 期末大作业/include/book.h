#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<vector>
using namespace std;
class user;
class book
{
    friend class library;
public:
    book() {}
    book(int i,long long I,string n,string a,string p,string d,double pr,int pa,int all)
        :id(i),ISBN(I),name(n),author(a),publisher(p),date(d),price(pr),pages(pa),allnum(all) {num=all;}

    void view();
    int lend(vector<user>::iterator &thisUser);
    int revise();
    int rlend(vector<user>::iterator &thisUser,int state);
    //UI整合

    bool operator ==(const string n)
    {
        return (this->name==n)||(this->author==n)||(this->publisher==n);
    }
    bool operator ==(const int i)
    {
        return (this->id==i);
    }
    bool operator ==(const long long i)
    {
        return (this->ISBN==i);
    }
    //运算符重载用于查找
private:
    string name;
    int id;
    long long ISBN;
    string author;
    string publisher;
    string date;
    int pages;
    double price;
    int allnum;
    int num;
    //基础数据

    vector<int>recordId;
    //借阅数据
};
#endif // BOOK_H
