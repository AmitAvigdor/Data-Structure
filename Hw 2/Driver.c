#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "Driver.h"

int main()
{
    node* root;
    root = randomTree();
    int treeCont,countN,levelS=0,key=0;
//    Q-1
    printf("Is the tree empty?: %d\n",isEmpty(root));
//    Q-2
    printf("The Leaves are: ");
    printLeaves(root);
//    Q-3
    printf("\nInsert a key: ");
    scanf("%d",&key);
    treeCont = contains(root,key);
    printf("Is the tree contains the key? %d ",treeCont);
//    Q-4
    countN = count(root);
    printf("\nNumber of node: %d \n",countN);
//    Q-5
    printf("The sum of keys is: %d\n",sumOfKeys(root));
//    Q-6
    printf("Enter wanted level: ");
    scanf("%d",&levelS);
    levelStatistics(root,levelS);
//    Q-7
    printf("\nIs the tree perfect? %d\n",isPerfect(root));
    return 0;
}
