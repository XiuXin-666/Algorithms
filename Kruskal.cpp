#include<iostream>
#include <vector>
#include <queue>
using namespace std;

//	������������ �� �ߵ�Ȩֵ
typedef struct Edge {
	int vexa;
	int vexb;
	int value;
}Edge;
vector<Edge> Tree;	//��С������

//��������أ����ȶ�����������
typedef struct temp {
	bool operator()(Edge a, Edge b) {
		return a.value > b.value;
	}
}temp;
priority_queue < Edge, vector<Edge>, temp> q;	//���ȶ��������

//���鼯�����һ�����
vector<int> pre;

//���鼯���Ҹ��ڵ�
int unionsearch(int root) {
	int son, tmp;
	son = root;
	while (root != pre[root]) //Ѱ�Ҹ����
		root = pre[root];
	while (son != root) { //·��ѹ��
		tmp = pre[son];
		pre[son] = root;
		son = tmp;
	}
	return root;
}

//�ж��������Ƿ���ͬһ���鼯
bool join(int root1, int root2) { //�ж��Ƿ���ͨ������ͨ�ͺϲ�
	int x, y;
	x = unionsearch(root1);
	y = unionsearch(root2);
	if (x == y) //�����ͨ����true
		return true;
	else {		//�������ͨ���Ͱ��������ڵ���ͨ��֧�ϲ�
		pre[x] = y;
		return false;
	}
}


//Kruskal�㷨
int Kruskal() {
	int sum = 0;	//��Ȩֵ
	while (!q.empty()) {
		Edge edge = q.top();
		int a = edge.vexa;
		int b = edge.vexb;
		if (!join(a, b)) {	//a,b���� ����ͬһ���鼯������ͬһ����������ϲ�
			Tree.push_back(edge);	//���뵽��С��������
			sum += edge.value;
		}
		q.pop();
	}
	return sum;
}

//int main() {
//	int vexNum, edgeNum;
//	cout << "���붥�����ͱ�����";
//	cin >> vexNum >> edgeNum;
//
//	cout << "�����ڽӱߺ�Ȩֵa b w��" << endl;
//	char A, B;
//	int w;
//	for (int i = 0; i < edgeNum; i++) {
//		cin >> A >> B >> w;
//		int a = A - 64;
//		int b = B - 64;
//		Edge edge;	//������Ϣ���沢�������ȶ�����
//		edge.vexa = a;
//		edge.vexb = b;
//		edge.value = w;
//		q.push(edge);	//���
//	}
//
////	��ʼ�����鼯
//	pre.resize(vexNum + 1);
//	for (int i = 1; i <= vexNum; i++)
//		pre[i] = i;
//
//
//	int sum = Kruskal();	//Kruskal�㷨
//
//	cout << endl << "��С��������ɣ�" << endl;
//	for (unsigned i = 0; i < Tree.size(); i++) {
//		cout << char(Tree[i].vexa + 64) << " -> " << char( Tree[i].vexb + 64 )<< " = " << Tree[i].value << endl;
//	}
//	cout << "��ȨֵΪ��" << sum << endl;
//
//	system("pause");
//	return 0;
//}

