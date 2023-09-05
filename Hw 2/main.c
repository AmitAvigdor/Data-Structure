#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int sum = 0;
typedef struct Node node;
struct Node {
    int data;
    node* left;
    node* right;
};
node* NewNode(int value)
{
    node* p = (node*)malloc(sizeof(node));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

//check if the tree is empty
int isEmpty(node* root){
    if(root == NULL){
        return 1;
    }
    return 0;
}

//signature
int levelStatisticsCounter(node* root,int level,int countNodes);

//check the leafs
void printLeaves(node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        printf("%d  ", root->data);
    }
    if(root->left != NULL){
        printLeaves(root->left);
    }
    if (root->right !=NULL) {
        printLeaves(root->right);
    }
}
//making a random tree
node* randomInsertInto(node* root, int value)
{
    if (root == NULL)
        root = NewNode(value);
    else if (rand() % 2 == 0)
        root->left = randomInsertInto(root->left, value);
    else
        root->right = randomInsertInto(root->right, value);
    return root;
}

node* randomTree(){
    node* root = NULL;
    int size = 1 + rand() % 15;
    int i;
    for (i = 1; i <= size; i++)
        root = randomInsertInto(root, 1 + rand() % 50);
    return root;
}

//searching for value in the tree
int contains(node* root, int key) {
    if (root==NULL)
        return 0;
    if(root-> data == key)
           return 1;
    return (contains(root->left,key) || contains(root->right,key));

}

//count all nodes
int count(node* root)
{
    int countN =  1;
    if (root == NULL)
        return 0;
    else
    {
        countN += count(root->left);
        countN += count(root->right);
        return countN;
    }
}

//sum of all values
int sumOfKeys(node* root){
    if(root == NULL)
        return 0;
    sum = sum + root->data;
    sumOfKeys(root->left);
    sumOfKeys(root->right);
    return sum;
}

//print asked level and its quantity
void levelStatistics(node* root, int level) {
    printf("\nThe number of nodes is: %d",levelStatisticsCounter(root,level,0));
}
//function that sends values to levelStatistics
int levelStatisticsCounter(node* root,int level,int countNodes){
    if (root == NULL)
        return countNodes;
    if (level == 0){
        printf("%d  ", root->data);
        countNodes++;
    }
    else if (level >= 1)
    {
       countNodes = levelStatisticsCounter(root->left, level - 1,countNodes);
        countNodes = levelStatisticsCounter(root->right, level - 1,countNodes);
    }
    return countNodes;
}

// determines if its a perfect tree
int isPerfect(node* root){
      if (root != NULL) {
        if (root->right == NULL && root->left == NULL) {
          return 1;
        }
        if (root->right != NULL && root->left != NULL) {
          return isPerfect(root->left) && isPerfect(root->right);
        }
      }
      return 0;
    }


