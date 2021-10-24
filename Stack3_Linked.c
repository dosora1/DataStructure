/*
연결 스택(0)
구조체 2개 이용
++is_empty() 괄호 꼭 붙일 것
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

//노드
typedef struct StackNode {
	element item;
	struct StackNode* link;
}StackNode;

//스택 포인터
typedef struct {
	StackNode* top;
}LinkedStackType;

//초기화
void init(LinkedStackType *s) {
	s->top = NULL;
}

//공백 상태 검출
int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

//포화 상태 검출(필요x)
int is_full(LinkedStackType* s) {
	return 0;
}

//삽입
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) { //할당이 제대로 안 됐다면 에러
		fprintf(stderr, "Memory allocation error\n");
		return;
	}
	else
		temp->item = item;//temp에 입력받은 item 저장
		temp->link = s->top;//temp의 link는, 이전 최상단 StackNode의 주소 저장
		s->top=temp;//최상단 StackNode를 temp로 지정
}

//삭제
element pop(LinkedStackType* s) {
	if (is_empty(s)) { //스택이 비어있다면
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		//element popitem 선언, 최상단 StackNode의 아이템 저장
		element popitem;
		popitem = temp->item;
		//최상단 StackNode를 현재 top의 이전 StackNode로 지정
		s->top = s->top->link;
		free(temp);
		return popitem;
	}
}

//피크
element peek(LinkedStackType* s) {
	if (is_empty(s)) { //비어있다면 에러
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

//메인
void main() {
	LinkedStackType s;

	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
}