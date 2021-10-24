/*
스택을 전역변수로 선언(0)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//공백 상태 검출 함수
int is_empty() {
	return (top == -1); //비어 있으면 전역변수에서 선언한 그대로임
}

//포화 상태 검출 함수
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(element item) {
	if (is_full()) { //스택이 차있으면 에러
		fprintf(stderr, "Stack is full\n");
		return;
	}
	else {
		stack[++top] = item; //탑 인덱스 증가, 아이템 넣기
	}
}

//삭제 함수
element pop() {
	if (is_empty()) { //비어 있으면 에러
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return stack[top--]; //스택 윗대가리 자르기
	}
}

//피크 함수
element peek() {
	if (is_empty()) { //비어 있으면 에러
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return stack[top];
	}
}

void main() {
	push(1);//stack에 1추가
	push(2);//stack에 2추가
	push(3);//stack에 3추가

	printf("%d\n",pop()); //스택에서 1삭제
	printf("%d\n",pop()); //스택에서 2삭제
	printf("%d\n", pop()); //스택에서 3삭제

	printf("%d\n", is_empty()); //비어 있는지 확인
}