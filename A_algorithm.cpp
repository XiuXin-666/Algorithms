#include "A_algorithm.h"
#include "Node.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const Node& s1, const Node& s2) {  //sort函数的排序规则，返回估价函数值最大的节点
	int gx1 = 0, gx2 = 0;   //gx为从初始节点到该节点已经付出的代价
	int hx1 = 0, hx2 = 0;   //hx为该节点到达目的节点的接近程度估计值
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

int A_algorithm::Nextnode(Node* S) {//返回可扩展节点的个数
    Nextnum = 0;
    int posi, posj;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (S->Node[i][j] == 0) {
                posi = i; posj = j;//定位到S节点的空位置处
                break;
            }
    if (posi - 1 >= 0) {//向上扩展
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
    if (posi + 1 <= 2) {//向下扩展
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
    if (posj - 1 >= 0) {//向左扩展
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
    if (posj + 1 <= 2) {//向右扩展
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
    //memset(allHash, 0, 362880);//把allHash数组的值全部赋为‘0‘字符
    vector<Node> OPEN;//生成一个node类型的数组OPEN
    Node* CLOSED = new Node;;
    Node* current = CLOSED;
    Node* N;
    OPEN.push_back(S0);//把初始节点S0放入OPEN表
    while (!OPEN.empty()) {
        N = new Node;
        *N = OPEN[OPEN.size() - 1]; OPEN.pop_back();//移出OPEN表的最后一个节点
        step++;
        current->next = N;//把N放入CLOSED表中
        current = current->next;
        if (IsSg(N) == 0) {       //如果目标节点Sg=N，则搜索成功，结束
            PrintPath(N);       //打印出N
            //cout << step<<endl;
            FreeCLOSED(CLOSED); //释放CLOSED表
            return;
        }
        int Nextnum = Nextnode(N);//扩展N节点，并取N节点的可扩展节点数
        if (Nextnum == 0)//如果N不可扩展则继续
            continue;
        for (int i = 0; i < Nextnum; i++)
            /*
            for (int j = 0; j < OPEN.size();j++){
                if(IsEqual(OPEN[j], next[i])&&IsEqual(OPEN[j], *N->parent)){

                }
            }
            */
            OPEN.push_back(next[i]);
        sort(OPEN.begin(), OPEN.end(), cmp);//对OPEN表的节点按照估价函数的值进行从大到小排序，每次取估价函数值最小的节点即表中的最后一个节点
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
