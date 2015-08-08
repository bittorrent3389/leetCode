#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode {
	int val;
	struct tagNode *next;
}note, *note_ptr;
void print_all(note_ptr head);
note_ptr addTwoNumbers(note_ptr l1, note_ptr l2);
note_ptr create_list(int n) {
	note_ptr head, tail, p;
	int i;
	head=tail=(note_ptr)malloc(sizeof(note));
	for( i = 1; i <=n; i++ ) {
		tail->next = (note_ptr)malloc(sizeof(note));
		tail = tail->next;
		tail->val = i;
	}
	tail->next = NULL;
	p = head;
	head = head->next;
	free(p);
	return head;
}
void main() {
	note_ptr l1 = create_list(10);
	note_ptr l2 = create_list(10);
	print_all(l1);
	print_all(l2);
	note_ptr head = addTwoNumbers(l1, l2);
	puts("-----------------------------");
	print_all(head);
}
note_ptr addTwoNumbers(note_ptr l1, note_ptr l2) {
	int carry = 0;
	note_ptr head = (note_ptr)malloc(sizeof(note));
	note_ptr dummy = head;
	while (l1 || l2 || carry) {
		if(l1) {
			carry += l1->val;
			l1 = l1->next;
		}
		if(l2) {
			carry += l2->val;
			l2 = l2->next;
		}
		head->next = (note_ptr)malloc(sizeof(note));
		head->next->val = carry%10;
		head->next->next = NULL;
		head = head->next;
		carry /= 10;
	}
	return dummy->next;
}
void print_all(note_ptr head) {
	while(head) {
		if (!head->next) {
			printf("%d", head->val);
			break;
		}
		printf("%d->", head->val);
		head = head->next;
	}
	puts("");
}
