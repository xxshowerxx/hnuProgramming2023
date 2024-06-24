#include<iostream>
using namespace std;
//����������
class intMyVector
{
	public:
		//���캯��
		intMyVector(int count)
		{
			n=count;
			p=new int[count];
		}
		//���ƹ��캯��
		intMyVector(intMyVector &v)
		{
			n=v.n;
			p=new  int[v.n];
			for(int i=0;i<n;i++)
				p[i]=(v.p)[i];
		}
		friend  intMyVector&  operator+(intMyVector &v1,intMyVector &v2);
		intMyVector&  operator=(intMyVector  &v);
		friend  ostream&  operator  <<  (ostream&,intMyVector&);
		friend  istream& operator>>		(istream&,intMyVector&);
		
		
		~intMyVector()
		{
			delete[] p;
		}
	private:
		int  n;
		int  *p;
};
intMyVector  mVector(3);
int    main()
{
	int n;
	cin>>n;
	intMyVector a(n),c(n);
	cin>>a;
	cin>>c;
	intMyVector b(a);
	c=a+b+c;
	cout<<c;
	return 0;
}

intMyVector& operator+(intMyVector  &v1,intMyVector  &v2)
{
	//�������
	for(int i=0;i<v1.n;++i)
		v2.p[i]+=v1.p[i];
	return v2;
	//
}

intMyVector& intMyVector::operator=(intMyVector &v)
{
	//�������
	for(int i=0;i<n;i++)
		p[i]=(v.p)[i];
	return *this;

	//
}
//�������
ostream& operator<<(ostream& output,intMyVector& v)
{
	output<<"[";
	for(int    i=0; i<(v.n-1); i++)
		output<<v.p[i]<<",";
	output<<v.p[v.n-1]<<"]"<<endl;
	return  output;
}

istream& operator>>		(istream& input,intMyVector& v)
{
	for(int i=0;i<v.n;++i)
		input>>v.p[i];
	return input;
}

//

