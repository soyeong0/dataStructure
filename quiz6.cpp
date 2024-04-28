#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType * s) {
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType * s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� overflow\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// ���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� underflow\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main() {
	int infinity = 987654321;
	int problem_num = 0;
	scanf_s("%d", &problem_num); // �׽�Ʈ ���̽� ���� �Է¹ޱ�
	for (int problem = 0; problem < problem_num; problem++) {
		int query_num = 0;
		scanf_s("%d", &query_num); // ������ ���� �Է¹ޱ�
		StackType min_stack; //�ּҰ��� �ִ� ����
		StackType max_stack; //�ִ밪�� �ִ� ����
		init_stack(&min_stack);
		init_stack(&max_stack);
		push(&min_stack, infinity);
		push(&max_stack, -infinity);

		for (int query = 0; query < query_num; query++) {
			int input1, input2, new_block = 0;
			scanf_s("%d", &input1);
			switch (input1) {
			case 1:
				scanf_s("%d", &input2);
				new_block = input2;

				// �ּҰ� ������ �� ���� ���� ���ؼ�, �� ��ϰ�, ������ �� �� �� ���� ���� ����
				if (min_stack.data[min_stack.top] > new_block)
					push(&min_stack, new_block);
				else
					push(&min_stack, min_stack.data[min_stack.top]);

				// �ִ밪 ������ �� ���� ���� ���ؼ�, �� ��ϰ�, ������ �� �� �� ū ���� ����
				if (max_stack.data[max_stack.top] < new_block)
					push(&max_stack, new_block);
				else
					push(&max_stack, max_stack.data[max_stack.top]);
				printf("%d %d\n", min_stack.data[min_stack.top], max_stack.data[max_stack.top]);
				break;

			case 2:
				//�ּҰ� ����, �ִ밪 ������ �� ���� ���� ����
				if (min_stack.top != infinity)
					pop(&min_stack);
				if (max_stack.top != -infinity)
					pop(&max_stack);
				break;
			}
		}
	}
	return 0;
}