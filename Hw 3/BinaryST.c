#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;

} Node;
//===============================================================

typedef struct BST{
	struct Node *root;
} BST;
//===============================================================

void insert(BST *tree, int data)
{
	Node *newnode = (Node*)malloc(sizeof(Node));
	
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;
	
	Node *y = NULL;
	Node *x = tree->root;

	while (x != NULL) {
		y = x;
		if (newnode->data < x->data)
			x = x->left;
		else
			x = x->right;
	}

	newnode->parent = y;
	if (y == NULL) // there was empty tree
		tree->root = newnode;
	else if (y->data > data) 
	{
		y->left = newnode;
	}
	else 
	{
		y->right = newnode;
	}	
}

//===============================================================
void printNode(Node* node) {
	if (node == NULL) {
		return;
	}
	printf("(");
	printNode(node->left);
	printf("%d", node->data);
	printNode(node->right);
	printf(")");
}

void printTree(BST* tree) {
	printNode(tree->root);
	printf("\n");
}
//===============================================================
int binSearch(Node* node, int data)
{
	if (node == NULL)
		return 0;
	if (node->data == data)
		return 1;
	if (data <= node->data)
		return binSearch(node->left, data);
	else
		return binSearch(node->right, data);
}

int Search(BST* tree, int data)
{
	return binSearch(tree->root, data);
}

//===============================================================
void freeNodes(Node *node){ //free allocated memory!!!
	if (node == NULL)
		return;
	freeNodes(node->left);
	freeNodes(node->right);
	free(node);
}

void freeTree(BST *tree) { //free allocated memory!!!
	freeNodes(tree->root);
}

//===============================================================

int main()
{	
	BST *t = (BST*)malloc(sizeof(BST));
	t->root = NULL;
	int i;
	int arr[] = { 15,9,26,10,3,29,24 };
	int size = sizeof(arr) / sizeof(int);
	for (i = 0; i < size; i++)
		insert(t, arr[i]);
	printf("Tree is:\n");
	printf("**************************************************\n");
	printTree(t);
	printf("**************************************************\n");
	printf("29 in tree? %d\n", Search(t, 29));
	printf("16 in tree? %d\n", Search(t, 16));
	freeTree(t); //free allocated memory!
	return 0;
}