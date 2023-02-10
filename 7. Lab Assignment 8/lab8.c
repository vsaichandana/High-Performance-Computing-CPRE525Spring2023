// Author: Saichandana V
// Purpose: Lab Assignment 8 [CPRE 525]
// Created: 02/09/2023
// This C code for n factorial and exponential
// Copyright @ Iowa State University

#include <stdio.h>
#include <math.h>

// my_factorial function using recursive logic based on Lab Assignment 4's Python code 
long long my_factorial(int n) {
    // Check for non-integer input value
    if (n != (int)n) {
        printf("[ERROR] Input must be an integer\n");
        return 0;
    }
    // Check for negative input value
    if (n < 0) {
        printf("[ERROR] Input must be a non-negative integer\n");
        return 0;
    }
    // Check for zero input value
    if (n == 0) {
        return 1;
    }
    // Recursive calculation of the factorial
    return n * my_factorial(n - 1);
}

// Compute the exponential of a real number using Taylor expansions with e^x0
double my_exp1(double x, int kmax, double e) {
    int x0 = round(x);
    double z = x - x0;
    double sum = 0;
    for (int i = 0; i <= kmax; i++) {
        sum += pow(z, i) / my_factorial(i);
    }
    return pow(e, x0) * sum;
}

// my_exp function without using e^x0
double my_exp2(double x, int n,  double e) {
    double result = 0;
    // Using my_factorial to calculate the exponential
    for (int i = 0; i < n; i++) {
        result += pow(x, i) / my_factorial(i);
    }

    return result;
}



int main() {
    int n;
    int inputDataSize;
    double x[5];
    double result[5];
    const double e = 2.718281828459;
    int ITERATIONS =  10;


    // get the value of n from the user
    printf("Enter an integer value for n: ");
    scanf("%d", &n);

    // compute and display the factorial of n
    int factorial_of_n = my_factorial(n);
    printf("The factorial of %d is %d\n", n, factorial_of_n);

    // get the value of array input data
    printf("Enter the size of array input data: ");
    scanf("%d", &inputDataSize);

    // get the values of x from the user
    for (int i = 0; i < inputDataSize; i++) {
        printf("Enter input data [%d]: ",i+1);
        scanf("%lf", &x[i]);
    }

    // compute the exponential of each value of x
    for (int i = 0; i < 5; i++) {
        // method 1 of exponential function
        result[i] = my_exp1(x[i],ITERATIONS,e);
        // method 2 of exponential function
        // result[i] = my_exp2(x[i],ITERATIONS,e);
    }

    // display the exponential of each value of x
    printf("The exponential values of x are: ");
    for (int i = 0; i < 5; i++) {
        printf("\nThe exponential values of x[%d]:e^%.1lf = %.2lf ",i+1,x[i],result[i]);
        // printf("%.2lf ", result[i]);
    }
    printf("\n");

    // save the exponential values of x to a data file
    FILE *fp;
    fp = fopen("data.txt", "w");
    for (int i = 0; i < inputDataSize; i++) {
        fprintf(fp, "%.2lf\n", result[i]);
    }
    fclose(fp);

    return 0;
}
