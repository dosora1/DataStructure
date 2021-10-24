/*
������ ���������� ����(0)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//���� ���� ���� �Լ�
int is_empty() {
	return (top == -1); //��� ������ ������������ ������ �״����
}

//��ȭ ���� ���� �Լ�
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

//���� �Լ�
void push(element item) {
	if (is_full()) { //������ �������� ����
		fprintf(stderr, "Stack is full\n");
		return;
	}
	else {
		stack[++top] = item; //ž �ε��� ����, ������ �ֱ�
	}
}

//���� �Լ�
element pop() {
	if (is_empty()) { //��� ������ ����
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return stack[top--]; //���� ���밡�� �ڸ���
	}
}

//��ũ �Լ�
element peek() {
	if (is_empty()) { //��� ������ ����
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return stack[top];
	}
}

void main() {
	push(1);//stack�� 1�߰�
	push(2);//stack�� 2�߰�
	push(3);//stack�� 3�߰�

	printf("%d\n",pop()); //���ÿ��� 1����
	printf("%d\n",pop()); //���ÿ��� 2����
	printf("%d\n", pop()); //���ÿ��� 3����

	printf("%d\n", is_empty()); //��� �ִ��� Ȯ��
}