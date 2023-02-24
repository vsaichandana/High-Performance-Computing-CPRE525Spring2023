#ifndef __NODE_H__
#define __NODE_H__

typedef struct db inputDatabase;
struct db
{
   int studentID;
   char firstName[100];
   char lastName[100];
   char courseTaken[100];
};

typedef struct node node;
struct node
{
   int position;
   //int value;
   int id;
   inputDatabase* inputData;
   node* next;
};


int QueryOption();
void ExecuteOption(const int option, node** top);
void DisplayOptions();
void Push(const int input, inputDatabase *inputData, node** top);
// void Push(const int input, node** top);
void Pop(node** top,int* output, inputDatabase** outputDatabase);
// void Pop(node** top, int* output);
void Peek(node** top,int* output, inputDatabase** outputDatabase);
// int Peek(node* top);
void DisplayStack(node* top);
void PrintNode(node* top);
void GetStackSize(node* top, int* stack_size);
void DeleteStack(node** top);

#endif
