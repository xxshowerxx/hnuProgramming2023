#include "library.h"
void user::view()
{
    cout<<id<<"\t"<<name<<"\t"<<recordId.size()<<"\t"<<bookNum<<endl;
}
void user::privateView()
{
    cout<<id<<"\t"<<name<<"\t"<<password<<"\t"<<recordId.size()<<"\t"<<bookNum<<endl;
}
