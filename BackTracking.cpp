#include <iostream>  
using namespace std;

template <class Type>
class Loading
{
	//friend Type MaxLoading(Type[],Type,int,int []);  
	//private:  
public:
	void Backtrack(int i);
	int n,          //集装箱数  
		* x,         //当前解  
		* bestx;     //当前最优解  
	Type* w,    //集装箱重量数组  
		c,          //第一艘轮船的载重量  
		cw,         //当前载重量  
		bestw,      //当前最优载重量  
		r;          //剩余集装箱重量  
};

template <class Type>
void  Loading <Type>::Backtrack(int i);

template<class Type>
Type MaxLoading(Type w[], Type c, int n, int bestx[]);

//int main()
//{
//	int n = 3, m;
//	int c = 50, c2 = 50;
//
//	int w[4] = { 0,10,40,40 };
//	int bestx[4];
//
//	m = MaxLoading(w, c, n, bestx);
//
//	cout << "轮船的载重量分别为：" << endl;
//	cout << "c(1)=" << c << ",c(2)=" << c2 << endl;
//
//	cout << "待装集装箱重量分别为：" << endl;
//	cout << "w(i)=";
//	for (int i = 1; i <= n; i++)
//	{
//		cout << w[i] << " ";
//	}
//	cout << endl;
//
//	cout << "回溯选择结果为：" << endl;
//	cout << "m(1)=" << m << endl;
//	cout << "x(i)=";
//
//	for (int i = 1; i <= n; i++)
//	{
//		cout << bestx[i] << " ";
//	}
//	cout << endl;
//
//	int m2 = 0;
//	for (int j = 1; j <= n; j++)
//	{
//		m2 = m2 + w[j] * (1 - bestx[j]);
//	}
//	cout << "m(2)=" << m2 << endl;
//
//	if (m2 > c2)
//	{
//		cout << "因为m(2)大于c(2),所以原问题无解！" << endl;
//	}
//	return 0;
//}

template <class Type>
void  Loading <Type>::Backtrack(int i)// 搜索第i层结点  
{
	if (i > n)// 到达叶结点  
	{
		if (cw > bestw)
		{
			for (int j = 1; j <= n; j++)
			{
				bestx[j] = x[j];//更新最优解  
				bestw = cw;
			}
		}
		return;
	}

	r -= w[i];
	if (cw + w[i] <= c) // 搜索左子树  
	{
		x[i] = 1;
		cw += w[i];
		Backtrack(i + 1);
		cw -= w[i];
	}

	if (cw + r > bestw)
	{
		x[i] = 0;  // 搜索右子树  
		Backtrack(i + 1);
	}
	r += w[i];
}

template<class Type>
Type MaxLoading(Type w[], Type c, int n, int bestx[])//返回最优载重量  
{
	Loading<Type>X;
	//初始化X  
	X.x = new int[n + 1];
	X.w = w;
	X.c = c;
	X.n = n;
	X.bestx = bestx;
	X.bestw = 0;
	X.cw = 0;
	//初始化r  
	X.r = 0;

	for (int i = 1; i <= n; i++)
	{
		X.r += w[i];
	}

	X.Backtrack(1);
	delete[]X.x;
	return X.bestw;
}








