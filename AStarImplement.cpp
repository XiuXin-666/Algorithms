//此代码仅可实现简单的八数码问题
//把注释去掉即为A*算法
#include "Node.h"
#include "A_algorithm.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

//
//int main() {
//	//node s0; s0.next = null; s0.parent = null;
//	//node sg; sg.next = null; sg.parent = null;
//	//cout << "please input initial node:" << endl;
//	//for (int i = 0; i < 3; i++)
//	//	for (int j = 0; j < 3; j++)
//	//		cin >> s0.node[i][j];
//	//cout << "please input goal node:" << endl;
//	//for (int i = 0; i < 3; i++)
//	//	for (int j = 0; j < 3; j++)
//	//		cin >> sg.node[i][j];
//    Node s0 = { {{2, 8, 3}, {1, 0, 4}, {7, 6, 5}}, 0, NULL };//初始化初始节点
//    Node sg = { {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}}, 0, NULL };//初始化目标节点
//    cout << "searchpath: " << endl << endl;
//    A_algorithm(&s0, &sg).algorithm();
//    return 0;
//}

