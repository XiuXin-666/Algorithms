#include <iostream>
#include <vector>
using namespace std;

//保存两个顶点 与 边的权值
typedef struct Tree {
	int vexa;
	int vexb;
	int edge;
}temp;
vector<Tree> tree;

//	prim算法
int prim(vector<vector<int> >& g) {
	int vex = g.size() - 1;		//顶点个数
	int cost = 0;	//最终生成树权值
	vector<int> mst(vex + 1);	//MST[i]表示顶点i连到MST中的哪个顶点，值=0时表示在MST中
	vector<int> MINedge(vex + 1);	//顶点i的邻接边中的最小值，值=-1时表示在MST中

	mst[1] = 0;	//将点1放入MST
	for (int i = 1; i <= vex; i++) {
		MINedge[i] = g[1][i];
		mst[i] = 1;
	}

	for (int i = 2; i <= vex; i++) {
		int MINvex = 0;		//最小边顶点
		int MINcost = INT_MAX;	//最小权值

		for (int j = 2; j <= vex; j++) {
			if (MINedge[j] < MINcost && MINedge[j] != -1) {	//最小边顶点不在MST中（两个顶点不能都在MST中）
				MINvex = j;
				MINcost = MINedge[j];
			}
		}
		Tree t;	//将点放入MST中
		t.vexa = mst[MINvex];
		t.vexb = MINvex;
		t.edge = MINcost;
		tree.push_back(t);
		cost += MINcost;
		MINedge[MINvex] = -1;

		//更新MINedge
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
	//初始化图
	int vexNum, edgeNum;
	cout << "输入顶点个数、边数：";
	cin >> vexNum >> edgeNum;
	vector<vector<int> > graph(vexNum + 1, vector<int>(vexNum + 1, INT_MAX));
	cout << "输入邻接边及权值a b w:" << endl;
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

	int cost = prim(graph);	//prim算法

	cout << endl << "最小生成树组成：" << endl;
	for (int i = 0; i < tree.size(); i++) {
		cout << char(tree[i].vexa + 64) << " -> " << char(tree[i].vexb + 64) << " = " << tree[i].edge << endl;
	}
	cout << "总权值为：" << cost << endl;

	system("pause");
	return 0;
}
