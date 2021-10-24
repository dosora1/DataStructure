/*
����ǥ��� -> ����ǥ���
- Array(����ü)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType *s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE)-1);
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

//ž���� ��
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1); //empty ������ ����Ʈ
	}
	else return s->stack[(s->top)--];
}

//ž���� ��
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else return s->stack[s->top];
}

//�켱����
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0; //����
	case '+': case '-': return 1;
	case '*': case '/': return 2; //����
	}
	return -1;
}

//���� ǥ�� -> ���� ǥ��
void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);

	StackType s;
	init(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/':
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
		}
	}
}