#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode {
	int val;
	struct tagNode *next;
}note, *note_ptr;
void print_all(note_ptr head);
note_ptr swapPairs(note_ptr head);
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
	note_ptr head = create_list(1);
	print_all(head);
	print_all(swapPairs(head));
}
note_ptr swapPairs(note_ptr head) {
	if (head == NULL) return NULL;
	note_ptr p = head->next;
	if (p == NULL) return head;
	note_ptr tmp_prev, tmp_next;
	while( head && head->next ) {
		tmp_prev = head;
		head = head->next;
		tmp_next = head->next;
		head->next = tmp_prev;
		//handle tmp_prev node.
		if (tmp_next) {
			if (tmp_next->next) tmp_prev->next = tmp_next->next;
			else if(tmp_next->next == NULL) tmp_prev->next = tmp_next;
		}
		else if (tmp_next == NULL) tmp_prev->next = NULL;
		head = tmp_next;
	}
	return p;
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
