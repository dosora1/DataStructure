/*
����ü�� �̿��� ���� ����(0)
- ����ü�� �ϳ�.
- �迭 ũ�� ����(101)
*/

//���� ���
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;

//����ü ����
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

//���� �ʱ�ȭ
void init(StackType* s) {
	s->top = -1;
}

//����°�
int is_empty(StackType* s) {
	return (s->top == -1);
}

//���ִ°�
int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

//�߰� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else {
		s->stack[++(s->top)] = item;
	}
}

//���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) { //��������� ����
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->stack[(s->top)--]; //�����ϰ� �Ա� �ڸ���
	}
}

//��ũ �Լ�
element peek(StackType* s) {
	if (is_empty(s)) { //��� ������ ����
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		return s->stack[s->top];
	}
}

int main() {
	StackType s;

	init(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));

	return 0;
}
