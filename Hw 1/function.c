//316178144 Amit Avigdor
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
//create node
struct node {
    int data;
    struct node *next;
};
typedef struct node nNode;
//function that print the list
void printList(nNode *head)
{
    nNode *temp = head;
    printf("\nThe list is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//function that returns the length of the linked list
int length(nNode* head) {
    int length = 0;
    nNode *current;
    for (current = head; current != NULL; current = current->next) {
        length++;
    }
    return length;
}
//function that insert the new data and the pointer to the next node
nNode* BuildNode(int new_data)
{
    nNode *node = (nNode*)malloc(sizeof(nNode));
    node->data = new_data;
    node->next = NULL;
    return node;
}
//function that build the linked list
nNode* BuildList()
{
    nNode *head = NULL, *temp = head;
    int data;
    printf("Enter numbers for list, -1 for end: ");
    scanf("%d ", &data);
    while (data != -1)
    {
        if (head == NULL)
        {
            head = BuildNode(data);
            temp = head;
        }
        else
        {
            temp->next = BuildNode(data);
            temp = temp->next;
        }
        scanf("%d", &data);
    }
        return head;
}
//function that reverse the linked list
void reverse(nNode** head_ref) {
    nNode* prev = NULL;
    nNode* current = *head_ref;
    nNode* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}
//function that sort the list
void sortList(nNode* head)
{
    nNode* i;
    nNode* j = (nNode*)malloc(sizeof(nNode));
    nNode* min = (nNode*)malloc(sizeof(nNode));
    nNode* temp = (nNode*)malloc(sizeof(nNode));
    i = head;
    for (; i; i=i->next)
    {
        min = i;
        for (j = i->next; j; j = j->next)
            if ((j->data) < (min->data))
                min = j;
        SWAP(i->data, min->data, temp->data);
        
    }
}
//function that inserts the node in the correct order
nNode *insertNodeToSort(nNode *head, int newData)
{
    int flag = 0;
    nNode* current= NULL;
    nNode* new_node = (nNode*)malloc(sizeof(nNode));
    new_node->data = newData;
    if (head == NULL || head->data >= new_node->data) {
        new_node->next = head;
        head = new_node;
    }
    else {
        current = head;
        while (current->next != NULL && !flag){
            if(current->data < new_node->data && current->next->data >= new_node->data){
                new_node->next = current->next;
                current->next = new_node;
                flag = 1;
               
            }
            else if(current->next->data < new_node->data){
                current = current->next;
            }
        }
        if(flag == 0){
            new_node->next = current->next;
            current->next = new_node;
        }
    }
    return head;
}

//function that search the element in the list and prints the index of the element
void search_element(nNode *head,int newData){
    int count = 1, flag =0 ;
    nNode* temp;
    temp = head;
    while(temp != NULL){
        if(temp -> data == newData){
            printf("index of value %d is %d\n",newData,count);
            flag = 1;
            break;
        }
        else{
            count = count + 1;
            temp = temp -> next;
        }
    }
    if(flag == 0){
        printf("Value %d did not found\n",newData);
    }
}
//function that calculate the sum of the linked list
int sum(nNode* head) {
    int sum = 0;
    while(head != NULL){
        sum = head -> data + sum ;
        head = head -> next;
    }
    return sum;
}
//function that multiplies the values in the even places
int multi(nNode* head){
    int count = 1, multi = 1;
    while(head != NULL){
        if((count % 2) == 0){
            multi = multi*(head->data);
        }
        count++;
        head = head->next;
    }
    return multi;
}
