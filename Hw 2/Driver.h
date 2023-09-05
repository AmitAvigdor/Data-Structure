#ifndef Driver_h
#define Driver_h

typedef struct Node node;
struct Node {
    int data;
    node* left;
    node* right;
};
node* NewNode(int);
int isEmpty(node*);
int levelStatisticsCounter(node*,int,int);
void printLeaves(node*);
node* randomInsertInto(node*, int);
node* randomTree(void);
int contains(node*, int);
int count(node*);
int sumOfKeys(node*);
void levelStatistics(node*, int);
int levelStatisticsCounter(node*,int,int);
int isPerfect(node*);
#endif /* Driver_h */
