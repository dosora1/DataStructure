//infix to postfix code

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1
typedef char element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	else
		s->stack[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
		return s->stack[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
		return s->stack[s->top];
}

element eval(char exp[]) {

	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;

	StackType s;
	init(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = ch - '0';
			push(&s, value);
		}
		else
		{
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {

			case '+':
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
				break;
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				push(&s, op1 / op2);
				break;
			}
		}
	}
	return pop(&s);
}

int prec(char op) {

	switch (op) {

	case '(': case ')':
		return 0;
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	}
	return -1;
}

char* infix_to_postfix(char exp[]) {

	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	static char psf[100];
	int cnt = 0;

	StackType s;
	init(&s);


	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {

		case '+': case '-': case '*': case '/':
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
			{
				psf[cnt++] = pop(&s);
				//	printf("%c", psf[i]);
			}

			push(&s, ch);
			break;

		case '(':
			//psf[i] = ch;
			//push(&s, psf[i]);
			push(&s, ch);
			break;

		case ')':
			top_op = pop(&s);
			while (top_op != '(')
			{
				psf[cnt++] = top_op;
				//printf("%c", psf[i]);
				top_op = pop(&s);
			}
			break;

		default:
			psf[cnt++] = ch;
			//printf("%c", psf[i]);
			break;
		}
	}

	while (!is_empty(&s))
	{
		psf[cnt++] = pop(&s);
		//printf("%c", psf[i]);
		//i++;
	}

	psf[cnt] = '\0';
	//printf("\n");

	/*
	for(i=0; i<12; i++)
			printf("%c", psf[i]);

	printf("\n");
	*/

	return psf;
}

int main() {

	int result;
	char postfix[100];
	char infix[100];

	printf("input infix : ");
	scanf("%s", infix);

	//infix_to_postfix(infix);

	strcpy(postfix, infix_to_postfix(infix));

	printf("postfix : %s\n", postfix);

	result = eval(postfix);
	printf("result is %d\n", result);

	return 0;
}
