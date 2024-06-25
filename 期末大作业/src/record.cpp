#include "library.h"
//给定时间格式化输出
void getTime(time_t &timep)
{
    struct tm *p;
    p = localtime(&timep);
    printf("%d/%d/%d %02d:%02d:%02d\t",1900 + p->tm_year, 1+ p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec);
}
void record::userView()
{
    cout<<bookId<<"\t";
    if(state==0)
    {
        cout<<"已归还\t";
        getTime(timeBorrow);
        getTime(timeBack);
        cout<<endl;
    }
    else
    {
        cout<<"借阅中\t";
        getTime(timeBorrow);
        cout<<"无"<<endl;
    }

}
void record::adminView()
{
    cout<<bookId<<"\t"<<userId<<"\t";
    if(state==0)
    {
        cout<<"已归还\t";
        getTime(timeBorrow);
        getTime(timeBack);
        cout<<endl;
    }
    else
    {
        cout<<"借阅中\t";
        getTime(timeBorrow);
        cout<<"无"<<endl;
    }
}
