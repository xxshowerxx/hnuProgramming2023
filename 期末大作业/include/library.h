#ifndef LIBRARY_H
#define LIBRARY_H
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<windows.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<fstream>
#include<iomanip>
#include<time.h>
#include"admin.h"
#include"book.h"
#include"user.h"
#include"record.h"
using namespace std;
vector<string> split(const string& s, char sep);
void getTime();
void getTime(time_t &timep);
class library
{
public:
    void bookInitial();
    void userInitial();
    void adminInitial();
    void recordInitial();
    //初始化

    void add(const user&);
    void add(const admin&);
    void add(const book&);
    void add(const record&);
    void changeUser();
    void changeBook();
    void changeRecord();
    //写入

    void land();
    void enroll();
    void visitorUI();
    void userUI(int id);
    void adminUI();

    void manageUser();
    void manageBook();

    void searchingUI(int type=3,int id=0);
    void rankingUI(int type=3,int id=0);

    void ranking(vector<book*>&result,int type=3,int id=0);
    void ranking(vector<user*>&result,int type=3,int id=0);

    void searching(vector<book*>&result,int type=3,int id=0);
    void searching(vector<record*>&result);
    void searching(vector<user*>&result);
    void searching(vector<admin*>&result);

    //UI整合

    library();
    //构造函数
private:
    vector<book> hbook;
    vector<admin> hadmin;
    vector<user> huser;
    vector<record> hrecord;
    //储存记录
};
#endif// CLIBRARY_H
