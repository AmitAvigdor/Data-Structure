#include <stdio.h>
#include <stdlib.h>

typedef struct StudentNode{
    int idNum;
    int midGrade;
    int finalTestGrade;
    struct StudentNode *left;
    struct StudentNode *right;
    struct StudentNode *parent;
}StudentNode;

//creates new node
typedef struct BST{
    struct StudentNode* root;
}BST;

StudentNode* searchStudent(StudentNode* root, int ID);
void insert(BST *tree, int data);
void updateMidtermGrade(BST *tree,int ID, int newGrade);
void updateExamGrade(BST *tree,int ID, int newGrade);
int getFinalStudentGrade(StudentNode *root);
int getFinalGrade(BST *tree,int ID);
int getNumberOfStudent(StudentNode *root);
int getSumOfGrade(StudentNode *root);
double getAverageGrades(BST* tree);
void inOrderReportGrades(StudentNode* root);
void reportGrades(BST* tree);
int getNumOfStudentByGrade(StudentNode* root,int degLow,int degHigh);
int getNumOfFails(BST* tree);
void ReportStatistics(BST* tree);
