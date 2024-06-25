#include"library.h"
//封装好的以特定字符分隔整行字符串，用于读入文件
vector<string> split(const string& s, char sep)
{
    istringstream iss(s);
    vector<string> res;
    string buffer;
    while(getline(iss, buffer, sep))
    {
        res.push_back(buffer);
    }
    return res;
}
//获取当前时间
void getTime()
{
    time_t timep;
    time(&timep);
    struct tm *p;
    p = localtime(&timep);
    printf("当前时间：%d/%d/%d %02d:%02d:%02d\n",1900 + p->tm_year, 1+ p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec);
}
//library构造函数，初始化读入文件
library::library()
{
    bookInitial();
    userInitial();
    adminInitial();
    recordInitial();
}
//book初始化读入文件
void library::bookInitial()
{
    ifstream ifBook(".\\data\\book.txt",ios::in);
    if(!ifBook.is_open())
    {
        cout<<"未找到书籍文件！"<<endl;
        ifBook.close();
        exit(-1);
    }
    string stmp;
    getline(ifBook,stmp);
    if(ifBook.eof())
    {
        cout<<"暂无存书！请管理员添加书籍！"<<endl;
        ifBook.close();
        return;
    }
    stringstream sstream;
    int id,pages,allnum;
    long long ISBN;
    string name,author,date,publisher;
    double price;
    while(getline(ifBook,stmp))
    {
        vector<string> res = split(stmp, '\t');
        name=res[2],author=res[3],publisher=res[4],date=res[5];
        sstream<<res[0]<<' '<<res[1]<<' '<<res[6]<<' '<<res[7]<<' '<<res[8];
        sstream>>id>>ISBN>>price>>pages>>allnum;
        book btmp(id,ISBN,name,author,publisher,date,price,pages,allnum);
        sstream.clear();
        sstream.str("");
        hbook.push_back(btmp);
    }
    ifBook.close();
}
//user初始化读入文件
void library::userInitial()
{
    ifstream ifUser(".\\data\\user.txt",ios::in);
    if(!ifUser.is_open())
    {
        cout<<"未找到读者文件！"<<endl;
        ifUser.close();
        exit(-1);
    }
    string stmp;
    getline(ifUser,stmp);
    if(ifUser.eof())
    {
        cout<<"暂无读者！请注册！"<<endl;
        ifUser.close();
        return;
    }
    stringstream sstream;
    int id;
    string name,password;
    while(getline(ifUser,stmp))
    {
        vector<string> res = split(stmp, '\t');
        sstream<<res[0]<<' '<<res[1]<<' '<<res[2];
        sstream>>id>>name>>password;
        user utmp(id,name,password);
        sstream.clear();
        sstream.str("");
        huser.push_back(utmp);
    }
    ifUser.close();
}
//admin初始化读入文件
void library::adminInitial()
{
    ifstream ifAdmin(".\\data\\admin.txt",ios::in);
    if(!ifAdmin.is_open())
    {
        cout<<"未找到管理员文件！"<<endl;
        ifAdmin.close();
        exit(-1);
    }
    string stmp;
    getline(ifAdmin,stmp);
    if(ifAdmin.eof())
    {
        cout<<"暂无管理员！请注册！"<<endl;
        ifAdmin.close();
        return;
    }
    stringstream sstream;
    int id;
    string name,password;
    while(getline(ifAdmin,stmp))
    {
        vector<string> res = split(stmp, '\t');
        sstream<<res[0]<<' '<<res[1]<<' '<<res[2];
        sstream>>id>>name>>password;
        admin atmp(id,name,password);
        sstream.clear();
        sstream.str("");
        hadmin.push_back(atmp);
    }
    ifAdmin.close();
}
//record初始化读入文件
void library::recordInitial()
{
    ifstream ifRecord(".\\data\\record.txt",ios::in);
    if(!ifRecord.is_open())
    {
        cout<<"未找到记录文件！"<<endl;
        ifRecord.close();
        exit(-1);
    }
    string stmp;
    getline(ifRecord,stmp);
    if(ifRecord.eof())
    {
        cout<<"暂无记录！借阅书籍后自动生成记录！"<<endl;
        ifRecord.close();
        return;
    }
    stringstream sstream;
    int id,bookId,userId,state;
    time_t timeBorrow,timeBack;
    while(getline(ifRecord,stmp))
    {
        vector<string> res = split(stmp, '\t');
        sstream<<res[0]<<' '<<res[1]<<' '<<res[2]<<' '<<res[3]<<' '<<res[4]<<' '<<res[5];
        sstream>>id>>bookId>>userId>>state>>timeBorrow>>timeBack;
        record rtmp(id,bookId,userId,state,timeBorrow,timeBack);
        sstream.clear();
        sstream.str("");
        hrecord.push_back(rtmp);
        vector<book>::iterator itbook;
        vector<user>::iterator ituser;
        if(bookId==hbook[bookId-1].id)
            itbook=hbook.begin()+bookId-1;
        else
            itbook=find(hbook.begin(),hbook.end(),bookId);
        itbook->recordId.push_back(id);
        if(userId==huser[userId-1].id)
            ituser=huser.begin()+userId-1;
        else
            ituser=find(huser.begin(),huser.end(),userId);
        ituser->recordId.push_back(id);
        //利用了vector容器的顺序，所以一般来说可以直接通过访问下标添加记录。但如果有删除的情况，顺序可能和id不符，所以再用find
        //保证正确性的同时加快效率
        if(state==1)
        {
            itbook->num-=1;
            ituser->bookNum+=1;
        }
    }
    ifRecord.close();
}
//user添加写入文件
void library::add(const user& thisUser)
{
    ofstream ofUser(".\\data\\user.txt",ios::app);
    ofUser<<thisUser.id<<'\t'<<thisUser.name<<'\t'<<thisUser.password<<endl;
    ofUser.close();
}
//admin添加写入文件
void library::add(const admin& thisAdmin)
{
    ofstream ofAdmin(".\\data\\admin.txt",ios::app);
    ofAdmin<<thisAdmin.id<<'\t'<<thisAdmin.name<<'\t'<<thisAdmin.password<<endl;
    ofAdmin.close();
}
//book添加写入文件
void library::add(const book& thisBook)
{
    ofstream ofBook(".\\data\\book.txt",ios::app);
    ofBook<<thisBook.id<<'\t'<<thisBook.ISBN<<'\t'<<thisBook.name<<'\t'<<thisBook.author<<'\t'<<thisBook.publisher<<
          '\t'<<thisBook.date<<'\t'<<thisBook.price<<'\t'<<thisBook.pages<<'\t'<<thisBook.allnum<<endl;
    ofBook.close();
}
//record添加写入文件
void library::add(const record& thisRecord)
{
    ofstream ofRecord(".\\data\\record.txt",ios::app);
    ofRecord<<thisRecord.id<<'\t'<<thisRecord.bookId<<'\t'<<thisRecord.userId<<'\t'<<thisRecord.state<<'\t'<<
        thisRecord.timeBorrow<<'\t'<<thisRecord.timeBack<<endl;
    ofRecord.close();
}
//user修改写入文件
void library::changeUser()
{
    ofstream ofUser(".\\data\\user.txt",ios::out);
    ofUser<<"id	name	password"<<endl;
    for(auto thisUser : huser)
        ofUser<<thisUser.id<<'\t'<<thisUser.name<<'\t'<<thisUser.password<<endl;
    ofUser.close();
}
//book修改写入文件
void library::changeBook()
{
    ofstream ofBook(".\\data\\book.txt",ios::out);
    ofBook<<"id	isbn	name	author	publishing	publisheddate	price	pages\tallnum"<<endl;
    for(auto thisBook : hbook)
        ofBook<<thisBook.id<<'\t'<<thisBook.ISBN<<'\t'<<thisBook.name<<'\t'<<thisBook.author<<'\t'<<thisBook.publisher<<
              '\t'<<thisBook.date<<'\t'<<thisBook.price<<'\t'<<thisBook.pages<<'\t'<<thisBook.allnum<<endl;
    ofBook.close();
}
//record修改写入文件
void library::changeRecord()
{
    ofstream ofRecord(".\\data\\record.txt",ios::out);
    ofRecord<<"id	book_id	user_id	state\ttimeBorrow\ttimeBack"<<endl;
    for(auto thisRecord : hrecord)
        ofRecord<<thisRecord.id<<'\t'<<thisRecord.bookId<<'\t'<<thisRecord.userId<<'\t'<<thisRecord.state<<'\t'<<
        thisRecord.timeBorrow<<'\t'<<thisRecord.timeBack<<endl;
    ofRecord.close();
}
//登录界面
void library::land()
{
    while(1)
    {
        int type;
        cout<<"读者数量："<<setfill('-')<<setw(19)<<huser.size()<<endl;
        cout<<"管理员数量："<<setfill('-')<<setw(17)<<hadmin.size()<<endl;
        cout<<"书籍数量："<<setfill('-')<<setw(19)<<hbook.size()<<endl;
        cout<<"借阅记录数量："<<setfill('-')<<setw(15)<<hrecord.size()<<endl;
        cout<<setfill(' ');
        getTime();
        cout<<"-----------------------------"<<endl;
        cout<<"---欢迎使用H大学图书馆系统---"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"------请选择你的登录模式-----"<<endl;
        cout<<"---------0-注册新用户--------"<<endl;
        cout<<"---------1-管理员------------"<<endl;
        cout<<"---------2-读者--------------"<<endl;
        cout<<"---------3-游客--------------"<<endl;
        cout<<"---------4-退出--------------"<<endl;
        cout<<"请输入你的选择："<<endl;
        cin>>type;
        switch(type)
        {
        case 0:
            enroll();
            break;
        case 1:
        {
            if(hadmin.empty())
            {
                cout<<"暂无管理员，请注册！"<<endl;
                break;
            }
            vector<admin>::iterator it;
            cout<<"---------登录方式------------"<<endl;
            cout<<"---------1-ID----------------"<<endl;
            cout<<"---------2-用户名------------"<<endl;
            cout<<"---------3-返回开始界面------"<<endl;
            int loadType;
            string password;
            cin>>loadType;
            switch(loadType)
            {
            case 1:
            {
                cout<<"请输入ID：";
                int id;
                while(cin>>id,it=find(hadmin.begin(),hadmin.end(),id),it==hadmin.end())
                {
                    cout<<"未找到该管理员！请重新输入：";
                }
                cout<<"请输入密码：";
                while(cin>>password,it->password!=password)
                {
                    cout<<"密码错误，请重新输入：";
                }
                cout<<"登录成功，即将进入管理员主页！"<<endl;
                adminUI();
                break;
            }
            case 2:
            {
                cout<<"请输入用户名：";
                string name;
                while(cin>>name,it=find(hadmin.begin(),hadmin.end(),name),it==hadmin.end())
                {
                    cout<<"未找到该管理员！请重新输入：";
                }
                cout<<"请输入密码：";
                while(cin>>password,it->password!=password)
                {
                    cout<<"密码错误，请重新输入：";
                }
                cout<<"登录成功，即将进入管理员主页！"<<endl;
                adminUI();
                break;
            }
            case 3:
                break;
            default:
                cout<<"输入错误，请重新输入！"<<endl;
            }
            break;
        }
        case 2:
        {
            if(huser.empty())
            {

                cout<<"暂无读者，请注册！"<<endl;
                break;
            }
            vector<user>::iterator it;
            cout<<"---------登录方式------------"<<endl;
            cout<<"---------1-ID----------------"<<endl;
            cout<<"---------2-用户名------------"<<endl;
            cout<<"---------3-返回开始界面------"<<endl;
            int loadType;
            string password;
            cin>>loadType;
            switch(loadType)
            {
            case 1:
            {
                cout<<"请输入ID：";
                int id;
                while(cin>>id,it=find(huser.begin(),huser.end(),id),it==huser.end())
                {
                    cout<<"未找到该读者！请重新输入：";
                }
                cout<<"请输入密码：";
                while(cin>>password,it->password!=password)
                {
                    cout<<"密码错误，请重新输入：";
                }
                cout<<"登录成功，即将进入读者主页！"<<endl;
                userUI(it->id);
                break;
            }
            case 2:
            {
                cout<<"请输入用户名：";
                string name;
                while(cin>>name,it=find(huser.begin(),huser.end(),name),it==huser.end())
                {
                    cout<<"未找到该读者！请重新输入：";
                }
                cout<<"请输入密码：";
                while(cin>>password,it->password!=password)
                {
                    cout<<"密码错误，请重新输入：";
                }
                cout<<"登录成功，即将进入读者主页！"<<endl;
                userUI(it->id);
                break;
            }
            case 3:
                break;
            default:
                cout<<"输入错误，请重新输入！"<<endl;
            }
            break;
        }
        case 3:
        {
            visitorUI();
            break;
        }
        case 4:
        {
            cout<<"您已退出！欢迎下次使用！"<<endl;
            return;
            break;
        }

        default:
            cout<<"输入错误，请重新输入！"<<endl;
        }
        system("pause");
        system("cls");
    }
}
//注册界面
void library::enroll()
{
    system("pause");
    system("cls");
    getTime();
    int type;
    cout<<"-----------------------------"<<endl;
    cout<<"----------注册界面-----------"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"------请选择你的用户类型-----"<<endl;
    cout<<"---------1-管理员------------"<<endl;
    cout<<"---------2-读者--------------"<<endl;
    cout<<"---------3-返回开始界面------"<<endl;
    while(1)
    {
        cout<<"请输入你的选择："<<endl;
        cin>>type;
        switch(type)
        {
        case 1:
        {
            string name,password;
            cout<<"请输入用户名（不含空格）：";
            while(cin>>name,!hadmin.empty()&&find(hadmin.begin(),hadmin.end(),name)!=hadmin.end())
                cout<<"该用户名已注册！请重新输入管理员名！"<<endl;
            cout<<"请输入密码（不含空格）：";
            cin>>password;
            int id;
            if(hadmin.empty())
                id=1;
            else
                id=(hadmin.end()-1)->id+1;
            cout<<"已为您自动生成账号，您的ID是："<<id<<endl;
            admin atmp(id,name,password);
            hadmin.push_back(atmp);
            add(atmp);
            cout<<"您已成功注册，即将返回登录界面！"<<endl;
            return;
            break;
        }
        case 2:
        {
            string name,password;
            cout<<"请输入用户名（不含空格）：";
            while(cin>>name,!huser.empty()&&find(huser.begin(),huser.end(),name)!=huser.end())
                cout<<"该用户名已注册！请重新输入读者名！"<<endl;

            cout<<"请输入密码（不含空格）：";
            cin>>password;
            int id;
            if(huser.empty())
                id=1;
            else
                id=(huser.end()-1)->id+1;
            cout<<"已为您自动生成账号，您的ID是："<<id<<endl;
            user utmp(id,name,password);
            huser.push_back(utmp);
            add(utmp);
            cout<<"您已成功注册，即将返回登录界面！"<<endl;
            return;
            break;
        }
        case 3:
            return;
            break;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
        }
    }
}
//管理员界面
void library::adminUI()
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        int type;
        cout<<"-----------------------------"<<endl;
        cout<<"----------管理员界面---------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"------请选择你的功能模式-----"<<endl;
        cout<<"-------1-读者信息管理--------"<<endl;
        cout<<"-------2-书籍信息管理--------"<<endl;
        cout<<"-------3-借阅信息展示--------"<<endl;
        cout<<"-------4-管理员信息展示------"<<endl;
        cout<<"-------5-读者信息展示--------"<<endl;
        cout<<"-------6-退出账号------------"<<endl;
        cin>>type;
        switch(type)
        {
        case 1:
            manageUser();
            break;
        case 2:
            manageBook();
            break;
        case 3:
        {
            vector<record*>result;
            for(int i=hrecord.size()-1; i>=0; --i)
            {
                result.push_back(&hrecord[i]);
            }
            searching(result);
            break;
        }
        case 4:
        {
            vector<admin*>result;
            for(int i=0; i<hadmin.size(); ++i)
            {
                result.push_back(&hadmin[i]);
            }
            searching(result);
            break;
        }
        case 5:
        {
            vector<user*>result;
            for(int i=0; i<huser.size(); ++i)
            {
                result.push_back(&huser[i]);
            }
            searching(result);
            break;
        }
        case 6:
            return;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
            break;
        }
    }
}
//读者管理界面
void library::manageUser()
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"-----------------------------"<<endl;
        cout<<"--------读者用户管理---------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"--1-增加用户信息-------------"<<endl;
        cout<<"--2-查找用户信息（含改、删）-"<<endl;
        cout<<"--3-返回上一级---------------"<<endl;
        int adminType;
        cin>>adminType;
        switch(adminType)
        {
        case 1:
        {
            string name,password;
            cout<<"请输入要增加的读者用户名（不含空格）：";
            while(cin>>name,!huser.empty()&&find(huser.begin(),huser.end(),name)!=huser.end())
                cout<<"该用户名已注册！请重新输入读者名！"<<endl;
            cout<<"请输入密码（不含空格）：";
            cin>>password;
            int id;
            if(huser.empty())
                id=1;
            else
                id=(huser.end()-1)->id+1;
            cout<<"已增加读者账号，读者的ID是："<<id<<endl;
            user utmp(id,name,password);
            huser.push_back(utmp);
            add(utmp);
            cout<<"您已成功添加读者用户账号！"<<endl;
            break;
        }
        case 2:
        {
            vector<user>::iterator it;
            cout<<"请输入所查询的读者用户名或ID：";
            string name;
            while(cin>>name,(it=find(huser.begin(),huser.end(),name),it==huser.end())
                    &&(it=find(huser.begin(),huser.end(),atoi(name.c_str())),it==huser.end()))
            {
                if(name=="0")
                    break;
                cout<<"未找到该读者！请重新输入(若退出，输入0)：";
            }
            if(name=="0")break;
            cout<<"[1]ID\t[2]用户名\t[3]密码\t[4]历史借阅数\t[5]当前借阅数"<<endl;
            it->privateView();
            cout<<"--请选择对该用户进行的操作---"<<endl;
            cout<<"--1-修改读者用户名-----------"<<endl;
            cout<<"--2-重置用户密码-------------"<<endl;
            cout<<"--3-注销该用户---------------"<<endl;
            cout<<"--4-返回---------------------"<<endl;
            int operation;
            while(1)
            {
                cin>>operation;
                switch(operation)
                {
                case 1:
                {
                    string newname;
                    cout<<"请输入新的用户名：";
                    while(cin>>newname,!huser.empty()&&find(huser.begin(),huser.end(),newname)!=huser.end())
                        cout<<"该用户名已注册！请重新输入读者名！"<<endl;
                    it->name=newname;
                    changeUser();
                    cout << "修改成功！" << endl;
                    break;
                }
                case 2:
                {
                    cout<<"确认重置密码为123456,[Y]确认；任意键其他键返回"<<endl;
                    char confirm;
                    cin>>confirm;
                    if(confirm=='Y')
                    {
                        it->password="123456";
                        changeUser();
                        cout<<"重置成功！"<<endl;
                    }

                    break;
                }
                case 3:
                {
                    if(it->bookNum!=0)
                    {
                        cout<<"当前读者仍有未归还书籍，无法注销！"<<endl;
                        break;
                    }
                    cout<<"确认注销,[Y]确认；任意其他键返回"<<endl;
                    char confirm;
                    cin>>confirm;
                    if(confirm=='Y')
                    {
                        huser.erase(it);
                        changeUser();
                        cout<<"注销成功！"<<endl;
                    }
                    break;
                }
                case 4:
                    break;
                default:
                    cout<<"输入错误，请重新输入！"<<endl;
                }
                if(operation>=1&&operation<=4)
                    break;
            }
            break;
        }
        case 3:
            return;
            break;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
        }
    }
}
//书籍管理界面
void library::manageBook()
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"-----------------------------"<<endl;
        cout<<"---------书籍信息管理--------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"--1-增加图书信息-------------"<<endl;
        cout<<"--2-查找图书信息（含改、删）-"<<endl;
        cout<<"--3-查看排行榜（含改、删）---"<<endl;
        cout<<"--4-返回上一级---------------"<<endl;
        int adminType;
        cin>>adminType;
        switch(adminType)
        {
        case 1:
        {
            cout<<"添加模式[1]完整信息[2]逐个信息[3]退出"<<endl;
            int information;
            while(1)
            {
                cin>>information;
                switch(information)
                {
                case 1:
                {
                    stringstream sstream;
                    cout<<"格式提示：ISBN\t书名\t作者\t出版社\t出版日期\t价格\t页数\t本数(以制表符为分隔)"<<endl;
                    int id,pages,allnum;
                    long long ISBN;
                    string name,author,date,publisher;
                    double price;
                    string stmp;
                    cin.ignore();
                    getline(cin,stmp);
                    vector<string> res = split(stmp, '\t');
                    name=res[1],author=res[2],publisher=res[3],date=res[4];
                    sstream<<res[0]<<' '<<res[5]<<' '<<res[6]<<' '<<res[7];
                    sstream>>ISBN>>price>>pages>>allnum;
                    id=(hbook.end()-1)->id+1;
                    book btmp(id,ISBN,name,author,publisher,date,price,pages,allnum);
                    sstream.clear();
                    sstream.str("");
                    hbook.push_back(btmp);
                    add(btmp);
                    cout<<"添加成功！添加后的信息：";
                    (hbook.end()-1)->view();
                    break;
                }
                case 2:
                {
                    int id,pages,allnum;
                    long long ISBN;
                    string name,author,date,publisher;
                    double price;
                    cout<<"请输入ISBN：";
                    cin>>ISBN;
                    cout<<"请输入书名：";
                    cin>>name;
                    cout<<"请输入作者：";
                    cin>>author;
                    cout<<"请输入出版社：";
                    cin>>publisher;
                    cout<<"请输入出版日期：";
                    cin>>date;
                    cout<<"请输入价格：";
                    cin>>price;
                    cout<<"请输入页数：";
                    cin>>pages;
                    cout<<"请输入本数：";
                    cin>>allnum;
                    book btmp(id,ISBN,name,author,publisher,date,price,pages,allnum);
                    hbook.push_back(btmp);
                    add(btmp);
                    cout<<"添加成功！添加后的信息：";
                    (hbook.end()-1)->view();
                    break;
                }
                case 3:
                    break;
                default:
                    cout<<"输入错误，请重新输入！"<<endl;
                }
                if(information==1||information==2||information==3)
                    break;
            }
            break;
        }
        case 2:
            searchingUI(1);
            break;
        case 3:
            rankingUI(1);
            break;
        case 4:
            return;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
        }
    }
}
//用户界面
void library::userUI(int id)
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        int type;
        cout<<"-----------------------------"<<endl;
        cout<<"----------读者界面-----------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"------请选择你的功能模式-----"<<endl;
        cout<<"----1-搜索（含借阅）---------"<<endl;
        cout<<"----2-查看个人借阅（含归还）-"<<endl;
        cout<<"----3-查看排行榜（含借阅）---"<<endl;
        cout<<"----4-修改密码---------------"<<endl;
        cout<<"----5-退出账号---------------"<<endl;
        cin>>type;
        switch(type)
        {
        case 1:
            searchingUI(2,id);
            break;
        case 2:
        {
            vector<user>::iterator itUser=find(huser.begin(),huser.end(),id);
            if(itUser->recordId.empty())
            {
                cout<<"暂无借阅记录！"<<endl;
                break;
            }
            cout<<"时间倒序显示借阅记录，包括历史借阅与正在借阅"<<endl;
            cout<<"[0]序号\t[1]书籍ID\t[2]借阅状态\t[3]借阅时间\t[4]归还时间"<<endl;
            int i=0;
            for(; i<itUser->recordId.size(); ++i)
            {
                vector<record>::iterator itRecord=find(hrecord.begin(),hrecord.end(),*(itUser->recordId.end()-i-1));
                cout<<i+1<<'\t';
                itRecord->userView();
            }
            cout<<"输入序号以查看书籍详细信息，若未归还可于此归还！"<<endl;
            int number;
            while(cin>>number,number>i||number<1)
            {
                cout<<"输入错误，请重新输入！"<<endl;
            }
            vector<record>::iterator itRecord=find(hrecord.begin(),hrecord.end(),*(itUser->recordId.end()-number));
            vector<book>::iterator itBook=find(hbook.begin(),hbook.end(),itRecord->bookId);
            if(itBook->rlend(itUser,itRecord->state))
            {
                itRecord->state=0;
                itRecord->timeBack=time(NULL);
                changeRecord();
            }
            break;
        }
        case 3:
            rankingUI(2,id);
            break;
        case 4:
        {
            vector<user>::iterator it=find(huser.begin(),huser.end(),id);
            for(int i=2; i>=0; --i)
            {
                cout<<"请输入原密码：";
                string ypassword;
                cin>>ypassword;
                cout<<"请输入现密码：";
                string xpassword;
                while(cin>>xpassword,xpassword==ypassword)
                {
                    cout<<"修改密码须与原密码不同，请重新输入："<<endl;
                }
                if(ypassword!=it->password)
                {
                    cout<<"原密码输入错误！错误三次将自动退出账号，你还有"<<i<<"次机会"<<endl;
                    if(i==0)
                    {
                        cout<<"即将退出账号，忘记密码请联系管理员重置密码！"<<endl;
                        return;
                    }
                }
                else
                {
                    it->password=xpassword;
                    changeUser();
                    cout<<"修改成功！"<<endl;
                    break;
                }
            }
            break;
        }
        case 5:
            return;
            break;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
            break;
        }
    }
}
//游客界面
void library::visitorUI()
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        int type;
        cout<<"-----------------------------"<<endl;
        cout<<"----------游客界面-----------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"------请选择你的功能模式-----"<<endl;
        cout<<"---------1-搜索--------------"<<endl;
        cout<<"---------2-排行榜------------"<<endl;
        cout<<"---------3-返回开始界面------"<<endl;
        cin>>type;
        switch(type)
        {
        case 1:
            searchingUI(3);
            break;
        case 2:
            rankingUI(3);
            break;
        case 3:
            return;
            break;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
            break;
        }
    }
}
//搜索界面
void library::searchingUI(int type,int id)
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        int information;
        cout<<"-----------------------------"<<endl;
        cout<<"----------搜索界面-----------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"------请选择你的搜索信息-----"<<endl;
        cout<<"---------1-书名--------------"<<endl;
        cout<<"---------2-ISBN/ISSN---------"<<endl;
        cout<<"---------3-作者--------------"<<endl;
        cout<<"---------4-出版社------------"<<endl;
        cout<<"---------5-所有书籍----------"<<endl;
        cout<<"---------6-返回用户界面------"<<endl;
        cin>>information;
        switch(information)
        {
        case 1:
        {
            cout<<"请输入书名：";
            string name;
            vector<book>::iterator it;
            while(cin>>name,it=find(hbook.begin(),hbook.end(),name),it==hbook.end())
            {
                if(name=="0")
                    break;
                cout<<"未找到书籍，请重新输入！若要退出请输入0"<<endl;
            }
            if(name=="0")
                break;
            cout<<"精准搜索，找到一条信息！"<<endl;
            cout<<"[1]ISBN\t[2]书名\t[3]作者\t[4]出版社\t[5]出版日期\t[6]价格\t[7]页数\t[8]历史借阅人数\t[9]剩余数量\t[10]当前借阅人数"<<endl;
            it->view();
            switch(type)
            {
            case 1:
            {
                cout<<"管理员身份，是否修改？[Y]是；任意键返回"<<endl;
                char c;
                cin>>c;
                if(c!='Y')
                    break;
                if(it->revise())
                {
                    hbook.erase(it);
                    cout<<"已成功删除！"<<endl;
                }
                changeBook();
                break;
            }
            case 2:
            {
                cout<<"读者身份，是否借阅？[Y]是；任意键返回"<<endl;
                char c;
                cin>>c;
                if(c!='Y')
                    break;
                vector<user>::iterator thisUser=find(huser.begin(),huser.end(),id);
                if(it->lend(thisUser))
                {
                    record tmp((hrecord.end()-1)->id+1,it->id,thisUser->id,1,time(NULL),time(NULL));
                    it->recordId.push_back((hrecord.end()-1)->id+1);
                    thisUser->recordId.push_back((hrecord.end()-1)->id+1);
                    hrecord.push_back(tmp);
                    add(tmp);
                }
                break;
            }
            case 3:
                cout<<"游客身份，仅可浏览！"<<endl;
                break;
            }
            break;
        }
        case 2:
        {
            cout<<"请输入ISBN：";
            long long ISBN;
            vector<book>::iterator it;
            while(cin>>ISBN,it=find(hbook.begin(),hbook.end(),ISBN),it==hbook.end())
            {
                if(ISBN==0)
                    break;
                cout<<"未找到书籍，请重新输入！若要退出请输入0"<<endl;
            }
            if(ISBN==0)
                break;
            cout<<"精准搜索，找到一条信息！"<<endl;
            cout<<"[1]ISBN\t[2]书名\t[3]作者\t[4]出版社\t[5]出版日期\t[6]价格\t[7]页数\t[8]历史借阅人数\t[9]借阅状态"<<endl;
            it->view();
            switch(type)
            {
            case 1:
            {
                cout<<"管理员身份，是否修改？[Y]是；任意键返回"<<endl;
                char c;
                cin>>c;
                if(c!='Y')
                    break;
                if(it->revise())
                {
                    hbook.erase(it);
                    cout<<"已成功删除！"<<endl;
                }
                changeBook();
                break;
            }
            case 2:
            {
                cout<<"读者身份，是否借阅？[Y]是；任意键返回"<<endl;
                char c;
                cin>>c;
                if(c!='Y')
                    break;
                vector<user>::iterator thisUser=find(huser.begin(),huser.end(),id);
                if(it->lend(thisUser))
                {
                    record tmp((hrecord.end()-1)->id+1,it->id,thisUser->id,1,time(NULL),time(NULL));
                    it->recordId.push_back((hrecord.end()-1)->id+1);
                    thisUser->recordId.push_back((hrecord.end()-1)->id+1);
                    hrecord.push_back(tmp);
                    add(tmp);
                }
                break;
            }
            case 3:
                cout<<"游客身份，仅可浏览！"<<endl;
                break;
            }
            break;
        }
        case 3:
        {
            cout<<"请输入作者名：";
            string author;
            while(cin>>author,find(hbook.begin(),hbook.end(),author)==hbook.end())
            {
                if(author=="0")
                    break;
                cout<<"未找到书籍，请重新输入！若要退出请输入0"<<endl;
            }
            if(author=="0")
                break;
            vector<book*>result;
            for(int i=0; i<hbook.size(); ++i)
            {
                if(hbook[i].author==author)
                    result.push_back(&hbook[i]);
            }
            sort(result.begin(),result.end(),[](book*&x,book*&y)
            {
                return x->name<y->name;
            });
            searching(result,type,id);
            break;
        }
        case 4:
        {
            cout<<"请输入出版社名：";
            string publisher;
            while(cin>>publisher,find(hbook.begin(),hbook.end(),publisher)==hbook.end())
            {
                if(publisher=="0")
                    break;
                cout<<"未找到书籍，请重新输入！若要退出请输入0"<<endl;
            }
            if(publisher=="0")
                break;
            vector<book*>result;
            for(int i=0; i<hbook.size(); ++i)
            {
                if(hbook[i].publisher==publisher)
                    result.push_back(&hbook[i]);
            }
            sort(result.begin(),result.end(),[](book*&x,book*&y)
            {
                return x->name<y->name;
            });
            searching(result,type,id);
            break;
        }
        case 5:
        {
            vector<book*>result;
            for(int i=0; i<hbook.size(); ++i)
            {
                result.push_back(&hbook[i]);
            }
            sort(result.begin(),result.end(),[](book*&x,book*&y)
            {
                return x->name<y->name;
            });
            searching(result,type,id);
        }
        case 6:
            return;
            break;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
            break;
        }
    }
}
//搜索书籍具体信息
void library::searching(vector<book*>&result,int type,int id)
{
    int page=1,allPage=ceil(result.size()/10.0);
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"模糊搜索，共找到"<<result.size()<<"本书籍！"<<endl;
        cout<<"每页显示10本书籍，共"<<allPage<<"页，当前位于第"<<page<<"页"<<endl;
        cout<<"[0]序号\t[1]ISBN\t[2]书名\t[3]作者\t[4]出版社\t[5]出版日期\t[6]价格\t[7]页数\t[8]历史借阅人数\t[9]剩余数量\t[10]当前借阅人数"<<endl;
        int i;
        for(i=(page-1)*10; i<page*10&&i<result.size(); ++i)
        {
            cout<<i-(page-1)*10+1<<'\t';
            result[i]->view();
        }
        cout<<"[1]第一页 [2]上一页 [3]下一页 [4]最后一页 [5]跳转到指定页 [6]退出";
        switch(type)
        {
        case 1:
            cout<<" [7]修改图书"<<endl;
            break;
        case 2:
            cout<<" [7]借阅图书"<<endl;
            break;
        case 3:
            cout<<endl;
            break;
        }
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            page=1;
            break;
        case 2:
            if(page==1)
                cout<<"当前位于第一页，不可进入上一页！"<<endl;
            else
                page-=1;
            break;
        case 3:
            if(page==allPage)
                cout<<"当前位于最后一页，不可进入上一页！"<<endl;
            else
                page+=1;
            break;
        case 4:
            page=allPage;
            break;
        case 5:
        {
            int j;
            cout<<"请输入跳转页数：";
            cin>>j;
            if(j==page)
                cout<<"不可跳转至当前页！"<<endl;
            else if(j<1||j>allPage)
                cout<<"指定页不存在！"<<endl;
            else
                page=j;
            break;
        }
        case 6:
            return;
            break;
        case 7:
            switch(type)
            {
            case 1:
            {
                cout<<"请输入您要修改的书籍在此页的序号:";
                int number;
                while(cin>>number,number>i-(page-1)*10||number<1)
                {
                    cout<<"输入错误，请重新输入！"<<endl;
                }
                number+=(page-1)*10-1;
                if(result[number]->revise())
                {
                    vector<book>::iterator it=find(hbook.begin(),hbook.end(),result[number]->id);
                    hbook.erase(it);
                }
                changeBook();
                break;
            }
            case 2:
            {
                cout<<"请输入您要借阅的书籍在此页的序号:";
                int number;
                while(cin>>number,number>i||number<1)
                {
                    cout<<"输入错误，请重新输入！"<<endl;
                }
                number+=(page-1)*10-1;
                vector<user>::iterator thisUser=find(huser.begin(),huser.end(),id);
                if(result[number]->lend(thisUser))
                {
                    record tmp((hrecord.end()-1)->id+1,result[number]->id,thisUser->id,1,time(NULL),time(NULL));
                    result[number]->recordId.push_back((hrecord.end()-1)->id+1);
                    thisUser->recordId.push_back((hrecord.end()-1)->id+1);
                    hrecord.push_back(tmp);
                    add(tmp);
                }
                break;
            }
            case 3:
                cout<<"输入错误，请重新输入！"<<endl;
                break;
            }
            break;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
        }
    }
}
//全部借阅记录显示
void library::searching(vector<record*>&result)
{
    int page=1,allPage=ceil(result.size()/10.0);
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"共找到"<<result.size()<<"条借阅记录！按时间倒序显示"<<endl;
        cout<<"每页显示10条记录，共"<<allPage<<"页，当前位于第"<<page<<"页"<<endl;
        cout<<"[0]序号\t[1]书籍ID\t[2]用户ID\t[3]借阅状态\t[4]借阅时间\t[5]归还时间"<<endl;
        int i;
        for(i=(page-1)*10; i<page*10&&i<result.size(); ++i)
        {
            cout<<i-(page-1)*10+1<<'\t';
            result[i]->adminView();
        }
        cout<<"[1]第一页 [2]上一页 [3]下一页 [4]最后一页 [5]跳转到指定页 [6]退出 [7]查看详细信息"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            page=1;
            break;
        case 2:
            if(page==1)
                cout<<"当前位于第一页，不可进入上一页！"<<endl;
            else
                page-=1;
            break;
        case 3:
            if(page==allPage)
                cout<<"当前位于最后一页，不可进入上一页！"<<endl;
            else
                page+=1;
            break;
        case 4:
            page=allPage;
            break;
        case 5:
        {
            int j;
            cout<<"请输入跳转页数：";
            cin>>j;
            if(j==page)
                cout<<"不可跳转至当前页！"<<endl;
            else if(j<1||j>allPage)
                cout<<"指定页不存在！"<<endl;
            else
                page=j;
            break;
        }
        case 6:
            return;
            break;
        case 7:
        {
            cout<<"请输入您要查看的记录在此页的序号:";
            int number;
            while(cin>>number,number>i-(page-1)*10||number<1)
            {
                cout<<"输入错误，请重新输入！"<<endl;
            }
            number+=(page-1)*10-1;
            vector<book>::iterator itBook=find(hbook.begin(),hbook.end(),result[number]->bookId);
            vector<user>::iterator itUser=find(huser.begin(),huser.end(),result[number]->userId);
            if(itBook!=hbook.end())
            {
                cout<<"书籍信息：";
                cout<<"[1]ISBN\t[2]书名\t[3]作者\t[4]出版社\t[5]出版日期\t[6]价格\t[7]页数\t[8]历史借阅人数\t[9]剩余数量\t[10]当前借阅人数"<<endl;
                itBook->view();
            }
            else
                cout<<"该书籍已删除，无法查看详细书籍信息！"<<endl;
            if(itUser!=huser.end())
            {
                cout<<"读者信息：";
                cout<<"[1]ID\t[2]用户名\t[3]历史借阅数\t[6]当前借阅数"<<endl;
                itUser->view();
            }
            else
                cout<<"该读者已删除，无法查看详细读者信息！"<<endl;
            break;
        }
        default:
            cout<<"输入错误，请重新输入！"<<endl;
        }
    }
}
//全部用户显示
void library::searching(vector<user*>&result)
{
    int page=1,allPage=ceil(result.size()/10.0);
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"共找到"<<result.size()<<"名读者！"<<endl;
        cout<<"每页显示10名用户，共"<<allPage<<"页，当前位于第"<<page<<"页"<<endl;
        cout<<"[1]ID\t[2]用户名\t[3]密码\t[4]历史借阅数\t[5]当前借阅数"<<endl;
        int i;
        for(i=(page-1)*10; i<page*10&&i<result.size(); ++i)
        {
            result[i]->privateView();
        }
        cout<<"[1]第一页 [2]上一页 [3]下一页 [4]最后一页 [5]跳转到指定页 [6]退出"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            page=1;
            break;
        case 2:
            if(page==1)
                cout<<"当前位于第一页，不可进入上一页！"<<endl;
            else
                page-=1;
            break;
        case 3:
            if(page==allPage)
                cout<<"当前位于最后一页，不可进入上一页！"<<endl;
            else
                page+=1;
            break;
        case 4:
            page=allPage;
            break;
        case 5:
        {
            int j;
            cout<<"请输入跳转页数：";
            cin>>j;
            if(j==page)
                cout<<"不可跳转至当前页！"<<endl;
            else if(j<1||j>allPage)
                cout<<"指定页不存在！"<<endl;
            else
                page=j;
            break;
        }
        case 6:
            return;
            break;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
        }
    }
}
//全部管理员显示
void library::searching(vector<admin*>&result)
{
    int page=1,allPage=ceil(result.size()/10.0);
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"共找到"<<result.size()<<"名管理员！"<<endl;
        cout<<"每页显示10名用户，共"<<allPage<<"页，当前位于第"<<page<<"页"<<endl;
        cout<<"[1]ID\t[2]用户名\t[3]密码"<<endl;
        int i;
        for(i=(page-1)*10; i<page*10&&i<result.size(); ++i)
        {
            result[i]->view();
        }
        cout<<"[1]第一页 [2]上一页 [3]下一页 [4]最后一页 [5]跳转到指定页 [6]退出"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            page=1;
            break;
        case 2:
            if(page==1)
                cout<<"当前位于第一页，不可进入上一页！"<<endl;
            else
                page-=1;
            break;
        case 3:
            if(page==allPage)
                cout<<"当前位于最后一页，不可进入上一页！"<<endl;
            else
                page+=1;
            break;
        case 4:
            page=allPage;
            break;
        case 5:
        {
            int j;
            cout<<"请输入跳转页数：";
            cin>>j;
            if(j==page)
                cout<<"不可跳转至当前页！"<<endl;
            else if(j<1||j>allPage)
                cout<<"指定页不存在！"<<endl;
            else
                page=j;
            break;
        }
        case 6:
            return;
            break;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
        }
    }
}
//排行榜界面
void library::rankingUI(int type,int id)
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        int rankType;
        cout<<"-----------------------------"<<endl;
        cout<<"------------排行榜-----------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"-------请选择排行榜类型------"<<endl;
        cout<<"-----1-借阅次数前十的图书----"<<endl;
        cout<<"-----2-借阅次数前十的读者----"<<endl;
        cout<<"-----3-最新出版前十的图书----"<<endl;
        cout<<"-----4-返回用户界面----------"<<endl;
        cin>>rankType;
        switch(rankType)
        {
        case 1:
        {

            vector<book*> all;
            for(int i=0; i<hbook.size(); ++i)
                all.push_back(&hbook[i]);
            sort(all.begin(),all.end(),[](book*&x,book*&y)
            {
                return x->recordId.size()>y->recordId.size();
            });
            vector<book*> result;
            for(int i=0; i<10; ++i)
                result.push_back(all[i]);
            cout<<"借阅次数前十图书排行榜"<<endl;
            ranking(result,type,id);
            break;
        }
        case 2:
        {
            vector<user> tempUser=huser;
            sort(tempUser.begin(),tempUser.end(),[](user&x,user&y)
            {
                return x.recordId.size()>y.recordId.size();
            });
            vector<user*> result;
            for(int i=0; i<10; ++i)
                result.push_back(&tempUser[i]);
            cout<<"借阅次数前十读者排行榜"<<endl;
            ranking(result,type,id);
            break;
        }
        case 3:
        {
            vector<book*> all;
            for(int i=0; i<hbook.size(); ++i)
                all.push_back(&hbook[i]);
            sort(all.begin(),all.end(),[](book*&x,book*&y)
            {
                return atoi(x->date.c_str())>atoi(y->date.c_str());
            });
            vector<book*> result;
            for(int i=0; i<10; ++i)
                result.push_back(all[i]);
            cout<<"最新出版前十图书排行榜"<<endl;
            ranking(result,type,id);
            break;
        }
        case 4:
            return;
            break;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
            break;
        }
    }
}
//最新出版排行和借阅前十图书排行
void library::ranking(vector<book*>&result,int type,int id)
{
    cout<<"[0]排名\t[1]ISBN\t[2]书名\t[3]作者\t[4]出版社\t[5]出版日期\t[6]价格\t[7]页数\t[8]历史借阅人数\t[10]剩余数量\t[11]当前借阅人数"<<endl;
    for(int i=0; i<10; ++i)
    {
        cout<<i+1<<'\t';
        result[i]->view();
    }
    switch(type)
    {
    case 1:
    {
        cout<<"管理员身份，可修改书籍！输入排名修改，输入任意其他数字退出！"<<endl;
        int number;
        cin>>number;
        if(number<1||number>10)
            return;
        number-=1;
        if(result[number]->revise())
        {
            vector<book>::iterator it=find(hbook.begin(),hbook.end(),result[number]->id);
            hbook.erase(it);
            changeBook();
        }
        changeBook();
        return;
        break;
    }
    case 2:
    {
        cout<<"读者身份，可借阅书籍！输入排名借阅，输入任意其他数字退出！"<<endl;
        int number;
        cin>>number;
        if(number<1||number>10)
            return;
        number-=1;
        vector<user>::iterator thisUser=find(huser.begin(),huser.end(),id);
        if(result[number]->lend(thisUser))
        {
            record tmp((hrecord.end()-1)->id+1,result[number]->id,thisUser->id,1,time(NULL),time(NULL));
            result[number]->recordId.push_back((hrecord.end()-1)->id+1);
            thisUser->recordId.push_back((hrecord.end()-1)->id+1);
            hrecord.push_back(tmp);
            add(tmp);
        }
        return;
        break;
    }
    case 3:
        cout<<"游客身份，仅可浏览！"<<endl;
        break;
    }
}
//借阅读者排行
void library::ranking(vector<user*>&result,int type,int id)
{
    cout<<"[0]排名\t[1]ID\t[2]用户名\t[3]历史借阅数\t[4]当前借阅数"<<endl;
    for(int i=0; i<10; ++i)
    {
        cout<<i+1<<'\t';
        result[i]->view();
    }
}

