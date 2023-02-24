#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void DisplayStack(node* top)
{
   if (top == NULL)
   {
      printf(" Stack is empty.\n");
      return;
   }

   printf(" ------------------------------------------------------------------------------------------------------------------------------------\n");
   printf(" | Pos: | Student ID: |  First Name:  |  Last Name:  | Course Taken: |     DB Address:     |      Address:      |       Next:       |\n");
   printf(" ------------------------------------------------------------------------------------------------------------------------------------\n");
   PrintNode(top);
   printf(" ------------------------------------------------------------------------------------------------------------------------------------\n");
}

void PrintNode(node* top)
{
   printf(" |%5i |%12i |%15s |%14s |%13s |%19p |%19p |%19p |\n",
          top->position, top->id, top->inputData->firstName, top->inputData->lastName, top->inputData->courseTaken, top->inputData, top, top->next);
   
   if (top->next == NULL)
   {
      return;
   }

   PrintNode(top->next);
}
