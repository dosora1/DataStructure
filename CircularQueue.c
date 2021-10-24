/*
���� ť(0)
�� ĭ�� ����α�
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6
typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//�ʱ�ȭ
void init(QueueType* q) {
	q->front = q->rear = 0;
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) q->queue[i] = 0;
}

//����°�, ����Ʈ ���� ������ �����
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//���ִ°�, ����Ʈ ��� �ϳ� ���̳�(mod% ����)
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//ť�� ������ ����
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		printf("ť�� ��ȭ����\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

//ť ������ ����
void dequeue(QueueType* q) {
	if (is_empty(q)) { //���� ���¸� ����
		printf("ť�� �������\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	q->queue[q->front] = 0;
}

//ť ���
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