#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct tagNode {
	int val;
	struct tagNode *next;
}note, *note_ptr;
void print_all(note_ptr head);
bool isPalindrome(note_ptr head);
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
note_ptr reverse(note_ptr head) {
	note_ptr p = NULL, r;
	while (head) {
		r = head->next;
		head->next = p;
		p = head;
		head = r;	
	}	
	return p;
}
note_ptr concat(note_ptr l1, note_ptr l2) {
	note_ptr backup = l1;
	while(l1->next) l1 = l1->next;
	l1->next = l2;
	return backup;
}
void main() {
	note_ptr l1 = create_list(6);
	note_ptr l2 = reverse(create_list(6));
	l1 = concat(l1,l2);
	print_all(l1);
	puts("-----------------------------");
	printf("yes or no? %d\n", isPalindrome(l1));
	
}
bool isPalindrome(note_ptr head) {
	note_ptr tail=head;
	note_ptr slow = head;
	note_ptr fast = head;
	while(fast&&fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
 	tail = reverse(slow);
	print_all(tail);
	while(head != slow){
		if (head->val != tail->val) return false;
		head = head->next;
		tail = tail->next;
	}
	return true;

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
