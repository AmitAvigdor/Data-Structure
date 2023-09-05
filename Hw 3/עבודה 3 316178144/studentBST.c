#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "studentBST.h"




StudentNode* searchStudent(StudentNode* root, int ID)
{
    if (root == NULL)
        return NULL;
    if (root->idNum == ID)
        return root;
    if (ID <= root->idNum)
        return searchStudent(root->left, ID);
    else
        return searchStudent(root->right, ID);
}

void insert(BST *tree, int data)
{
    StudentNode *newnode = (StudentNode*)malloc(sizeof(StudentNode));

    newnode->idNum = data;
    newnode->midGrade = 0;
    newnode->finalTestGrade = 0;
    newnode->left = NULL;
    newnode->right = NULL;


    StudentNode *y = NULL;
    StudentNode *x = tree->root;

    while (x != NULL) {
        y = x;
        if (newnode->idNum < x->idNum)
            x = x->left;
        else
            x = x->right;
    }

    newnode->parent = y;
    if (y == NULL) // there was empty tree
        tree->root = newnode;
    else if (y->idNum > data)
    {
        y->left = newnode;
    }
    else
    {
        y->right = newnode;
    }
}

void updateMidtermGrade(BST *tree,int ID, int newGrade) {
    struct Student *tmpRoot = tree->root;                   // Create new pointer for the root of the BST for send to the search function.
    struct StudentNode *root = searchStudent(tmpRoot, ID);
    if (root != NULL)
        root->midGrade = newGrade;
}

void updateExamGrade(BST *tree,int ID, int newGrade) {
    struct Student *tmpRoot = tree->root;                   // Create new pointer for the root of the BST for send to the search function.
    struct StudentNode *root = searchStudent(tmpRoot, ID);
    if (root != NULL)
        root->finalTestGrade = newGrade;
}

int getFinalStudentGrade(StudentNode *root){
    int ans = 0,m_d;
    double g_f;
    if(root != NULL) {
        g_f = (root->midGrade * 0.3) + (root->finalTestGrade * 0.7);
        m_d = ((int)(g_f*10)%10);
        if(m_d < 6)
            ans =  (int)g_f;
        else{
            m_d = m_d/10;
            ans = g_f+(1-m_d);
        }


    }
    return ans;
}

int getFinalGrade(BST *tree,int ID){
    struct Student *tmpRoot = tree->root;                   // Create new pointer for the root of the BST for send to the search function.
    struct StudentNode *root = searchStudent(tmpRoot, ID);
    return getFinalStudentGrade(root);

}



int getNumberOfStudent(StudentNode *root){
    int sum = 0;
    if(root == NULL){
        return sum;
    }
    sum = getNumberOfStudent(root->right)+getNumberOfStudent(root->left);
    return (sum+1);

}

int getSumOfGrade(StudentNode *root){
    int sum = 0;
    if(root == NULL){
        return sum;
    }
    sum = getSumOfGrade(root->right)+getSumOfGrade(root->left);
    return (sum+getFinalStudentGrade(root));

}

double getAverageGrades(BST* tree){
    struct Student *tmpRoot = tree->root;                   // Create new pointer for the root of the BST for send to the search function.
    struct Student *tmpRoot2 = tree->root;                   // Create new pointer for the root of the BST for send to the search function.
    int studentNum,sumGrade;
    studentNum = getNumberOfStudent(tmpRoot);
    sumGrade = getSumOfGrade(tmpRoot2);
    return (sumGrade/studentNum);

}
void inOrderReportGrades(StudentNode* root){
    if(root == NULL)
        return;
    inOrderReportGrades(root->left);
    printf("%d\t%d\t%d\t%d\n",root->idNum,root->midGrade,root->finalTestGrade,getFinalStudentGrade(root));
    inOrderReportGrades(root->right);
}


void reportGrades(BST* tree){
    struct Student *tmpRoot = tree->root;                   // Create new pointer for the root of the BST for send to the search function.
    inOrderReportGrades(tmpRoot);
}

int getNumOfStudentByGrade(StudentNode* root,int degLow,int degHigh){
    int sum = 0;
    int grade;
    if(root == NULL){
        return sum;
    }
    sum = getNumOfStudentByGrade(root->right,degLow,degHigh)+getNumOfStudentByGrade(root->left,degLow,degHigh);
    grade = getFinalStudentGrade(root);
    if(grade >= degLow && grade <= degHigh )
        return (sum+1);
    return sum;

}

int getNumOfFails(BST* tree){
    struct Student *tmpRoot = tree->root;                   // Create new pointer for the root of the BST for send to the search function.
    return getNumOfStudentByGrade(tmpRoot,0,55);
}


void ReportStatistics(BST* tree){
    struct Student *tmpRoot = tree->root;                   // Create new pointer for the root of the BST for send to the search function.
    struct Student *tmpRoot2 = tree->root;                   // Create new pointer for the root of the BST for send to the search function.
    struct Student *tmpRoot3 = tree->root;                   // Create new pointer for the root of the BST for send to the search function.
    printf("\t\t     Degree    \tfinal grade\n");
    printf("Good     \t(56-75) \t%d\n",getNumOfStudentByGrade(tmpRoot,56,75));
    printf("Very Good\t(76-94) \t%d\n",getNumOfStudentByGrade(tmpRoot2,76,94));
    printf("Excellent\t(95-100)\t%d\n",getNumOfStudentByGrade(tmpRoot3,95,100));
}
