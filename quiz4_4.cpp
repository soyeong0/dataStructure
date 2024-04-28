#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode { // 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// 맨 앞에 노드 삽입
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

// 맨 앞의 노드를 삭제
ListNode* remove_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* remove(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;
	/*while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}*/
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == x) return p;
	}
	return NULL; // 탐색 실패
}

ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head2;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode* reverse(ListNode* head) {
	// 순회 포인터로 p, q, r을 사용
	ListNode* p, * q, * r;

	p = head;         // p는 역순으로 만들 리스트
	q = NULL;        // q는 역순으로 만들 노드
	while (p != NULL) {
		r = q;          // r은 역순으로 된 리스트.
		// r은 q, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;
		q->link = r;      // q의 링크 방향을 바꾼다.
	}
	return q;
}

int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	for (int i = 4; i >= 1; i--) {
		head1 = insert_first(head1, i * 10);
	}
	print_list(head1);
	head2 = reverse(head1);
	print_list(head2);
	return 0;
}