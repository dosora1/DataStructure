/*
원형 큐(0)
한 칸은 비워두기
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6
typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//초기화
void init(QueueType* q) {
	q->front = q->rear = 0;
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) q->queue[i] = 0;
}

//비었는가, 프론트 레어 같으면 비었음
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//차있는가, 프론트 레어가 하나 차이남(mod% 연산)
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//큐에 아이템 삽입
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		printf("큐는 포화상태\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

//큐 아이템 삭제
void dequeue(QueueType* q) {
	if (is_empty(q)) { //공백 상태면 에러
		printf("큐가 공백상태\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	q->queue[q->front] = 0;
}

//큐 출력
element display(QueueType *q){
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		printf("%d ", q->queue[i]);
	}
}

void main() {
	QueueType q;
	
	//15p process1
	init(&q);
	display(&q);
	printf("\n");
	//process2
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	display(&q);
	printf("\n");

	//process3
	enqueue(&q, 4);
	enqueue(&q, 5);
	display(&q);
	printf("\n");

	//process4
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	display(&q);
	printf("\n");

	//process5
	enqueue(&q, 6);
	display(&q);
	printf("\n");

	//process6
	enqueue(&q, 7);
	enqueue(&q, 8);
	enqueue(&q, 9);
	display(&q);
	printf("\n");

}