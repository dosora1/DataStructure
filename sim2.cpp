#include <random>
#include <stdio.h>
#include <stdlib.h>
typedef int NodeNum;

typedef struct Node{
	double Ls;
	double Rs;
	NodeNum next;
	NodeNum next2;
}Node;

typedef struct Eff {
	double good;
	double bad;
}Eff;

int main() {
	Node node[] = {
		{0,0,-1}, //1
		{0,0,-1}, //2
		{0,0,-1}, //3 ���

		{3,0,10}, //4
		{3,0,11}, //5
		{3,0,12}, //6
		{3,0,13}, //7
		{3,0,14}, //8
		{3,0,15}, //9
		{3,13,16}, //10
		{4,12,16}, //11
		{5,11,16}, //12
		{6,10,16}, //13
		{7,9,16}, //14
		{8,8,16}, //15
		{2,0,3}, //16
		{1,15,16}, //17
		{2,14,16}, //18
		{3,13,16}, //19
		{4,12,16}, //20
		{5,11,16}, //21

		{3,0,16}, //22
		{3,0,17}, //23
		{3,0,18}, //24
		{3,0,19}, //25
		{3,0,20}, //26
		{3,0,21}, //27

		{1,0,17}, //28
		{3,15,16}, //29
		{3,14,16}, //30
		{1,0,3}, //31
		{1,0,2}, //32
		{1,0,32}, //33
		{1,0,33}, //34

		{3,0,37}, //35
		{3,0,39}, //36
		{1,0,38}, //37
		{1,0,1}, //38
		{1,0,38}, //39
		{2,0,45}, //40
		{2,0,38}, //41
		{1,0,41},//42
		{3,0,49},//43
		{3,0,40},//44
		{1,0,3}, //45
		{4,0,32}, //46
		{3,0,32}, //47
		{1,0,37}, //48
		{1,0,41}, //49
};
	NodeNum next = 0;
	int Room[] = { 35,36,48,43,42,44,46,47,4,5,6,7,8,9,28,29,30,22,23,24,25,26,27 };
	int RoomCnt = sizeof(Room) / sizeof(int);
	Eff eff[sizeof(Room) / sizeof(int)] = { 0 };
	double EffSum=0;

	for (int i = 0; i < sizeof(Room)/sizeof(int); i++) { //�� �渶�� ����
		Node* temp = &node[Room[i]-1];
		while (temp->next != -1) {
			//������ ȿ���� ����ü�� ����
			if (temp->Ls == 0 || temp->Rs == 0) { //�� �� �ϳ��� 0�̸�(��ΰ� �ϳ��̸�)
				eff[i].good += temp->Ls;
				eff[i].bad += temp->Ls;
				printf("good = %.0lf\n", eff[i].good);
				printf("bad = %.0lf\n", eff[i].bad);
			}
			else if (temp->Ls > temp->Rs) { //Ls�� Rs���� ũ��
				eff[i].good += temp->Rs; //good�� Rs�� ����
				eff[i].bad += temp->Ls; //bad�� Ls�� ����

				printf("good = %.0lf\n", eff[i].good);
				printf("bad = %.0lf\n", eff[i].bad);
			}
			else { //Ls�� Rs���� ������
				eff[i].good += temp->Ls;
				eff[i].bad += temp->Rs;
				printf("good = %.0lf\n", eff[i].good);
				printf("bad = %.0lf\n", eff[i].bad);
			}
			temp = &node[(temp->next) - 1]; //temp����
		}
		printf("�� ��ȣ : %d\n", Room[i]);
		printf("���� ��� Ž���� �ð� ��� : %.0lf\n", eff[i].good);
		printf("�ִ� ��� Ž���� �ð� ��� : %.0lf\n", eff[i].bad);
		printf("Efficiency : %.2lf �� ���� Ż��\n\n", (eff[i].bad) / (eff[i].good));
		EffSum += (eff[i].bad) / (eff[i].good); //ȿ�� ����� ���ϱ� ���� �� ������
	}
	printf("��� ȿ�� : %.2lf\n", EffSum / RoomCnt);
	return 0;
}