//316178144 Amit Avigdor
#ifndef function_h
#define function_h

struct node {
    int data;
    struct node *next;
};
typedef struct node nNode;

nNode* BuildList();
void printList(nNode* );
int length(nNode*);
nNode* BuildNode(int);
void reverse(nNode**);
void sortList(nNode*);
nNode *insertNodeToSort(nNode*, int);
void search_element(nNode*,int);
int sum(nNode*);
int multi(nNode*);
#endif
