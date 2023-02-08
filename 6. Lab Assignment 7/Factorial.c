// Author: Saichandana V
// Purpose: Lab Assignment 7 [CPRE 525]
// Created: 02/07/2023
// This C code for n factorial
// Copyright @ Iowa State University


#include <stdio.h>

// Function to calculate the factorial of a number using recursion
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int main()
{
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // Check if n is non-negative
    if (num >= 0)
    {
        int result = factorial(num);
        printf("The factorial of %d is %d\n", num, result);
    }
    else
    {
        printf("Error: n must be a non-negative integer\n");
    }
    return 0;
}
