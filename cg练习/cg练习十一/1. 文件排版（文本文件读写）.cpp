#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<fstream>
using namespace std;
string detab(string s)
{
	stringstream sstream(s);
	string ans,temp;
	while(sstream>>temp)
	{
		ans+=temp+' ';
	}
	return ans;
}
int main()
{
	ifstream infile("listin.txt", ios::in);
	ofstream outfile("listout.txt");
	string s;
	int x;
	cin>>x;
	while(!infile.eof())
	{
		getline(infile,s);
		if(s=="") continue;
		int a=s.find(':');
		string s1=s.substr(0,a);
		string s2=s.substr(a+1,s.size()-1-a);
		s1=detab(s1),s2=detab(s2);
		outfile<<s1+string(x-1-s1.length(),' ');
		outfile<<":"<<" "<<s2<<endl;
	}
	infile.close();
	outfile.close();
 	return 0;
}

