#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode {
	int val;
	struct tagNode *next;
}note, *note_ptr;
void print_all(note_ptr head);
note_ptr removeNthFromEnd(note_ptr head, int n);
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
	note_ptr head = create_list(2);
	print_all(head);
	head = removeNthFromEnd(head, 1);
	print_all(head);
}
note_ptr removeNthFromEnd(note_ptr head, int n) {
	if (head==NULL) return NULL;
	note_ptr dummyHead = (note_ptr)malloc(sizeof(note));
	dummyHead->next =head;
	note_ptr first = dummyHead;	note_ptr second = dummyHead;
	while(n--) first = first->next;
	while(first && first->next) {
		first = first->next;
		second = second->next;
	}
	//delete the second node
	note_ptr p = second->next;
	second->next = second->next->next;
	free(p);
	head = dummyHead->next;
	free(dummyHead);
	return head;
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
