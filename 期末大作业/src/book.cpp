#include"library.h"
//书籍单条信息显示
void book::view()
{
    cout<<ISBN<<"\t"<<name<<"\t"<<author<<"\t"<<publisher<<"\t"<<date<<"\t"<<price<<"\t"<<pages<<"\t"<<recordId.size()<<"\t";
    cout<<"剩余"<<num<<"本\t当前借阅人数"<<allnum-num<<endl;
}
//书籍借阅
int book::lend(vector<user>::iterator &thisUser)
{
    cout<<"您要借阅的书籍信息："<<endl;
    view();
    if(num==0)
    {
        cout<<"当前书籍已借完，借阅失败！"<<endl;
        return 0;
    }
    if(thisUser->bookNum==3)
    {
        cout<<"每人同时只能借三本，您已借满，借阅失败！"<<endl;
        return 0;
    }
    cout<<"[Y]确认借阅;任意其他输入取消借阅"<<endl;
    char confirm;
    cin>>confirm;
    if(confirm!='Y')
        return 0;
    num-=1;
    thisUser->bookNum++;
    cout<<"借阅成功！"<<endl;
    return 1;
}
//书籍归还
int book::rlend(vector<user>::iterator &thisUser,int state)
{
    cout<<"借阅记录详细书籍信息："<<endl;
    cout<<"[1]ISBN"<<setw(7)<<" "<<setw(25)<<left<<"[2]书名"<<setw(10)<<left<<"[3]作者"<<setw(10)<<left
        <<"[4]出版社\t[5]出版日期\t[6]价格\t[7]页数\t[8]历史借阅人数\t[9]剩余数量\t[10]当前借阅人数"<<endl;
    view();
    if(state==0)
    {
        cout<<"当前书籍您已归还！"<<endl;
        return 0;
    }
    cout<<"当前书籍未归还，是否归还？"<<endl;
    cout<<"[Y]确认归还;任意其他输入取消归还"<<endl;
    char confirm;
    cin>>confirm;
    if(confirm!='Y')
        return 0;
    num+=1;
    thisUser->bookNum--;
    cout<<"归还成功！"<<endl;
    return 1;
}
//书籍修改
int book::revise()
{
    cout<<"您要修改的书籍信息："<<endl;
    view();
    cout<<"请选择你的操作：[1]修改书籍具体信息 [2]删除书籍 [3]添加书籍 任意其他输入取消修改"<<endl;
    int type;
    cin>>type;
    switch(type)
    {
    case 1:
    {
        while(1)
        {
            cout<<"请输入你要修改的具体信息：[0]全部[1]ISBN[2]书名[3]作者[4]出版社[5]出版日期[6]价格[7]页数[8]本数[9]取消"<<endl;
            int number;
            cin>>number;
            switch(number)
            {
            case 0:
            {
                stringstream sstream;
                cout<<"格式提示：ISBN\t书名\t作者\t出版社\t出版日期\t价格\t页数\t本数(以制表符为分隔)"<<endl;
                string stmp;
                cin.ignore();
                getline(cin,stmp);
                vector<string> res = split(stmp, '\t');
                name=res[1],author=res[2],publisher=res[3],date=res[4];
                sstream<<res[0]<<res[5]<<' '<<res[6]<<' '<<res[7];
                sstream>>ISBN>>price>>pages>>allnum;
                sstream.clear();
                sstream.str("");
                cout<<"修改成功！修改后的信息：";
                view();
                break;
            }
            case 1:
            {
                cout<<"请输入ISBN：";
                cin>>ISBN;
                cout<<"修改成功！修改后的信息：";
                view();
                break;
            }
            case 2:
            {
                cout<<"请输入书名：";
                cin.ignore();
                getline(cin,name);
                cout<<"修改成功！修改后的信息：";
                view();
                break;
            }
            case 3:
            {
                cout<<"请输入作者：";
                cin.ignore();
                getline(cin,author);
                cout<<"修改成功！修改后的信息：";
                view();
                break;
            }
            case 4:
            {
                cout<<"请输入出版社：";
                cin.ignore();
                getline(cin,publisher);
                cout<<"修改成功！修改后的信息：";
                view();
                break;
            }
            case 5:
            {
                cout<<"请输入出版日期：";
                cin>>date;
                cout<<"修改成功！修改后的信息：";
                view();
                break;
            }
            case 6:
            {
                cout<<"请输入价格：";
                cin>>price;
                cout<<"修改成功！修改后的信息：";
                view();
                break;
            }
            case 7:
            {
                cout<<"请输入页数：";
                cin>>pages;
                cout<<"修改成功！修改后的信息：";
                view();
                break;
            }
            case 8:
                {
                    cout<<"请输入本数：";
                    int o;
                    cin>>allnum;
                    num+=allnum-o;
                    cout<<"修改成功！修改后的信息：";
                    view();
                    break;
                }
            case 9:
            {
                return 0;
                break;
            }
            default:
                cout<<"输入错误，请重新输入！"<<endl;
            }

        }
        break;
    }
    case 2:
    {
        if(num!=allnum)
        {
            cout<<"当前书籍仍有未归还记录，无法删除！"<<endl;
            return 0;
        }
        cout<<"确定删除[Y]；任意其他输入取消删除"<<endl;
        char confirm;
        cin>>confirm;
        if(confirm=='Y')
            return 1;
        else
            return 0;
        break;
    }
    case 3:
    {
        cout<<"请输入你要添加的本数：";
        int n;
        cin>>n;
        num+=n;
        allnum+=n;
        cout<<"修改成功！修改后的信息：";
        view();
    }
    }
    return 0;
}
//书籍添加不宜作为书籍类的成员函数
