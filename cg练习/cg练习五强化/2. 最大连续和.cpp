# include <iostream>
using namespace std;
void getMaxSum(int a[], int n, int &Left, int &Right);
int main()
{
	int n;
	cin>>n;
	int *p=new int[n];
	for(int i=0; i<n; i++) cin>>p[i];
	int Left, Right;
	getMaxSum(p,n,Left,Right);
	cout<<Left<<" "<<Right<<endl;
	delete[] p;
	return 0;
}
void getMaxSum(int a[], int n, int &Left, int &Right)
{
	int sum=0,max=-2147483648;
	int l=0,r=0;
	for(int i=0;i<n;++i)
	{
		sum+=a[i];
		if(sum<0)
		{
			sum=0;
			l=i+1;
		}
		if(max<sum)
		{
			max=sum;
			Left=l;
			Right=r;
		}
		r++;
	}
}

//贪心：累加，每次比较累加和最大值，并及时记录下左右端点。如果累加为负数，则舍弃前面的数，因为后面的数加前面的负数比光后面的数要小。
//每次舍弃前面累加的负数，后面累加的数都比和前面的和要大，这样再把累加数与最大值比较，循环一次即可比较出最大值。
//双重循环会超时，贪心法是对双重循环的优化，负数整体不会重复计算。
//如果是中间负数，只要和前面的和大于0，不会被抹去
//这个方法也是分治的优化，本质还是对负数整体的舍弃，但要注意负数整体是连头连尾的
//又想了一下抽象思维：本质是三分，负正负的三个整体，（负有些情况没有）判断sum<0即是舍弃第一个负数部分（循环之）判断max<sum即是扩展正部分
//明白了，本质确实是负正负，但是这样的划分不是唯一的，判断sum<0是舍弃第一个负数部分，max<sum是扩展正数部分并更新至最大值，也就是判断
//正数部分与负数部分的边界。不过正如我前面说的划分不是唯一的，当正数累加到负值又可以融入第一个负数部分，对第二种划分情况进行判断
