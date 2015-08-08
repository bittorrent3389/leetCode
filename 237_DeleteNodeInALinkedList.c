#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
	int val;
	struct ListNode *next;
} item, *item_ptr;
void delete_node(item_ptr node) {
	if( node == NULL ) return;
	if (node->next) {
		node->val   = node->next->val;
		item_ptr p = node->next;
		node->next  = node->next->next;
		free(p);
	} else {
		//item_ptr p = node;
		node = NULL;
		//free(p);
	}	
}
void free_all(item* head) {
	item* p;
	while (head){
		p = head;
		head = head->next;
		free(p);
	}
	puts("free_all is done.");
}
void print_all(item_ptr head) {
	while (head) {
		printf("%d ", head->val );
		head = head->next;
	}
	puts("\nprint_all is done.");
}
//node is the alias of struct ListNode.
item_ptr create_list(int a, int b);
void main(void) {
	item_ptr head=create_list(1,5);
	item_ptr p = head;
	int n = 4;
	print_all(head);
	while(n--) p=p->next;
	delete_node(p);
	print_all(head);
	free_all(head);	
}
item_ptr create_list(int i, int n ) {
	item_ptr head, tail, p;
	head=tail=(item_ptr)malloc(sizeof(item));
	for(;i<=n;i++) {
		tail->next = (item_ptr)malloc((sizeof(item)));
		tail = tail->next;
		tail->val = i;
	}
	tail->next = NULL;
	p = head;
	head = head->next;
	free(p);
	return head;
}
