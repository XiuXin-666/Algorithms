#pragma once
#include "Node.h"
#include <iostream>

class A_algorithm {	//A*�㷨����
public:
	A_algorithm(Node* S0, Node* Sg);        //���캯��
	int IsSg(Node* S) {  //�ж��Ƿ���Ŀ��״̬
		return memcmp(&S->Node, &Sg.Node, sizeof(int) * 9); 
	}
	int Nextnode(Node* S);                  // ��һ�����еĽڵ�
	//int Cantor(int Node[][3]);            // ����չ��
	void algorithm();                       // A�㷨
	void PrintPath(Node* head);             // ��ӡ·��
	void FreeCLOSED(Node* CLOSED);          // �ͷ�close��
private:
	//unsigned char allHash[362880];
	Node S0;                                //��ʼ�ڵ�
	Node Sg;                                //Ŀ��ڵ�
	int Nextnum;
	Node next[4];                           //��չ�ڵ�
};
