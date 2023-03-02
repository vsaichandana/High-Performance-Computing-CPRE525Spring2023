#include <stdlib.h>
#include "node.h"

void Peek(node** top,int* output, inputDatabase** outputDatabase)
{
   node* temp = *top;
 
   if (temp==NULL)
   { return; }
   else
   { temp = temp->next; }
   *output = (*top)->id;
   *outputDatabase = (*top)->inputData;
}