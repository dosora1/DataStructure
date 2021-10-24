#include <random>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int up;
	Node* Ulink;

	int down;
	Node* Dlink;

	int right;
	Node* Rlink;

	int left;
	Node* Llink;

} Node;

void Switch(Node* temp, int random, int *ts) {
	switch (random) { //������ �������� �ٲ�, temp ��� �ٲ�
		case(0):
			temp=temp->Ulink;
			*ts = temp->up;
			break;
		case(1):
			temp = temp->Dlink;
			*ts = temp->down;
			break;
		case(2):
			temp = temp->Rlink;
			*ts = temp->right;
			break;
		case(3):
			temp = temp->Llink;
			*ts = temp->left;
			break;
	}
}

int main() {
	Node node[50] = {
		{0,0,0,0,1,&node[37],0,0},           // node 1(���)
		{0,0,0,0,1,&node[31],0,0},           // node 2(���)
		{1,&node[44],0,0,0,0,0,0},           // node 3(���)
		{0,0,3,&node[9],0,0,0,0},            // node 4
		{0,0,3,&node[10],0,0,0,0},           // node 5
		{0,0,3,&node[11],0,0,0,0},
		{0,0,3,&node[12],0,0,0,0},
		{0,0,3,&node[13],0,0,0,0},
		{0,0,3,&node[14],0,0,0,0},
		{3,&node[3],3,&node[15],1,&node[10],0,0},        // node 10
		{3,&node[4],0,0,1,&node[11],1,&node[9]},
		{3,&node[5],1,&node[28],1,&node[12],1,&node[10]},
		{3,&node[6],1,&node[29],1,&node[13],1,&node[11]},
		{3,&node[7],0,0,1,&node[14],1,&node[12]},
		{3,&node[8],3,&node[20],0,0,1,&node[13]},        // node 15
		{3,&node[9],3,&node[21],1,&node[16],1,&node[30]},
		{1,&node[27],3,&node[22],1,&node[17],1,&node[15]},
		{1,&node[28],3,&node[23],1,&node[18],1,&node[16]},
		{1,&node[29],3,&node[24],1,&node[19],1,&node[17]},
		{0,0,3,&node[25],1,&node[20],1,&node[18]},       // node 20
		{3,&node[14],3,&node[26],0,0,1,&node[19]},
		{3,&node[15],0,0,0,0,0,0},
		{3,&node[16],0,0,0,0,0,0},
		{3,&node[17],0,0,0,0,0,0},
		{3,&node[18],0,0,0,0,0,0},           // node 25
		{3,&node[19],0,0,0,0,0,0},
		{3,&node[20],0,0,0,0,0,0},
		{0,0,1,&node[16],0,0,0,0},
		{1,&node[11],1,&node[17],0,0,0,0},
		{1,&node[12],1,&node[18],0,0,0,0},	// node 30
		{4,&node[31],0,0,1,&node[15],1,&node[44]},
		{1,&node[32],4,&node[30],0,0,2,&node[1]},
		{1,&node[33],1,&node[31],0,0,3,&node[46]},
		{0,0,1,&node[32],0,0,3,&node[45]},
		{0,0,0,0,3,&node[36],0,0},		// node 35
		{0,0,3,&node[38],0,0,0,0},
		{1,&node[47],1,&node[37],0,0,3,&node[34]},
		{1,&node[36],0,0,1,&node[38],1,&node[0]},
		{3,&node[35],0,0,0,0,1,&node[37]},
		{0,0,3,&node[43],1,&node[44],1,&node[40]},	// node 40
		{0,0,1,&node[41],1,&node[39],1,&node[48]},
		{1,&node[40],0,0,0,0,0,0},
		{3,&node[48],0,0,0,0,0,0},
		{3,&node[39],0,0,0,0,0,0},
		{0,0,1,&node[2],1,&node[30],1,&node[39]},	// node 45
		{0,0,0,0,3,&node[33],0,0},
		{0,0,0,0,3,&node[32],0,0},
		{0,0,1,&node[36],0,0,0,0},
		{0,0,3,&node[42],1,&node[40],1,&node[49]},
		{0,0,0,0,1,&node[48],0,0}		// node 50
	};
	int unknow = 0; //��θ� �� ����� ���� ����
	Node* temp = &node[7]; //�ʱ� ���� 8��
	int ts = 0;

	//��θ� �� ���
	while(temp!=&node[0]|| temp != &node[1] || temp != &node[2]){ //��󱸿� �����ϸ� ����
		int random = rand() % 4; //������ �������� ����
		Switch(temp, random, &ts);
		if (!ts) { //������ �ε����� ���ھ 0�� �ƴ� ��� ��θ� Ž��.
			unknow += ts;
		}
	}
	printf("Total score : %d\n",ts);
	return 0;
}