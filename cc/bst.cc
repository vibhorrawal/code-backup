#include <bits/stdc++.h>
using namespace std;

struct BST
{
	int data;
	BST *left;
	BST *right;
	
};
BST *newNode(int data){
	BST* temp = (BST*)malloc(sizeof(BST));
	temp->data = data;
	temp -> left = temp -> right = NULL;
	return temp;
}
BST* insert(BST *node, int data){
	if(node == NULL)
		return newNode(data);

	if(data > node -> data)
		node -> right = insert(node->right, data);
	else
		node -> left = insert(node->left, data);

	// return node;
}
void preorder(BST *node){
	if(node != NULL){
		printf(" -> %d", node ->data);
		preorder(node->left);
		preorder(node->right);
	}
}
int main(int argc, char const *argv[])
{
	int value;
	BST *root = NULL;
	printf("Enter data (-1 to end)\n");
	scanf("%d", &value);
	root = insert(root,value);
	while(true){
		scanf("%d", &value);
		if (value == -1) break;
		insert(root,value);
	}
	preorder(root);
	return 0;
}