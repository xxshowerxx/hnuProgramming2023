#ifndef RECORD_H
#define RECORD_H
#include<iostream>
using namespace std;
class record
{
public:
    friend class library;
    record() {}
    record(int i,int bi,int ui,int s,time_t t1,time_t t2):id(i),bookId(bi),userId(ui),state(s),timeBorrow(t1),timeBack(t2){}
    void userView();
    void adminView();
    bool operator ==(const int i)
    {
        return (this->id==i);
    }
    //重载运算符，用于查找
private:
    int state;
    int id;
    int bookId;
    int userId;
    time_t timeBorrow,timeBack;
    //借阅记录
};

#endif // RECORD_H
