#include <iostream>
#include <vector>
using namespace std;

//������������ �� �ߵ�Ȩֵ
typedef struct Tree {
	int vexa;
	int vexb;
	int edge;
}temp;
vector<Tree> tree;

//	prim�㷨
int prim(vector<vector<int> >& g) {
	int vex = g.size() - 1;		//�������
	int cost = 0;	//����������Ȩֵ
	vector<int> mst(vex + 1);	//MST[i]��ʾ����i����MST�е��ĸ����㣬ֵ=0ʱ��ʾ��MST��
	vector<int> MINedge(vex + 1);	//����i���ڽӱ��е���Сֵ��ֵ=-1ʱ��ʾ��MST��

	mst[1] = 0;	//����1����MST
	for (int i = 1; i <= vex; i++) {
		MINedge[i] = g[1][i];
		mst[i] = 1;
	}

	for (int i = 2; i <= vex; i++) {
		int MINvex = 0;		//��С�߶���
		int MINcost = INT_MAX;	//��СȨֵ

		for (int j = 2; j <= vex; j++) {
			if (MINedge[j] < MINcost && MINedge[j] != -1) {	//��С�߶��㲻��MST�У��������㲻�ܶ���MST�У�
				MINvex = j;
				MINcost = MINedge[j];
			}
		}
		Tree t;	//�������MST��
		t.vexa = mst[MINvex];
		t.vexb = MINvex;
		t.edge = MINcost;
		tree.push_back(t);
		cost += MINcost;
		MINedge[MINvex] = -1;

		//����MINedge
		for (int i = 2; i <= vex; i++) {
			if (g[MINvex][i] < MINedge[i]) {
				MINedge[i] = g[MINvex][i];
				mst[i] = MINvex;
			}
		}
	}

	return cost;
}

int main() {
	//��ʼ��ͼ
	int vexNum, edgeNum;
	cout << "���붥�������������";
	cin >> vexNum >> edgeNum;
	vector<vector<int> > graph(vexNum + 1, vector<int>(vexNum + 1, INT_MAX));
	cout << "�����ڽӱ߼�Ȩֵa b w:" << endl;
	char A, B;
	int w;
	for (int i = 0; i < edgeNum; i++) {
		cin >> A >> B >> w;
		int a = A - 64;
		int b = B - 64;
		graph[a][b] = w;
		graph[b][a] = w;
	}
	for (int i = 1; i <= vexNum; i++)
		graph[i][i] = 0;

	int cost = prim(graph);	//prim�㷨

	cout << endl << "��С��������ɣ�" << endl;
	for (int i = 0; i < tree.size(); i++) {
		cout << char(tree[i].vexa + 64) << " -> " << char(tree[i].vexb + 64) << " = " << tree[i].edge << endl;
	}
	cout << "��ȨֵΪ��" << cost << endl;

	system("pause");
	return 0;
}
