#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode { // ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// �� �տ� ��� ����
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

// �� ���� ��带 ����
ListNode* remove_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
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
	return NULL; // Ž�� ����
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

int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;
	for (int i = 3; i >= 1; i--) {
		head1 = insert_first(head1, i * 10);
	}
	print_list(head1);
	for (int i = 6; i >= 4; i--) {
		head2 = insert_first(head2, i * 10);
	}
	print_list(head2);
	head3 = concat_list(head1, head2);
	print_list(head3);
	return 0;
}