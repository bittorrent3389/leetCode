#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
	int val;
	struct Node *next;
}Node, *NodePtr;
void print_all(NodePtr head);
NodePtr append(NodePtr head, int new_val) {
	NodePtr tail, ret;
	if( (tail=(NodePtr)malloc(sizeof(Node))) == NULL) {
		fprintf(stderr, "Memory Allocation error. \n");
	}
	if(head == NULL) ret = tail;
	else {
		ret = head;
		while(head->next) head = head->next;
		head->next = tail;
	}
	tail->val = new_val;
	tail->next = NULL;
	return ret;
}
NodePtr swap(NodePtr curr, NodePtr q) {
	NodePtr tmp = q->next;
	q->next = curr;
	curr->next = tmp;
	return q;
}
void bubbleSort(NodePtr head) {
	bool flag = true;
	NodePtr dummyHead = (NodePtr)malloc(sizeof(Node));
	dummyHead->next = head;
	while(flag) {
		flag = false;
		NodePtr curr = dummyHead->next;
		NodePtr prev = dummyHead;
		while(curr->next){
			if(curr->val > curr->next->val) {
				flag = true;
				prev->next = curr = swap(curr,curr->next);
			}
			prev = curr;
			curr = curr->next;
		}
		printf("flag:%d ",flag);
		print_all(dummyHead->next);
	}
}
void main() {
	NodePtr list=NULL;
	list = append(list, 5);
	list = append(list, 2);
	list = append(list, 9);
	list = append(list, 8);
	list = append(list, 1);
	list = append(list, 7);

	print_all(list);
	puts("-----------------------------");
	bubbleSort(list);
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
