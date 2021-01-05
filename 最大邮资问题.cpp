#include <iostream>
#include <vector>
using namespace std;

class Stamp
{
	friend int MaxStamp(int, int, int[]);

private:
	int n;	//��Ʊ��ֵ��
	int m;	//ÿ���ŷ��������������Ʊ��
	int maxvalue;	//��ǰ����ֵ
	int maxint;	//������
	int maxl;	//�����Ͻ�
	int* x;	//��ǰ��
	int* y;	//����������������������Ʊ��
	int* bestx;	//��ǰ���Ž�

	void Backtrack(int i, int r);
};

void Stamp::Backtrack(int i, int r)
{
	/*����X[1:i]�����������������,���ǵ�ֱ�ӵݹ����⸴�Ӷ�̫�ߣ�
	���ǲ������Լ����ò�����m����ֵΪx[1:i]����Ʊ��������k�����������Ʊ��y[k]��
	ͨ��y[k]���Ժܿ��Ƴ�r��ֵ����ʵ�ϣ�y[k]����ͨ��������O(n)ʱ���ڽ��*/
	for (int j = 0; j <= x[i - 2] * (m - 1); j++) //x[i-2]*(m-1)�ǵ�i-2��ѭ����һ�����ޣ�Ŀ�����ҵ�r-1��ֵ 
		if (y[j] < m)
		{
			for (int k = 1; k <= m - y[j]; k++) //k�ǶԱ�ʾjʣ���Ʊ�����м��   
			{
				if (y[j] + k < y[j + x[i - 1] * k])
					//x[i-1]*k��k����Ʊ�ܱ�ʾ���������   
					//+j��ʾ������i���ʺ���   
					//�ж������ӵ��ܱ�ʾ��������Ҫ���� 
				{
					y[j + x[i - 1] * k] = y[j] + k;
					//�Ե�i-2����չһ��x[i-1]������ʷֲ�
				}

			}
		}
	//�鿴���ʷ�Χ������٣�Ȼ���ѯy����Ӷ��ҵ�r 
	while (y[r] < maxint) //����X[1:i]�����������������
	{
		r++;
	}
	//�������r-1��ֵ����Ӧx[1:i-1]����m�������ڵ�������� 
	if (i > n) // ������﷢����Ʊ����������������ս��ֵ�������ؽ��
	{
		if (r - 1 > maxvalue)  // ��r����������������������ֵ����maxStamp������ս��
		{
			maxvalue = r - 1;
			for (int j = 1; j <= n; j++)
				bestx[j] = x[j];  // ��x[i]��ʾ��ǰ��ȷ���ĵ�i+1����Ʊ����ֵ��bestx�������ս��
		}
		return;
	}
	int* z = new int[maxl + 1];
	for (int k = 1; k <= maxl; k++)
		z[k] = y[k];
	//�������ݸ������Ա㷵���ϲ�ʱ���ܹ��ָ�����   
	//���϶��Ǵ����i-1�㼰��֮�ϵ�����   
	for (int j = x[i - 1] + 1; j <= r; j++) //�ڵ�i������ô��ĺ��ӽ�㹩ѡ��   
	{
		x[i] = j;
		Backtrack(i + 1, r);//�����ϲ�ָ���Ϣ
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
	cout << "��ǰ���Ž�:";
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
//	cout << "��������Ʊ��ֵ��:";
//	cin >> n;
//	cout << "������ÿ���ŷ��������������Ʊ��:";
//	cin >> m;
//
//	bestx = new int[n + 1];
//	for (int i = 1; i <= n; i++)
//		bestx[i] = 0;
//
//	cout << "�������:" << MaxStamp(n, m, bestx) << endl;
//	system("pause");
//	return 0;
//}