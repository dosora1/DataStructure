/*
덱 구현(0)
-출력
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;

//노드
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

//덱 전체를 봤을때
typedef struct DequeType {
	DlistNode* head;
	DlistNode* tail;
}DequeType;

//에러
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화
void init(DequeType* dq) {
	dq->head = dq->tail = NULL;
}

//노드 생성
DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) {
	DlistNode* new_node = (DlistNode*)malloc(sizeof(DlistNode));
	if (new_node == NULL) { //할당이 제대로 안 됐으면
		error("Memory allocation error");
	}
	new_node->llink = llink;
	new_node->data = item;
	new_node->rlink = rlink;

	return new_node;
}

//덱이 비었는가
int is_empty(DequeType* dq) {
	if (dq->head == NULL)
		return 1;
	else
		return 0;
}

//뒤에서 추가
void add_rear(DequeType* dq, element item) {
	DlistNode* new_node = create_node(dq->tail, item, NULL); //기존의 꼬리와 연결(우연결), 아이템, 뉴노드의 rlink

	if (is_empty(dq)) //기존 덱이 비었으면
		dq->head = new_node; //뉴노드가 헤드가 됨
	else //기존 덱이 있다면
		dq->tail->rlink = new_node; //기존 덱의 테일의 rlink가 뉴노드와 이어짐
	dq->tail = new_node; //기존의 테일은 뉴노드로 바뀜
}

//왼추가
void add_front(DequeType* dq, element item) {
	DlistNode* new_node = create_node(NULL, item, dq->head); //왼쪽에서 첫번째

	if (is_empty(dq))
		dq->tail = new_node;
	else
		dq->head->llink = new_node;
	dq->head = new_node;
}

//왼제거
element delete_front(DequeType* dq) {
	element item;
	DlistNode* removed_node;

	if (is_empty(dq))
		error("Deque is empty");
	else {
		removed_node = dq->head; //지울 노드 저장
		item = removed_node->data; //지울 값 저장
		dq->head = dq->head->rlink; //헤드가 가리키는 곳 이동
		free(removed_node); //메모리해제
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

	if (is_empty(dq)) //비었으면
		printf("Deque is empty\n");
	else { //차있으면
		removed_node = dq->tail;
		item = removed_node->data; //삭제할 노드, 데이터 각 저장
		dq->tail = dq->tail->llink; //업데이트
		free(removed_node); //해제

		if (dq->tail == NULL) //테일 노드가 널이면(마지막 노드라면)
			dq->head = NULL; //헤드도 널
		else //테일이 뭔가를 가리키고 있으면
			dq->tail->rlink = NULL; //테일 노드의 rlink도 널
	}
	return item;
}

//출력
void display(DequeType* dq) {
	DlistNode* p;
	printf("( ");
	for (p = dq->head; p != NULL; p = p->rlink) //rlink를 따라감
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