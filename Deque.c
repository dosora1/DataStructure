/*
�� ����(0)
-���
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;

//���
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

//�� ��ü�� ������
typedef struct DequeType {
	DlistNode* head;
	DlistNode* tail;
}DequeType;

//����
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ
void init(DequeType* dq) {
	dq->head = dq->tail = NULL;
}

//��� ����
DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) {
	DlistNode* new_node = (DlistNode*)malloc(sizeof(DlistNode));
	if (new_node == NULL) { //�Ҵ��� ����� �� ������
		error("Memory allocation error");
	}
	new_node->llink = llink;
	new_node->data = item;
	new_node->rlink = rlink;

	return new_node;
}

//���� ����°�
int is_empty(DequeType* dq) {
	if (dq->head == NULL)
		return 1;
	else
		return 0;
}

//�ڿ��� �߰�
void add_rear(DequeType* dq, element item) {
	DlistNode* new_node = create_node(dq->tail, item, NULL); //������ ������ ����(�쿬��), ������, ������� rlink

	if (is_empty(dq)) //���� ���� �������
		dq->head = new_node; //����尡 ��尡 ��
	else //���� ���� �ִٸ�
		dq->tail->rlink = new_node; //���� ���� ������ rlink�� ������ �̾���
	dq->tail = new_node; //������ ������ ������ �ٲ�
}

//���߰�
void add_front(DequeType* dq, element item) {
	DlistNode* new_node = create_node(NULL, item, dq->head); //���ʿ��� ù��°

	if (is_empty(dq))
		dq->tail = new_node;
	else
		dq->head->llink = new_node;
	dq->head = new_node;
}

//������
element delete_front(DequeType* dq) {
	element item;
	DlistNode* removed_node;

	if (is_empty(dq))
		error("Deque is empty");
	else {
		removed_node = dq->head; //���� ��� ����
		item = removed_node->data; //���� �� ����
		dq->head = dq->head->rlink; //��尡 ����Ű�� �� �̵�
		free(removed_node); //�޸�����
		if (dq->head == NULL) //
			dq->tail = NULL;
		else
			dq->head->llink = NULL;
	}
	return item;
}

element delete_rear(DequeType* dq) {
	element item;
	DlistNode* removed_node;

	if (is_empty(dq)) //�������
		printf("Deque is empty\n");
	else { //��������
		removed_node = dq->tail;
		item = removed_node->data; //������ ���, ������ �� ����
		dq->tail = dq->tail->llink; //������Ʈ
		free(removed_node); //����

		if (dq->tail == NULL) //���� ��尡 ���̸�(������ �����)
			dq->head = NULL; //��嵵 ��
		else //������ ������ ����Ű�� ������
			dq->tail->rlink = NULL; //���� ����� rlink�� ��
	}
	return item;
}

//���
void display(DequeType* dq) {
	DlistNode* p;
	printf("( ");
	for (p = dq->head; p != NULL; p = p->rlink) //rlink�� ����
		printf("%d ", p->data);
	printf(")\n");
}

void main() {
	DequeType deque;
	init(&deque);

	add_front(&deque, 10);
	add_front(&deque, 20);
	add_rear(&deque, 30);
	display(&deque);

	printf("%d\n", delete_front(&deque));
	printf("%d\n", delete_rear(&deque));

	display(&deque);
}