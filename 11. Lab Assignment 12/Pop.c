#include <stdlib.h>
#include "node.h"

void Pop(node** top,int* output, inputDatabase** outputDatabase)
{
   node* temp = *top;
 
   if (temp==NULL)
   { return; }
   else
   { temp = temp->next; }
   *output = (*top)->id;
   *outputDatabase = (*top)->inputData;
   free(*top);
   *top = temp;

   node* ptr = *top;
   while (ptr!=NULL)
   {
      ptr->position = ptr->position-1;
      ptr = ptr->next;
   }
}
