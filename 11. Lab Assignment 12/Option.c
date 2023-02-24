#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int QueryOption()
{
	int option;
	printf("------------------------------------------\n");
	printf(" ENTER CHOICE : ");
	scanf("%i", &option);
	return option;
}

void ExecuteOption(const int option, node **top)
{
	// int value;
	int id;
	inputDatabase *inputData;
	inputData = (inputDatabase *)malloc(sizeof(struct db));

	switch (option)
	{
	case 0: // Display available options
		DisplayOptions();
		break;
	case 1: // Enter a new value then push new node to stack
		int c;
		while ((c = getchar()) != '\n' && c != EOF)
			;
		printf(" Enter ID: ");
		while (scanf("%d", &id) != 1)
		{
			printf("Invalid input. Enter ID: ");
			// Clear input buffer
			while ((c = getchar()) != '\n' && c != EOF);
		}
		inputData->studentID = id;
		printf(" Enter First Name : ");
		scanf("%s", inputData->firstName);
		printf(" Enter Last Name : ");
		scanf("%s", inputData->lastName);
		printf(" Enter course Taken : ");
		scanf("%s", inputData->courseTaken);
		Push(id, inputData, top);
		printf("-----------[PUSH operation performed]------\n");
		break;
	case 2: // Pop top value off of stack
		if (*top != NULL)
		{
			Pop(top, &id, &inputData);
			printf("-----------[POP operation performed]------\n");
			printf(" Pop Student ID = %i\n", id);
			// printf(" Pop inputdata address = %15p\n", inputData);
			printf(" Pop First Name is %s\n", inputData->firstName);
			printf(" Pop Last Name is %s\n", inputData->lastName);
			printf(" Pop Course Taken is %s\n", inputData->courseTaken);
			printf("------------------------------------------\n");
		}
		else
		{
			printf(" Stack is empty.\n");
		}
		break;
	case 3: // Peek at top value on stack
		if ((*top) != NULL)
		{
			Peek(top, &id, &inputData);
			printf("----------[PEEK operation performed]------\n");
			printf(" Top Student ID is %i\n", inputData->studentID);
			printf(" Top First Name is %s\n", inputData->firstName);
			printf(" Top Last Name is %s\n", inputData->lastName);
			printf(" Top Course Taken is %s\n", inputData->courseTaken);
			printf("------------------------------------------\n");
		}
		else
		{
			printf(" Stack is empty.\n");
		}
		break;
	case 4: // Display the entire stack
	printf("----[Display operation performed]------\n");
		DisplayStack(*top);
		break;
	case 5: // Print stack size
		GetStackSize(*top, &id);
		printf("----[Stack Size operation performed]------\n");
		printf(" Stack size is %i\n", id);
		printf("------------------------------------------\n");
		break;
	case 6: // Do nothing here, but this causes code to end
		break;
	default:
		printf("Error: incorrect option. Try again.\n");
		break;
	}
}
