#include "A_algorithm.h"
#include "Node.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const Node& s1, const Node& s2) {  //sort������������򣬷��ع��ۺ���ֵ���Ľڵ�
	int gx1 = 0, gx2 = 0;   //gxΪ�ӳ�ʼ�ڵ㵽�ýڵ��Ѿ������Ĵ���
	int hx1 = 0, hx2 = 0;   //hxΪ�ýڵ㵽��Ŀ�Ľڵ�Ľӽ��̶ȹ���ֵ
	const Node* ptr1 = &s1;
	const Node* ptr2 = &s2;
	int Node[3][3] = { {1,2,3},{8,0,4},{7,6,5} };
	while (ptr1 != NULL) {
		gx1 += 1;
		ptr1 = ptr1->parent;
	}
	while (ptr2 != NULL) {
		gx2 += 1;
		ptr2 = ptr2->parent;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (s1.Node[i][j] != Node[i][j]) {
				hx1 += 1;
			}
			if (s2.Node[i][j] != Node[i][j]) {
				hx2 += 1;
			}
		}
	}
	return (gx1 + hx1) > (gx2 + hx2);
}

bool IsEqual(Node n1, Node n2) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (n1.Node[i][j] != n2.Node[i][j])
				return false;
	return true;
}

A_algorithm::A_algorithm(Node* S0, Node* Sg) {
    memcpy(&this->S0.Node, &S0->Node, sizeof(int) * 9);
    this->S0.parent = NULL;
    this->S0.next = NULL;
    memcpy(&this->Sg.Node, &Sg->Node, sizeof(int) * 9);
    this->Sg.parent = NULL;
    this->Sg.next = NULL;
}

int A_algorithm::Nextnode(Node* S) {//���ؿ���չ�ڵ�ĸ���
    Nextnum = 0;
    int posi, posj;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (S->Node[i][j] == 0) {
                posi = i; posj = j;//��λ��S�ڵ�Ŀ�λ�ô�
                break;
            }
    if (posi - 1 >= 0) {//������չ
        Node up = *S;
        up.Node[posi][posj] = up.Node[posi - 1][posj];
        up.Node[posi - 1][posj] = 0;
        next[Nextnum] = up;
        next[Nextnum].parent = S;
        Nextnum++;
        /*
        if(allHash[Cantor(up.Node)] == 0){
            next[Nextnum] = up;
            next[Nextnum].parent = S;
            Nextnum++;
        }
        */
    }
    if (posi + 1 <= 2) {//������չ
        Node down = *S;
        down.Node[posi][posj] = down.Node[posi + 1][posj];
        down.Node[posi + 1][posj] = 0;
        next[Nextnum] = down;
        next[Nextnum].parent = S;
        Nextnum++;
        /*
        if(allHash[Cantor(down.Node)] == 0){
            next[Nextnum] = down;
            next[Nextnum].parent = S;
            Nextnum++;
        }
        */
    }
    if (posj - 1 >= 0) {//������չ
        Node left = *S;
        left.Node[posi][posj] = left.Node[posi][posj - 1];
        left.Node[posi][posj - 1] = 0;
        next[Nextnum] = left;
        next[Nextnum].parent = S;
        Nextnum++;
        /*
        if(allHash[Cantor(left.Node)] == 0){
            next[Nextnum] = left;
            next[Nextnum].parent = S;
            Nextnum++;
        }
        */
    }
    if (posj + 1 <= 2) {//������չ
        Node right = *S;
        right.Node[posi][posj] = right.Node[posi][posj + 1];
        right.Node[posi][posj + 1] = 0;
        next[Nextnum] = right;
        next[Nextnum].parent = S;
        Nextnum++;
        /*
        if(allHash[Cantor(right.Node)] == 0){
            next[Nextnum] = right;
            next[Nextnum].parent = S;
            Nextnum++;
        }
        */
    }
    return Nextnum;
}

/*
int A_algorithm::Cantor(int Node[][3]){
    int fac[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    int index = 0;
    for(int i = 7; i >= 0; i--){
        int irow = i / 3, icol = i - i / 3 * 3;
        int count = 0;
        for(int j = 8; j > i; j--){
            int jrow = j / 3, jcol = j - j / 3 * 3;
            if(Node[jrow][jcol] < Node[irow][icol]){
                count++;
            }
        }
        index += (count*fac[8-i]);
    }
    return index;
}
*/

void A_algorithm::algorithm() {
    int step = 0;
    //memset(allHash, 0, 362880);//��allHash�����ֵȫ����Ϊ��0���ַ�
    vector<Node> OPEN;//����һ��node���͵�����OPEN
    Node* CLOSED = new Node;;
    Node* current = CLOSED;
    Node* N;
    OPEN.push_back(S0);//�ѳ�ʼ�ڵ�S0����OPEN��
    while (!OPEN.empty()) {
        N = new Node;
        *N = OPEN[OPEN.size() - 1]; OPEN.pop_back();//�Ƴ�OPEN������һ���ڵ�
        step++;
        current->next = N;//��N����CLOSED����
        current = current->next;
        if (IsSg(N) == 0) {       //���Ŀ��ڵ�Sg=N���������ɹ�������
            PrintPath(N);       //��ӡ��N
            //cout << step<<endl;
            FreeCLOSED(CLOSED); //�ͷ�CLOSED��
            return;
        }
        int Nextnum = Nextnode(N);//��չN�ڵ㣬��ȡN�ڵ�Ŀ���չ�ڵ���
        if (Nextnum == 0)//���N������չ�����
            continue;
        for (int i = 0; i < Nextnum; i++)
            /*
            for (int j = 0; j < OPEN.size();j++){
                if(IsEqual(OPEN[j], next[i])&&IsEqual(OPEN[j], *N->parent)){

                }
            }
            */
            OPEN.push_back(next[i]);
        sort(OPEN.begin(), OPEN.end(), cmp);//��OPEN��Ľڵ㰴�չ��ۺ�����ֵ���дӴ�С����ÿ��ȡ���ۺ���ֵ��С�Ľڵ㼴���е����һ���ڵ�
        //
        //cout << step << " OPEN TABLE:" << endl;
        //for (int i = 0; i < OPEN.size();i++)
        //    PrintPath(&OPEN[i]);
        //
    }
    cout << "Failed." << endl;
    FreeCLOSED(CLOSED);
    return;
}

void A_algorithm::PrintPath(Node* head) {
    if (head == NULL) {
        return;
    }
    else {
        PrintPath(head->parent);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (head->Node[i][j] == 0)
                    cout << "  ";
                else
                    cout << head->Node[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void A_algorithm::FreeCLOSED(Node* CLOSED) {
    Node* current;
    while (CLOSED != NULL) {
        current = CLOSED->next;
        free(CLOSED);
        CLOSED = current;
    }
}
