#include    <iostream>
using    namespace    std;
//整型向量类
class    intMyVector
{
	public:
		//构造函数
		intMyVector(int    count)
		{
			n=count;
			p=new    int[count];
		}

	friend ostream&    operator    <<    (ostream&  out,intMyVector&  v);
	friend istream&    operator    >>    (istream&  in,intMyVector&  v);
	intMyVector& operator +(intMyVector &v)
	{
		for(int i=0;i<n;++i)
			p[i]+=v.p[i];
		return *this;
	}//其实不对，应该返回临时变量 


	private:
		int    n;
		int    *p;
};
istream&    operator    >>    (istream&  in,intMyVector&  v)
{
	for(int i=0;i<v.n;++i)
	{
		in>>v.p[i];
	}
	return in;
}


//补充代码

ostream&    operator    <<    (ostream&  out,intMyVector&  v)
{
	for(int  i=0; i<v.n; i++)
	{
		out<<v.p[i]<<"  ";
	}
	return  out;
}
int    main()
{
	int    n;
	cin>>n;
	intMyVector  a(n),b(n);
	cin>>a;
	cin>>b;
	b=a+b;
	cout<<b;
	return    0;
}


