#include"library.h"
//�鼮������Ϣ��ʾ
void book::view()
{
    cout<<ISBN<<"\t"<<name<<"\t"<<author<<"\t"<<publisher<<"\t"<<date<<"\t"<<price<<"\t"<<pages<<"\t"<<recordId.size()<<"\t";
    cout<<"ʣ��"<<num<<"��\t��ǰ��������"<<allnum-num<<endl;
}
//�鼮����
int book::lend(vector<user>::iterator &thisUser)
{
    cout<<"��Ҫ���ĵ��鼮��Ϣ��"<<endl;
    view();
    if(num==0)
    {
        cout<<"��ǰ�鼮�ѽ��꣬����ʧ�ܣ�"<<endl;
        return 0;
    }
    if(thisUser->bookNum==3)
    {
        cout<<"ÿ��ͬʱֻ�ܽ����������ѽ���������ʧ�ܣ�"<<endl;
        return 0;
    }
    cout<<"[Y]ȷ�Ͻ���;������������ȡ������"<<endl;
    char confirm;
    cin>>confirm;
    if(confirm!='Y')
        return 0;
    num-=1;
    thisUser->bookNum++;
    cout<<"���ĳɹ���"<<endl;
    return 1;
}
//�鼮�黹
int book::rlend(vector<user>::iterator &thisUser,int state)
{
    cout<<"���ļ�¼��ϸ�鼮��Ϣ��"<<endl;
    cout<<"[1]ISBN"<<setw(7)<<" "<<setw(25)<<left<<"[2]����"<<setw(10)<<left<<"[3]����"<<setw(10)<<left
        <<"[4]������\t[5]��������\t[6]�۸�\t[7]ҳ��\t[8]��ʷ��������\t[9]ʣ������\t[10]��ǰ��������"<<endl;
    view();
    if(state==0)
    {
        cout<<"��ǰ�鼮���ѹ黹��"<<endl;
        return 0;
    }
    cout<<"��ǰ�鼮δ�黹���Ƿ�黹��"<<endl;
    cout<<"[Y]ȷ�Ϲ黹;������������ȡ���黹"<<endl;
    char confirm;
    cin>>confirm;
    if(confirm!='Y')
        return 0;
    num+=1;
    thisUser->bookNum--;
    cout<<"�黹�ɹ���"<<endl;
    return 1;
}
//�鼮�޸�
int book::revise()
{
    cout<<"��Ҫ�޸ĵ��鼮��Ϣ��"<<endl;
    view();
    cout<<"��ѡ����Ĳ�����[1]�޸��鼮������Ϣ [2]ɾ���鼮 [3]����鼮 ������������ȡ���޸�"<<endl;
    int type;
    cin>>type;
    switch(type)
    {
    case 1:
    {
        while(1)
        {
            cout<<"��������Ҫ�޸ĵľ�����Ϣ��[0]ȫ��[1]ISBN[2]����[3]����[4]������[5]��������[6]�۸�[7]ҳ��[8]����[9]ȡ��"<<endl;
            int number;
            cin>>number;
            switch(number)
            {
            case 0:
            {
                stringstream sstream;
                cout<<"��ʽ��ʾ��ISBN\t����\t����\t������\t��������\t�۸�\tҳ��\t����(���Ʊ��Ϊ�ָ�)"<<endl;
                string stmp;
                cin.ignore();
                getline(cin,stmp);
                vector<string> res = split(stmp, '\t');
                name=res[1],author=res[2],publisher=res[3],date=res[4];
                sstream<<res[0]<<res[5]<<' '<<res[6]<<' '<<res[7];
                sstream>>ISBN>>price>>pages>>allnum;
                sstream.clear();
                sstream.str("");
                cout<<"�޸ĳɹ����޸ĺ����Ϣ��";
                view();
                break;
            }
            case 1:
            {
                cout<<"������ISBN��";
                cin>>ISBN;
                cout<<"�޸ĳɹ����޸ĺ����Ϣ��";
                view();
                break;
            }
            case 2:
            {
                cout<<"������������";
                cin.ignore();
                getline(cin,name);
                cout<<"�޸ĳɹ����޸ĺ����Ϣ��";
                view();
                break;
            }
            case 3:
            {
                cout<<"���������ߣ�";
                cin.ignore();
                getline(cin,author);
                cout<<"�޸ĳɹ����޸ĺ����Ϣ��";
                view();
                break;
            }
            case 4:
            {
                cout<<"����������磺";
                cin.ignore();
                getline(cin,publisher);
                cout<<"�޸ĳɹ����޸ĺ����Ϣ��";
                view();
                break;
            }
            case 5:
            {
                cout<<"������������ڣ�";
                cin>>date;
                cout<<"�޸ĳɹ����޸ĺ����Ϣ��";
                view();
                break;
            }
            case 6:
            {
                cout<<"������۸�";
                cin>>price;
                cout<<"�޸ĳɹ����޸ĺ����Ϣ��";
                view();
                break;
            }
            case 7:
            {
                cout<<"������ҳ����";
                cin>>pages;
                cout<<"�޸ĳɹ����޸ĺ����Ϣ��";
                view();
                break;
            }
            case 8:
                {
                    cout<<"�����뱾����";
                    int o;
                    cin>>allnum;
                    num+=allnum-o;
                    cout<<"�޸ĳɹ����޸ĺ����Ϣ��";
                    view();
                    break;
                }
            case 9:
            {
                return 0;
                break;
            }
            default:
                cout<<"����������������룡"<<endl;
            }

        }
        break;
    }
    case 2:
    {
        if(num!=allnum)
        {
            cout<<"��ǰ�鼮����δ�黹��¼���޷�ɾ����"<<endl;
            return 0;
        }
        cout<<"ȷ��ɾ��[Y]��������������ȡ��ɾ��"<<endl;
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
        cout<<"��������Ҫ��ӵı�����";
        int n;
        cin>>n;
        num+=n;
        allnum+=n;
        cout<<"�޸ĳɹ����޸ĺ����Ϣ��";
        view();
    }
    }
    return 0;
}
//�鼮��Ӳ�����Ϊ�鼮��ĳ�Ա����
