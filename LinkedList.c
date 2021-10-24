/*
연결리스트
*/

#include <stdio.h>

typedef int element;
typedef int ListNode{
	element data;
	struct ListNode* link;
}ListNode;

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	if (*phead == NULL) { // 공백리스트일 경우
		new_node->link = NULL;
		*phead = new_node;
	}
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

//반복으로 display
void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

//재귀로 display
void dispaly_recur(ListNode* head) {
	ListNode* p = head;
	if (p != NULL) {
		printf("%d->", p->data);
		display_recur(p->link);
	}
}

ListNode *search(ListNode* head, int x) {
	ListNode *p;
	p = head;
	while (p != NULL) {
		if (p->data == x) return p; // search CLEAR
		p = p->link; // 링크를 타고 Move NEXT
	}
	return p; // 탐색 실패일 경우 NULL 반환
}

ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL) { //링크를 타고 오른쪽으로 움직임, 끝이면 탈출
			p = p->link;
		}
		p->link = head2; //head1과 head2 연결
		return head1;
	}
}

ListNode* reverse(ListNode* head) {
	ListNode* p, *q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

void main() {

}