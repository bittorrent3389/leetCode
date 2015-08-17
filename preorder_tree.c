#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tagTreeNode {
	int val;
	struct tagTreeNode *left;
	struct tagTreeNode *right;
}TreeNode, *TreeNodePtr;
TreeNodePtr newNode(int val) {
	TreeNodePtr ggla= (TreeNodePtr)malloc(sizeof(TreeNode));
	ggla->val = val;
	ggla->left = NULL;
	ggla->right = NULL;
	return ggla;
}
int totalNodes(TreeNodePtr root) {
    if (!root) return 0;
    return 1+totalNodes(root->left)+totalNodes(root->right);
}
int* preorder(TreeNodePtr node, int* returnSize){
	 *returnSize = totalNodes(node);	
	 int* returnArray =(int*)malloc(*returnSize*sizeof(int));
	 void _preorder(TreeNodePtr node, int **returnArray) {
		if(node) {
			**returnArray = node->val;
			(*returnArray)++;
			printf("_preorder %d,%p  \n", *(*returnArray-1), *returnArray-1);
			_preorder(node->left, returnArray);
			_preorder(node->right, returnArray);
		}
	 }
	int* tmp = returnArray;	 
	_preorder(node, &returnArray);
	printf("returnArray:%p\n", returnArray);
	return tmp;
}
void main(){
	//create a tree.
	TreeNodePtr root = newNode(3);
	root->left = newNode(1);
	root->right = newNode(2);
	//root->right->left = newNode(3);
	//root->right->right= NULL;
	int i;	
	int* res = preorder(root, &i); 
	printf("i:%d\n", i);
	while(i--)
			printf("%d ", *res++);
	puts("");
}
