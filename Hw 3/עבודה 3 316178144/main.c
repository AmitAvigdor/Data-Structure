
#include "studentBST.h"


void main(){
    BST* tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;
    insert(tree,20);
    insert(tree,5);
    insert(tree,1);
    insert(tree,15);
    insert(tree,9);
    insert(tree,7);
    insert(tree,12);
    insert(tree,30);
    insert(tree,25);
    insert(tree,40);
    insert(tree, 45);
    insert(tree, 42);
}