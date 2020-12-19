#pragma once
class Node { //节点类
public:
	int Node[3][3];         //每个节点用一个二维数组表示
	class Node* parent;     //节点的先辈节点
	class Node* next;       //节点的扩展节点
};


