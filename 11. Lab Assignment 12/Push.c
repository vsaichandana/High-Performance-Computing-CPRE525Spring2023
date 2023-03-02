#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void Push(const int input, inputDatabase *inputData, node** top)
{
   if (*top == NULL)
   {
      *top =(node*)malloc(sizeof(struct node));
      (*top)->next = NULL;
      (*top)->id = input;
      (*top)->inputData = inputData;
      (*top)->position = 1;
   }
   else
   {
      node* temp;
      temp =(node*)malloc(sizeof(struct node));
      temp->next = *top;
      temp->id = input;
      temp->inputData = inputData;
      temp->position = 1;
      *top = temp;

      node* ptr = (*top)->next;
      while (ptr!=NULL)
      {
	 ptr->position = ptr->position+1;
	 ptr = ptr->next;
      }
   }
}