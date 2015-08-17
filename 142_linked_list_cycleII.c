#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct tagNode {
	int val;
	struct tagNode *next;
}Node, *NodePtr;
void print_all(NodePtr head);
NodePtr create_list(int i, int n) {
	NodePtr head, tail, p;
	head=tail=(NodePtr)malloc(sizeof(Node));
	for( i ; i <=n; i++ ) {
		tail->next = (NodePtr)malloc(sizeof(Node));
		tail = tail->next;
		tail->val = i;
	}
	tail->next = NULL;
	p = head;
	head = head->next;
	free(p);
	return head;
}
NodePtr reverse(NodePtr head) {
	NodePtr p = NULL, r;
	while (head) {
		r = head->next;
		head->next = p;
		p = head;
		head = r;	
	}	
	return p;
}
NodePtr concat(NodePtr l1, NodePtr l2) {
	NodePtr backup = l1;
	while(l1->next) l1 = l1->next;
	l1->next = l2;
	return backup;
}
NodePtr deleteDuplicates(NodePtr head) {
//	typedef struct ListNode* NodePtr;
	NodePtr curr = head;
	while(curr) {
		NodePtr tmp = curr->next;
		if(tmp && tmp->val == curr->val) {
			NodePtr p = tmp;
			tmp = tmp->next;
			free(p);
			curr->next = tmp;
			continue;
		}
		curr = curr->next;
	}
	return head;
}
void main() {
	NodePtr l1 = create_list(1,1);
	NodePtr l2 = create_list(1,1);
	NodePtr l3 = create_list(1,5);
	l1 = concat(l1,l2);
	l1 = concat(l1,l3);
	print_all(l1);
	puts("-----------------------------");
    print_all(deleteDuplicates(l1));
}
void print_all(NodePtr head) {
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
