#include<iostream>
#include <vector>
#include <queue>
using namespace std;

//	保存两个顶点 与 边的权值
typedef struct Edge {
	int vexa;
	int vexb;
	int value;
}Edge;
vector<Edge> Tree;	//最小生成树

//运算符重载，优先队列升序排列
typedef struct temp {
	bool operator()(Edge a, Edge b) {
		return a.value > b.value;
	}
}temp;
priority_queue < Edge, vector<Edge>, temp> q;	//优先队列排序边

//并查集存放上一级结点
vector<int> pre;

//并查集查找根节点
int unionsearch(int root) {
	int son, tmp;
	son = root;
	while (root != pre[root]) //寻找根结点
		root = pre[root];
	while (son != root) { //路径压缩
		tmp = pre[son];
		pre[son] = root;
		son = tmp;
	}
	return root;
}

//判断两个点是否在同一并查集
bool join(int root1, int root2) { //判断是否连通，不连通就合并
	int x, y;
	x = unionsearch(root1);
	y = unionsearch(root2);
	if (x == y) //如果连通返回true
		return true;
	else {		//如果不连通，就把它们所在的连通分支合并
		pre[x] = y;
		return false;
	}
}


//Kruskal算法
int Kruskal() {
	int sum = 0;	//总权值
	while (!q.empty()) {
		Edge edge = q.top();
		int a = edge.vexa;
		int b = edge.vexb;
		if (!join(a, b)) {	//a,b顶点 不在同一并查集（不在同一棵树），则合并
			Tree.push_back(edge);	//加入到最小生成树中
			sum += edge.value;
		}
		q.pop();
	}
	return sum;
}

//int main() {
//	int vexNum, edgeNum;
//	cout << "输入顶点数和边数：";
//	cin >> vexNum >> edgeNum;
//
//	cout << "输入邻接边和权值a b w：" << endl;
//	char A, B;
//	int w;
//	for (int i = 0; i < edgeNum; i++) {
//		cin >> A >> B >> w;
//		int a = A - 64;
//		int b = B - 64;
//		Edge edge;	//将边信息保存并放入优先队列中
//		edge.vexa = a;
//		edge.vexb = b;
//		edge.value = w;
//		q.push(edge);	//入队
//	}
//
////	初始化并查集
//	pre.resize(vexNum + 1);
//	for (int i = 1; i <= vexNum; i++)
//		pre[i] = i;
//
//
//	int sum = Kruskal();	//Kruskal算法
//
//	cout << endl << "最小生成树组成：" << endl;
//	for (unsigned i = 0; i < Tree.size(); i++) {
//		cout << char(Tree[i].vexa + 64) << " -> " << char( Tree[i].vexb + 64 )<< " = " << Tree[i].value << endl;
//	}
//	cout << "总权值为：" << sum << endl;
//
//	system("pause");
//	return 0;
//}

