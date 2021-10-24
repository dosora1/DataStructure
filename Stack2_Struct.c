/*
구조체를 이용한 스택 구현(0)
- 구조체가 하나.
- 배열 크기 지정(101)
*/

//공통 헤더
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;

//구조체 선언
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기화
void init(StackType* s) {
	s->top = -1;
}

//비었는가
int is_empty(StackType* s) {
	return (s->top == -1);
}

//차있는가
int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

//추가 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->stack[++(s->top)] = item;
	}
}

//삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) { //비어있으면 에러
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->stack[(s->top)--]; //리턴하고 입구 자르기
	}
}

//피크 함수
element peek(StackType* s) {
	if (is_empty(s)) { //비어 있으면 에러
		fprintf(stderr, "스택 공백 에러\n");
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
