#include"library.h"
//��װ�õ����ض��ַ��ָ������ַ��������ڶ����ļ�
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
//��ȡ��ǰʱ��
void getTime()
{
    time_t timep;
    time(&timep);
    struct tm *p;
    p = localtime(&timep);
    printf("��ǰʱ�䣺%d/%d/%d %02d:%02d:%02d\n",1900 + p->tm_year, 1+ p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec);
}
//library���캯������ʼ�������ļ�
library::library()
{
    bookInitial();
    userInitial();
    adminInitial();
    recordInitial();
}
//book��ʼ�������ļ�
void library::bookInitial()
{
    ifstream ifBook(".\\data\\book.txt",ios::in);
    if(!ifBook.is_open())
    {
        cout<<"δ�ҵ��鼮�ļ���"<<endl;
        ifBook.close();
        exit(-1);
    }
    string stmp;
    getline(ifBook,stmp);
    if(ifBook.eof())
    {
        cout<<"���޴��飡�����Ա����鼮��"<<endl;
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
//user��ʼ�������ļ�
void library::userInitial()
{
    ifstream ifUser(".\\data\\user.txt",ios::in);
    if(!ifUser.is_open())
    {
        cout<<"δ�ҵ������ļ���"<<endl;
        ifUser.close();
        exit(-1);
    }
    string stmp;
    getline(ifUser,stmp);
    if(ifUser.eof())
    {
        cout<<"���޶��ߣ���ע�ᣡ"<<endl;
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
//admin��ʼ�������ļ�
void library::adminInitial()
{
    ifstream ifAdmin(".\\data\\admin.txt",ios::in);
    if(!ifAdmin.is_open())
    {
        cout<<"δ�ҵ�����Ա�ļ���"<<endl;
        ifAdmin.close();
        exit(-1);
    }
    string stmp;
    getline(ifAdmin,stmp);
    if(ifAdmin.eof())
    {
        cout<<"���޹���Ա����ע�ᣡ"<<endl;
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
//record��ʼ�������ļ�
void library::recordInitial()
{
    ifstream ifRecord(".\\data\\record.txt",ios::in);
    if(!ifRecord.is_open())
    {
        cout<<"δ�ҵ���¼�ļ���"<<endl;
        ifRecord.close();
        exit(-1);
    }
    string stmp;
    getline(ifRecord,stmp);
    if(ifRecord.eof())
    {
        cout<<"���޼�¼�������鼮���Զ����ɼ�¼��"<<endl;
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
        //������vector������˳������һ����˵����ֱ��ͨ�������±���Ӽ�¼���������ɾ���������˳����ܺ�id��������������find
        //��֤��ȷ�Ե�ͬʱ�ӿ�Ч��
        if(state==1)
        {
            itbook->num-=1;
            ituser->bookNum+=1;
        }
    }
    ifRecord.close();
}
//user���д���ļ�
void library::add(const user& thisUser)
{
    ofstream ofUser(".\\data\\user.txt",ios::app);
    ofUser<<thisUser.id<<'\t'<<thisUser.name<<'\t'<<thisUser.password<<endl;
    ofUser.close();
}
//admin���д���ļ�
void library::add(const admin& thisAdmin)
{
    ofstream ofAdmin(".\\data\\admin.txt",ios::app);
    ofAdmin<<thisAdmin.id<<'\t'<<thisAdmin.name<<'\t'<<thisAdmin.password<<endl;
    ofAdmin.close();
}
//book���д���ļ�
void library::add(const book& thisBook)
{
    ofstream ofBook(".\\data\\book.txt",ios::app);
    ofBook<<thisBook.id<<'\t'<<thisBook.ISBN<<'\t'<<thisBook.name<<'\t'<<thisBook.author<<'\t'<<thisBook.publisher<<
          '\t'<<thisBook.date<<'\t'<<thisBook.price<<'\t'<<thisBook.pages<<'\t'<<thisBook.allnum<<endl;
    ofBook.close();
}
//record���д���ļ�
void library::add(const record& thisRecord)
{
    ofstream ofRecord(".\\data\\record.txt",ios::app);
    ofRecord<<thisRecord.id<<'\t'<<thisRecord.bookId<<'\t'<<thisRecord.userId<<'\t'<<thisRecord.state<<'\t'<<
        thisRecord.timeBorrow<<'\t'<<thisRecord.timeBack<<endl;
    ofRecord.close();
}
//user�޸�д���ļ�
void library::changeUser()
{
    ofstream ofUser(".\\data\\user.txt",ios::out);
    ofUser<<"id	name	password"<<endl;
    for(auto thisUser : huser)
        ofUser<<thisUser.id<<'\t'<<thisUser.name<<'\t'<<thisUser.password<<endl;
    ofUser.close();
}
//book�޸�д���ļ�
void library::changeBook()
{
    ofstream ofBook(".\\data\\book.txt",ios::out);
    ofBook<<"id	isbn	name	author	publishing	publisheddate	price	pages\tallnum"<<endl;
    for(auto thisBook : hbook)
        ofBook<<thisBook.id<<'\t'<<thisBook.ISBN<<'\t'<<thisBook.name<<'\t'<<thisBook.author<<'\t'<<thisBook.publisher<<
              '\t'<<thisBook.date<<'\t'<<thisBook.price<<'\t'<<thisBook.pages<<'\t'<<thisBook.allnum<<endl;
    ofBook.close();
}
//record�޸�д���ļ�
void library::changeRecord()
{
    ofstream ofRecord(".\\data\\record.txt",ios::out);
    ofRecord<<"id	book_id	user_id	state\ttimeBorrow\ttimeBack"<<endl;
    for(auto thisRecord : hrecord)
        ofRecord<<thisRecord.id<<'\t'<<thisRecord.bookId<<'\t'<<thisRecord.userId<<'\t'<<thisRecord.state<<'\t'<<
        thisRecord.timeBorrow<<'\t'<<thisRecord.timeBack<<endl;
    ofRecord.close();
}
//��¼����
void library::land()
{
    while(1)
    {
        int type;
        cout<<"����������"<<setfill('-')<<setw(19)<<huser.size()<<endl;
        cout<<"����Ա������"<<setfill('-')<<setw(17)<<hadmin.size()<<endl;
        cout<<"�鼮������"<<setfill('-')<<setw(19)<<hbook.size()<<endl;
        cout<<"���ļ�¼������"<<setfill('-')<<setw(15)<<hrecord.size()<<endl;
        cout<<setfill(' ');
        getTime();
        cout<<"-----------------------------"<<endl;
        cout<<"---��ӭʹ��H��ѧͼ���ϵͳ---"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"------��ѡ����ĵ�¼ģʽ-----"<<endl;
        cout<<"---------0-ע�����û�--------"<<endl;
        cout<<"---------1-����Ա------------"<<endl;
        cout<<"---------2-����--------------"<<endl;
        cout<<"---------3-�ο�--------------"<<endl;
        cout<<"---------4-�˳�--------------"<<endl;
        cout<<"���������ѡ��"<<endl;
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
                cout<<"���޹���Ա����ע�ᣡ"<<endl;
                break;
            }
            vector<admin>::iterator it;
            cout<<"---------��¼��ʽ------------"<<endl;
            cout<<"---------1-ID----------------"<<endl;
            cout<<"---------2-�û���------------"<<endl;
            cout<<"---------3-���ؿ�ʼ����------"<<endl;
            int loadType;
            string password;
            cin>>loadType;
            switch(loadType)
            {
            case 1:
            {
                cout<<"������ID��";
                int id;
                while(cin>>id,it=find(hadmin.begin(),hadmin.end(),id),it==hadmin.end())
                {
                    cout<<"δ�ҵ��ù���Ա�����������룺";
                }
                cout<<"���������룺";
                while(cin>>password,it->password!=password)
                {
                    cout<<"����������������룺";
                }
                cout<<"��¼�ɹ��������������Ա��ҳ��"<<endl;
                adminUI();
                break;
            }
            case 2:
            {
                cout<<"�������û�����";
                string name;
                while(cin>>name,it=find(hadmin.begin(),hadmin.end(),name),it==hadmin.end())
                {
                    cout<<"δ�ҵ��ù���Ա�����������룺";
                }
                cout<<"���������룺";
                while(cin>>password,it->password!=password)
                {
                    cout<<"����������������룺";
                }
                cout<<"��¼�ɹ��������������Ա��ҳ��"<<endl;
                adminUI();
                break;
            }
            case 3:
                break;
            default:
                cout<<"����������������룡"<<endl;
            }
            break;
        }
        case 2:
        {
            if(huser.empty())
            {

                cout<<"���޶��ߣ���ע�ᣡ"<<endl;
                break;
            }
            vector<user>::iterator it;
            cout<<"---------��¼��ʽ------------"<<endl;
            cout<<"---------1-ID----------------"<<endl;
            cout<<"---------2-�û���------------"<<endl;
            cout<<"---------3-���ؿ�ʼ����------"<<endl;
            int loadType;
            string password;
            cin>>loadType;
            switch(loadType)
            {
            case 1:
            {
                cout<<"������ID��";
                int id;
                while(cin>>id,it=find(huser.begin(),huser.end(),id),it==huser.end())
                {
                    cout<<"δ�ҵ��ö��ߣ����������룺";
                }
                cout<<"���������룺";
                while(cin>>password,it->password!=password)
                {
                    cout<<"����������������룺";
                }
                cout<<"��¼�ɹ����������������ҳ��"<<endl;
                userUI(it->id);
                break;
            }
            case 2:
            {
                cout<<"�������û�����";
                string name;
                while(cin>>name,it=find(huser.begin(),huser.end(),name),it==huser.end())
                {
                    cout<<"δ�ҵ��ö��ߣ����������룺";
                }
                cout<<"���������룺";
                while(cin>>password,it->password!=password)
                {
                    cout<<"����������������룺";
                }
                cout<<"��¼�ɹ����������������ҳ��"<<endl;
                userUI(it->id);
                break;
            }
            case 3:
                break;
            default:
                cout<<"����������������룡"<<endl;
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
            cout<<"�����˳�����ӭ�´�ʹ�ã�"<<endl;
            return;
            break;
        }

        default:
            cout<<"����������������룡"<<endl;
        }
        system("pause");
        system("cls");
    }
}
//ע�����
void library::enroll()
{
    system("pause");
    system("cls");
    getTime();
    int type;
    cout<<"-----------------------------"<<endl;
    cout<<"----------ע�����-----------"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"------��ѡ������û�����-----"<<endl;
    cout<<"---------1-����Ա------------"<<endl;
    cout<<"---------2-����--------------"<<endl;
    cout<<"---------3-���ؿ�ʼ����------"<<endl;
    while(1)
    {
        cout<<"���������ѡ��"<<endl;
        cin>>type;
        switch(type)
        {
        case 1:
        {
            string name,password;
            cout<<"�������û����������ո񣩣�";
            while(cin>>name,!hadmin.empty()&&find(hadmin.begin(),hadmin.end(),name)!=hadmin.end())
                cout<<"���û�����ע�ᣡ�������������Ա����"<<endl;
            cout<<"���������루�����ո񣩣�";
            cin>>password;
            int id;
            if(hadmin.empty())
                id=1;
            else
                id=(hadmin.end()-1)->id+1;
            cout<<"��Ϊ���Զ������˺ţ�����ID�ǣ�"<<id<<endl;
            admin atmp(id,name,password);
            hadmin.push_back(atmp);
            add(atmp);
            cout<<"���ѳɹ�ע�ᣬ�������ص�¼���棡"<<endl;
            return;
            break;
        }
        case 2:
        {
            string name,password;
            cout<<"�������û����������ո񣩣�";
            while(cin>>name,!huser.empty()&&find(huser.begin(),huser.end(),name)!=huser.end())
                cout<<"���û�����ע�ᣡ�����������������"<<endl;

            cout<<"���������루�����ո񣩣�";
            cin>>password;
            int id;
            if(huser.empty())
                id=1;
            else
                id=(huser.end()-1)->id+1;
            cout<<"��Ϊ���Զ������˺ţ�����ID�ǣ�"<<id<<endl;
            user utmp(id,name,password);
            huser.push_back(utmp);
            add(utmp);
            cout<<"���ѳɹ�ע�ᣬ�������ص�¼���棡"<<endl;
            return;
            break;
        }
        case 3:
            return;
            break;
        default:
            cout<<"����������������룡"<<endl;
        }
    }
}
//����Ա����
void library::adminUI()
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        int type;
        cout<<"-----------------------------"<<endl;
        cout<<"----------����Ա����---------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"------��ѡ����Ĺ���ģʽ-----"<<endl;
        cout<<"-------1-������Ϣ����--------"<<endl;
        cout<<"-------2-�鼮��Ϣ����--------"<<endl;
        cout<<"-------3-������Ϣչʾ--------"<<endl;
        cout<<"-------4-����Ա��Ϣչʾ------"<<endl;
        cout<<"-------5-������Ϣչʾ--------"<<endl;
        cout<<"-------6-�˳��˺�------------"<<endl;
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
            cout<<"����������������룡"<<endl;
            break;
        }
    }
}
//���߹������
void library::manageUser()
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"-----------------------------"<<endl;
        cout<<"--------�����û�����---------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"--1-�����û���Ϣ-------------"<<endl;
        cout<<"--2-�����û���Ϣ�����ġ�ɾ��-"<<endl;
        cout<<"--3-������һ��---------------"<<endl;
        int adminType;
        cin>>adminType;
        switch(adminType)
        {
        case 1:
        {
            string name,password;
            cout<<"������Ҫ���ӵĶ����û����������ո񣩣�";
            while(cin>>name,!huser.empty()&&find(huser.begin(),huser.end(),name)!=huser.end())
                cout<<"���û�����ע�ᣡ�����������������"<<endl;
            cout<<"���������루�����ո񣩣�";
            cin>>password;
            int id;
            if(huser.empty())
                id=1;
            else
                id=(huser.end()-1)->id+1;
            cout<<"�����Ӷ����˺ţ����ߵ�ID�ǣ�"<<id<<endl;
            user utmp(id,name,password);
            huser.push_back(utmp);
            add(utmp);
            cout<<"���ѳɹ���Ӷ����û��˺ţ�"<<endl;
            break;
        }
        case 2:
        {
            vector<user>::iterator it;
            cout<<"����������ѯ�Ķ����û�����ID��";
            string name;
            while(cin>>name,(it=find(huser.begin(),huser.end(),name),it==huser.end())
                    &&(it=find(huser.begin(),huser.end(),atoi(name.c_str())),it==huser.end()))
            {
                if(name=="0")
                    break;
                cout<<"δ�ҵ��ö��ߣ�����������(���˳�������0)��";
            }
            if(name=="0")break;
            cout<<"[1]ID\t[2]�û���\t[3]����\t[4]��ʷ������\t[5]��ǰ������"<<endl;
            it->privateView();
            cout<<"--��ѡ��Ը��û����еĲ���---"<<endl;
            cout<<"--1-�޸Ķ����û���-----------"<<endl;
            cout<<"--2-�����û�����-------------"<<endl;
            cout<<"--3-ע�����û�---------------"<<endl;
            cout<<"--4-����---------------------"<<endl;
            int operation;
            while(1)
            {
                cin>>operation;
                switch(operation)
                {
                case 1:
                {
                    string newname;
                    cout<<"�������µ��û�����";
                    while(cin>>newname,!huser.empty()&&find(huser.begin(),huser.end(),newname)!=huser.end())
                        cout<<"���û�����ע�ᣡ�����������������"<<endl;
                    it->name=newname;
                    changeUser();
                    cout << "�޸ĳɹ���" << endl;
                    break;
                }
                case 2:
                {
                    cout<<"ȷ����������Ϊ123456,[Y]ȷ�ϣ����������������"<<endl;
                    char confirm;
                    cin>>confirm;
                    if(confirm=='Y')
                    {
                        it->password="123456";
                        changeUser();
                        cout<<"���óɹ���"<<endl;
                    }

                    break;
                }
                case 3:
                {
                    if(it->bookNum!=0)
                    {
                        cout<<"��ǰ��������δ�黹�鼮���޷�ע����"<<endl;
                        break;
                    }
                    cout<<"ȷ��ע��,[Y]ȷ�ϣ���������������"<<endl;
                    char confirm;
                    cin>>confirm;
                    if(confirm=='Y')
                    {
                        huser.erase(it);
                        changeUser();
                        cout<<"ע���ɹ���"<<endl;
                    }
                    break;
                }
                case 4:
                    break;
                default:
                    cout<<"����������������룡"<<endl;
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
            cout<<"����������������룡"<<endl;
        }
    }
}
//�鼮�������
void library::manageBook()
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"-----------------------------"<<endl;
        cout<<"---------�鼮��Ϣ����--------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"--1-����ͼ����Ϣ-------------"<<endl;
        cout<<"--2-����ͼ����Ϣ�����ġ�ɾ��-"<<endl;
        cout<<"--3-�鿴���а񣨺��ġ�ɾ��---"<<endl;
        cout<<"--4-������һ��---------------"<<endl;
        int adminType;
        cin>>adminType;
        switch(adminType)
        {
        case 1:
        {
            cout<<"���ģʽ[1]������Ϣ[2]�����Ϣ[3]�˳�"<<endl;
            int information;
            while(1)
            {
                cin>>information;
                switch(information)
                {
                case 1:
                {
                    stringstream sstream;
                    cout<<"��ʽ��ʾ��ISBN\t����\t����\t������\t��������\t�۸�\tҳ��\t����(���Ʊ��Ϊ�ָ�)"<<endl;
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
                    cout<<"��ӳɹ�����Ӻ����Ϣ��";
                    (hbook.end()-1)->view();
                    break;
                }
                case 2:
                {
                    int id,pages,allnum;
                    long long ISBN;
                    string name,author,date,publisher;
                    double price;
                    cout<<"������ISBN��";
                    cin>>ISBN;
                    cout<<"������������";
                    cin>>name;
                    cout<<"���������ߣ�";
                    cin>>author;
                    cout<<"����������磺";
                    cin>>publisher;
                    cout<<"������������ڣ�";
                    cin>>date;
                    cout<<"������۸�";
                    cin>>price;
                    cout<<"������ҳ����";
                    cin>>pages;
                    cout<<"�����뱾����";
                    cin>>allnum;
                    book btmp(id,ISBN,name,author,publisher,date,price,pages,allnum);
                    hbook.push_back(btmp);
                    add(btmp);
                    cout<<"��ӳɹ�����Ӻ����Ϣ��";
                    (hbook.end()-1)->view();
                    break;
                }
                case 3:
                    break;
                default:
                    cout<<"����������������룡"<<endl;
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
            cout<<"����������������룡"<<endl;
        }
    }
}
//�û�����
void library::userUI(int id)
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        int type;
        cout<<"-----------------------------"<<endl;
        cout<<"----------���߽���-----------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"------��ѡ����Ĺ���ģʽ-----"<<endl;
        cout<<"----1-�����������ģ�---------"<<endl;
        cout<<"----2-�鿴���˽��ģ����黹��-"<<endl;
        cout<<"----3-�鿴���а񣨺����ģ�---"<<endl;
        cout<<"----4-�޸�����---------------"<<endl;
        cout<<"----5-�˳��˺�---------------"<<endl;
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
                cout<<"���޽��ļ�¼��"<<endl;
                break;
            }
            cout<<"ʱ�䵹����ʾ���ļ�¼��������ʷ���������ڽ���"<<endl;
            cout<<"[0]���\t[1]�鼮ID\t[2]����״̬\t[3]����ʱ��\t[4]�黹ʱ��"<<endl;
            int i=0;
            for(; i<itUser->recordId.size(); ++i)
            {
                vector<record>::iterator itRecord=find(hrecord.begin(),hrecord.end(),*(itUser->recordId.end()-i-1));
                cout<<i+1<<'\t';
                itRecord->userView();
            }
            cout<<"��������Բ鿴�鼮��ϸ��Ϣ����δ�黹���ڴ˹黹��"<<endl;
            int number;
            while(cin>>number,number>i||number<1)
            {
                cout<<"����������������룡"<<endl;
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
                cout<<"������ԭ���룺";
                string ypassword;
                cin>>ypassword;
                cout<<"�����������룺";
                string xpassword;
                while(cin>>xpassword,xpassword==ypassword)
                {
                    cout<<"�޸���������ԭ���벻ͬ�����������룺"<<endl;
                }
                if(ypassword!=it->password)
                {
                    cout<<"ԭ����������󣡴������ν��Զ��˳��˺ţ��㻹��"<<i<<"�λ���"<<endl;
                    if(i==0)
                    {
                        cout<<"�����˳��˺ţ�������������ϵ����Ա�������룡"<<endl;
                        return;
                    }
                }
                else
                {
                    it->password=xpassword;
                    changeUser();
                    cout<<"�޸ĳɹ���"<<endl;
                    break;
                }
            }
            break;
        }
        case 5:
            return;
            break;
        default:
            cout<<"����������������룡"<<endl;
            break;
        }
    }
}
//�οͽ���
void library::visitorUI()
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        int type;
        cout<<"-----------------------------"<<endl;
        cout<<"----------�οͽ���-----------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"------��ѡ����Ĺ���ģʽ-----"<<endl;
        cout<<"---------1-����--------------"<<endl;
        cout<<"---------2-���а�------------"<<endl;
        cout<<"---------3-���ؿ�ʼ����------"<<endl;
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
            cout<<"����������������룡"<<endl;
            break;
        }
    }
}
//��������
void library::searchingUI(int type,int id)
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        int information;
        cout<<"-----------------------------"<<endl;
        cout<<"----------��������-----------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"------��ѡ�����������Ϣ-----"<<endl;
        cout<<"---------1-����--------------"<<endl;
        cout<<"---------2-ISBN/ISSN---------"<<endl;
        cout<<"---------3-����--------------"<<endl;
        cout<<"---------4-������------------"<<endl;
        cout<<"---------5-�����鼮----------"<<endl;
        cout<<"---------6-�����û�����------"<<endl;
        cin>>information;
        switch(information)
        {
        case 1:
        {
            cout<<"������������";
            string name;
            vector<book>::iterator it;
            while(cin>>name,it=find(hbook.begin(),hbook.end(),name),it==hbook.end())
            {
                if(name=="0")
                    break;
                cout<<"δ�ҵ��鼮�����������룡��Ҫ�˳�������0"<<endl;
            }
            if(name=="0")
                break;
            cout<<"��׼�������ҵ�һ����Ϣ��"<<endl;
            cout<<"[1]ISBN\t[2]����\t[3]����\t[4]������\t[5]��������\t[6]�۸�\t[7]ҳ��\t[8]��ʷ��������\t[9]ʣ������\t[10]��ǰ��������"<<endl;
            it->view();
            switch(type)
            {
            case 1:
            {
                cout<<"����Ա��ݣ��Ƿ��޸ģ�[Y]�ǣ����������"<<endl;
                char c;
                cin>>c;
                if(c!='Y')
                    break;
                if(it->revise())
                {
                    hbook.erase(it);
                    cout<<"�ѳɹ�ɾ����"<<endl;
                }
                changeBook();
                break;
            }
            case 2:
            {
                cout<<"������ݣ��Ƿ���ģ�[Y]�ǣ����������"<<endl;
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
                cout<<"�ο���ݣ����������"<<endl;
                break;
            }
            break;
        }
        case 2:
        {
            cout<<"������ISBN��";
            long long ISBN;
            vector<book>::iterator it;
            while(cin>>ISBN,it=find(hbook.begin(),hbook.end(),ISBN),it==hbook.end())
            {
                if(ISBN==0)
                    break;
                cout<<"δ�ҵ��鼮�����������룡��Ҫ�˳�������0"<<endl;
            }
            if(ISBN==0)
                break;
            cout<<"��׼�������ҵ�һ����Ϣ��"<<endl;
            cout<<"[1]ISBN\t[2]����\t[3]����\t[4]������\t[5]��������\t[6]�۸�\t[7]ҳ��\t[8]��ʷ��������\t[9]����״̬"<<endl;
            it->view();
            switch(type)
            {
            case 1:
            {
                cout<<"����Ա��ݣ��Ƿ��޸ģ�[Y]�ǣ����������"<<endl;
                char c;
                cin>>c;
                if(c!='Y')
                    break;
                if(it->revise())
                {
                    hbook.erase(it);
                    cout<<"�ѳɹ�ɾ����"<<endl;
                }
                changeBook();
                break;
            }
            case 2:
            {
                cout<<"������ݣ��Ƿ���ģ�[Y]�ǣ����������"<<endl;
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
                cout<<"�ο���ݣ����������"<<endl;
                break;
            }
            break;
        }
        case 3:
        {
            cout<<"��������������";
            string author;
            while(cin>>author,find(hbook.begin(),hbook.end(),author)==hbook.end())
            {
                if(author=="0")
                    break;
                cout<<"δ�ҵ��鼮�����������룡��Ҫ�˳�������0"<<endl;
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
            cout<<"���������������";
            string publisher;
            while(cin>>publisher,find(hbook.begin(),hbook.end(),publisher)==hbook.end())
            {
                if(publisher=="0")
                    break;
                cout<<"δ�ҵ��鼮�����������룡��Ҫ�˳�������0"<<endl;
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
            cout<<"����������������룡"<<endl;
            break;
        }
    }
}
//�����鼮������Ϣ
void library::searching(vector<book*>&result,int type,int id)
{
    int page=1,allPage=ceil(result.size()/10.0);
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"ģ�����������ҵ�"<<result.size()<<"���鼮��"<<endl;
        cout<<"ÿҳ��ʾ10���鼮����"<<allPage<<"ҳ����ǰλ�ڵ�"<<page<<"ҳ"<<endl;
        cout<<"[0]���\t[1]ISBN\t[2]����\t[3]����\t[4]������\t[5]��������\t[6]�۸�\t[7]ҳ��\t[8]��ʷ��������\t[9]ʣ������\t[10]��ǰ��������"<<endl;
        int i;
        for(i=(page-1)*10; i<page*10&&i<result.size(); ++i)
        {
            cout<<i-(page-1)*10+1<<'\t';
            result[i]->view();
        }
        cout<<"[1]��һҳ [2]��һҳ [3]��һҳ [4]���һҳ [5]��ת��ָ��ҳ [6]�˳�";
        switch(type)
        {
        case 1:
            cout<<" [7]�޸�ͼ��"<<endl;
            break;
        case 2:
            cout<<" [7]����ͼ��"<<endl;
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
                cout<<"��ǰλ�ڵ�һҳ�����ɽ�����һҳ��"<<endl;
            else
                page-=1;
            break;
        case 3:
            if(page==allPage)
                cout<<"��ǰλ�����һҳ�����ɽ�����һҳ��"<<endl;
            else
                page+=1;
            break;
        case 4:
            page=allPage;
            break;
        case 5:
        {
            int j;
            cout<<"��������תҳ����";
            cin>>j;
            if(j==page)
                cout<<"������ת����ǰҳ��"<<endl;
            else if(j<1||j>allPage)
                cout<<"ָ��ҳ�����ڣ�"<<endl;
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
                cout<<"��������Ҫ�޸ĵ��鼮�ڴ�ҳ�����:";
                int number;
                while(cin>>number,number>i-(page-1)*10||number<1)
                {
                    cout<<"����������������룡"<<endl;
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
                cout<<"��������Ҫ���ĵ��鼮�ڴ�ҳ�����:";
                int number;
                while(cin>>number,number>i||number<1)
                {
                    cout<<"����������������룡"<<endl;
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
                cout<<"����������������룡"<<endl;
                break;
            }
            break;
        default:
            cout<<"����������������룡"<<endl;
        }
    }
}
//ȫ�����ļ�¼��ʾ
void library::searching(vector<record*>&result)
{
    int page=1,allPage=ceil(result.size()/10.0);
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"���ҵ�"<<result.size()<<"�����ļ�¼����ʱ�䵹����ʾ"<<endl;
        cout<<"ÿҳ��ʾ10����¼����"<<allPage<<"ҳ����ǰλ�ڵ�"<<page<<"ҳ"<<endl;
        cout<<"[0]���\t[1]�鼮ID\t[2]�û�ID\t[3]����״̬\t[4]����ʱ��\t[5]�黹ʱ��"<<endl;
        int i;
        for(i=(page-1)*10; i<page*10&&i<result.size(); ++i)
        {
            cout<<i-(page-1)*10+1<<'\t';
            result[i]->adminView();
        }
        cout<<"[1]��һҳ [2]��һҳ [3]��һҳ [4]���һҳ [5]��ת��ָ��ҳ [6]�˳� [7]�鿴��ϸ��Ϣ"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            page=1;
            break;
        case 2:
            if(page==1)
                cout<<"��ǰλ�ڵ�һҳ�����ɽ�����һҳ��"<<endl;
            else
                page-=1;
            break;
        case 3:
            if(page==allPage)
                cout<<"��ǰλ�����һҳ�����ɽ�����һҳ��"<<endl;
            else
                page+=1;
            break;
        case 4:
            page=allPage;
            break;
        case 5:
        {
            int j;
            cout<<"��������תҳ����";
            cin>>j;
            if(j==page)
                cout<<"������ת����ǰҳ��"<<endl;
            else if(j<1||j>allPage)
                cout<<"ָ��ҳ�����ڣ�"<<endl;
            else
                page=j;
            break;
        }
        case 6:
            return;
            break;
        case 7:
        {
            cout<<"��������Ҫ�鿴�ļ�¼�ڴ�ҳ�����:";
            int number;
            while(cin>>number,number>i-(page-1)*10||number<1)
            {
                cout<<"����������������룡"<<endl;
            }
            number+=(page-1)*10-1;
            vector<book>::iterator itBook=find(hbook.begin(),hbook.end(),result[number]->bookId);
            vector<user>::iterator itUser=find(huser.begin(),huser.end(),result[number]->userId);
            if(itBook!=hbook.end())
            {
                cout<<"�鼮��Ϣ��";
                cout<<"[1]ISBN\t[2]����\t[3]����\t[4]������\t[5]��������\t[6]�۸�\t[7]ҳ��\t[8]��ʷ��������\t[9]ʣ������\t[10]��ǰ��������"<<endl;
                itBook->view();
            }
            else
                cout<<"���鼮��ɾ�����޷��鿴��ϸ�鼮��Ϣ��"<<endl;
            if(itUser!=huser.end())
            {
                cout<<"������Ϣ��";
                cout<<"[1]ID\t[2]�û���\t[3]��ʷ������\t[6]��ǰ������"<<endl;
                itUser->view();
            }
            else
                cout<<"�ö�����ɾ�����޷��鿴��ϸ������Ϣ��"<<endl;
            break;
        }
        default:
            cout<<"����������������룡"<<endl;
        }
    }
}
//ȫ���û���ʾ
void library::searching(vector<user*>&result)
{
    int page=1,allPage=ceil(result.size()/10.0);
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"���ҵ�"<<result.size()<<"�����ߣ�"<<endl;
        cout<<"ÿҳ��ʾ10���û�����"<<allPage<<"ҳ����ǰλ�ڵ�"<<page<<"ҳ"<<endl;
        cout<<"[1]ID\t[2]�û���\t[3]����\t[4]��ʷ������\t[5]��ǰ������"<<endl;
        int i;
        for(i=(page-1)*10; i<page*10&&i<result.size(); ++i)
        {
            result[i]->privateView();
        }
        cout<<"[1]��һҳ [2]��һҳ [3]��һҳ [4]���һҳ [5]��ת��ָ��ҳ [6]�˳�"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            page=1;
            break;
        case 2:
            if(page==1)
                cout<<"��ǰλ�ڵ�һҳ�����ɽ�����һҳ��"<<endl;
            else
                page-=1;
            break;
        case 3:
            if(page==allPage)
                cout<<"��ǰλ�����һҳ�����ɽ�����һҳ��"<<endl;
            else
                page+=1;
            break;
        case 4:
            page=allPage;
            break;
        case 5:
        {
            int j;
            cout<<"��������תҳ����";
            cin>>j;
            if(j==page)
                cout<<"������ת����ǰҳ��"<<endl;
            else if(j<1||j>allPage)
                cout<<"ָ��ҳ�����ڣ�"<<endl;
            else
                page=j;
            break;
        }
        case 6:
            return;
            break;
        default:
            cout<<"����������������룡"<<endl;
        }
    }
}
//ȫ������Ա��ʾ
void library::searching(vector<admin*>&result)
{
    int page=1,allPage=ceil(result.size()/10.0);
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        cout<<"���ҵ�"<<result.size()<<"������Ա��"<<endl;
        cout<<"ÿҳ��ʾ10���û�����"<<allPage<<"ҳ����ǰλ�ڵ�"<<page<<"ҳ"<<endl;
        cout<<"[1]ID\t[2]�û���\t[3]����"<<endl;
        int i;
        for(i=(page-1)*10; i<page*10&&i<result.size(); ++i)
        {
            result[i]->view();
        }
        cout<<"[1]��һҳ [2]��һҳ [3]��һҳ [4]���һҳ [5]��ת��ָ��ҳ [6]�˳�"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            page=1;
            break;
        case 2:
            if(page==1)
                cout<<"��ǰλ�ڵ�һҳ�����ɽ�����һҳ��"<<endl;
            else
                page-=1;
            break;
        case 3:
            if(page==allPage)
                cout<<"��ǰλ�����һҳ�����ɽ�����һҳ��"<<endl;
            else
                page+=1;
            break;
        case 4:
            page=allPage;
            break;
        case 5:
        {
            int j;
            cout<<"��������תҳ����";
            cin>>j;
            if(j==page)
                cout<<"������ת����ǰҳ��"<<endl;
            else if(j<1||j>allPage)
                cout<<"ָ��ҳ�����ڣ�"<<endl;
            else
                page=j;
            break;
        }
        case 6:
            return;
            break;
        default:
            cout<<"����������������룡"<<endl;
        }
    }
}
//���а����
void library::rankingUI(int type,int id)
{
    while(1)
    {
        system("pause");
        system("cls");
        getTime();
        int rankType;
        cout<<"-----------------------------"<<endl;
        cout<<"------------���а�-----------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"-------��ѡ�����а�����------"<<endl;
        cout<<"-----1-���Ĵ���ǰʮ��ͼ��----"<<endl;
        cout<<"-----2-���Ĵ���ǰʮ�Ķ���----"<<endl;
        cout<<"-----3-���³���ǰʮ��ͼ��----"<<endl;
        cout<<"-----4-�����û�����----------"<<endl;
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
            cout<<"���Ĵ���ǰʮͼ�����а�"<<endl;
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
            cout<<"���Ĵ���ǰʮ�������а�"<<endl;
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
            cout<<"���³���ǰʮͼ�����а�"<<endl;
            ranking(result,type,id);
            break;
        }
        case 4:
            return;
            break;
        default:
            cout<<"����������������룡"<<endl;
            break;
        }
    }
}
//���³������кͽ���ǰʮͼ������
void library::ranking(vector<book*>&result,int type,int id)
{
    cout<<"[0]����\t[1]ISBN\t[2]����\t[3]����\t[4]������\t[5]��������\t[6]�۸�\t[7]ҳ��\t[8]��ʷ��������\t[10]ʣ������\t[11]��ǰ��������"<<endl;
    for(int i=0; i<10; ++i)
    {
        cout<<i+1<<'\t';
        result[i]->view();
    }
    switch(type)
    {
    case 1:
    {
        cout<<"����Ա��ݣ����޸��鼮�����������޸ģ������������������˳���"<<endl;
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
        cout<<"������ݣ��ɽ����鼮�������������ģ������������������˳���"<<endl;
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
        cout<<"�ο���ݣ����������"<<endl;
        break;
    }
}
//���Ķ�������
void library::ranking(vector<user*>&result,int type,int id)
{
    cout<<"[0]����\t[1]ID\t[2]�û���\t[3]��ʷ������\t[4]��ǰ������"<<endl;
    for(int i=0; i<10; ++i)
    {
        cout<<i+1<<'\t';
        result[i]->view();
    }
}

