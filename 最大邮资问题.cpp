#include <iostream>
#include <vector>
using namespace std;

class Stamp
{
	friend int MaxStamp(int, int, int[]);

private:
	int n;	//邮票面值数
	int m;	//每张信封最多允许贴的邮票数
	int maxvalue;	//当前最优值
	int maxint;	//大整数
	int maxl;	//邮资上界
	int* x;	//当前解
	int* y;	//贴出各种邮资所需最少邮票数
	int* bestx;	//当前最优解

	void Backtrack(int i, int r);
};

void Stamp::Backtrack(int i, int r)
{
	/*计算X[1:i]的最大连续邮资区间,考虑到直接递归的求解复杂度太高，
	我们不妨尝试计算用不超过m张面值为x[1:i]的邮票贴出邮资k所需的最少邮票数y[k]。
	通过y[k]可以很快推出r的值。事实上，y[k]可以通过递推在O(n)时间内解决*/
	for (int j = 0; j <= x[i - 2] * (m - 1); j++) //x[i-2]*(m-1)是第i-2层循环的一个上限，目的是找到r-1的值 
		if (y[j] < m)
		{
			for (int k = 1; k <= m - y[j]; k++) //k是对表示j剩余的票数进行检查   
			{
				if (y[j] + k < y[j + x[i - 1] * k])
					//x[i-1]*k是k张邮票能表示的最大邮资   
					//+j表示增加了i邮资后能   
					//判断新增加的能表示的邮资需要多少 
				{
					y[j + x[i - 1] * k] = y[j] + k;
					//对第i-2层扩展一个x[i-1]后的邮资分布
				}

			}
		}
	//查看邮资范围扩大多少，然后查询y数组从而找到r 
	while (y[r] < maxint) //计算X[1:i]的最大连续邮资区间
	{
		r++;
	}
	//搜索求出r-1的值，对应x[1:i-1]的在m张限制内的最大区间 
	if (i > n) // 如果到达发行邮票的张数，则更新最终结果值，并返回结果
	{
		if (r - 1 > maxvalue)  // 用r计算可贴出的连续邮资最大值，而maxStamp存放最终结果
		{
			maxvalue = r - 1;
			for (int j = 1; j <= n; j++)
				bestx[j] = x[j];  // 用x[i]表示当前以确定的第i+1张邮票的面值，bestx保存最终结果
		}
		return;
	}
	int* z = new int[maxl + 1];
	for (int k = 1; k <= maxl; k++)
		z[k] = y[k];
	//保留数据副本，以便返回上层时候能够恢复数据   
	//以上都是处理第i-1层及其之上的问题   
	for (int j = x[i - 1] + 1; j <= r; j++) //在第i层有这么多的孩子结点供选择   
	{
		x[i] = j;
		Backtrack(i + 1, r);//返回上层恢复信息
		for (int k = 1; k <= maxl; k++)
			y[k] = z[k];
	}
	delete[] z;
}



int MaxStamp(int n, int m, int bestx[]) {
	Stamp X;
	int maxint = 32767;
	int maxl = 1500;

	X.n = n;
	X.m = m;
	X.maxvalue = 0;
	X.maxint = maxint;
	X.maxl = maxl;
	X.bestx = bestx;
	X.x = new int[n + 1];
	X.y = new int[maxl + 1];

	for (int i = 0; i <= n; i++)
		X.x[i] = 0;
	for (int i = 1; i <= maxl; i++)
		X.y[i] = maxint;
	X.x[1] = 1;
	X.y[0] = 0;
	X.Backtrack(2, 1);
	cout << "当前最优解:";
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << "  ";
	cout << endl;
	delete[] X.x;
	delete[] X.y;
	return X.maxvalue;
}

//
//int main() {
//	int* bestx;
//	int n;
//	int m;
//	cout << "请输入邮票面值数:";
//	cin >> n;
//	cout << "请输入每张信封最多允许贴的邮票数:";
//	cin >> m;
//
//	bestx = new int[n + 1];
//	for (int i = 1; i <= n; i++)
//		bestx[i] = 0;
//
//	cout << "最大邮资:" << MaxStamp(n, m, bestx) << endl;
//	system("pause");
//	return 0;
//}