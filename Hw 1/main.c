//316178144 Amit Avigdor
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"function.h"

int main(){
//   Q-1 prints the length of linked list
    nNode* head = NULL;
    int data;
    head = BuildList();
    printList(head);
    printf("The length is: %d\n",length(head));
    
//  Q-2 sorting the list
    printf("\nSorted List: ");
    sortList(head);
    printList(head);
//  Q-2 puts the new number in the correct order
    printf("\nEnter a number for new node Sort List: ");
    scanf("%d", &data);
    head = insertNodeToSort(head,data);
    printList(head);
    printf("The length is: %d\n",length(head));
    
//  Q-3 searching the value in the linked list and printing its location in the list
    printf("\nEnter a value for find: ");
    scanf("%d", &data);
    search_element(head,data);
    
//  Q-4 reverse the linked list
    printf("\nReversed list:\n ");
    reverse(&head);
    printList(head);
    
//  Q-5 calculate the total sum of the linked lists values
    printf("\nSum of list is %d\n",sum(head));
    
//  Q-6 function that multiplies the values in the even places
    printf("\nProduct of even index values of list is %d\n",multi(head));
    
    return 0;
}
