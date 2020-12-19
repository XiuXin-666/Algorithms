#pragma once
#include "Node.h"
#include <iostream>

class A_algorithm {	//A*算法搜索
public:
	A_algorithm(Node* S0, Node* Sg);        //构造函数
	int IsSg(Node* S) {  //判断是否是目标状态
		return memcmp(&S->Node, &Sg.Node, sizeof(int) * 9); 
	}
	int Nextnode(Node* S);                  // 下一个可行的节点
	//int Cantor(int Node[][3]);            // 康托展开
	void algorithm();                       // A算法
	void PrintPath(Node* head);             // 打印路径
	void FreeCLOSED(Node* CLOSED);          // 释放close表
private:
	//unsigned char allHash[362880];
	Node S0;                                //初始节点
	Node Sg;                                //目标节点
	int Nextnum;
	Node next[4];                           //扩展节点
};
