#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a new type F which is a pointer to function
typedef double (*F)(double, int);

// Function declarations
double power(double x, int n);
double multiply(double x, int n);
double divide(double x, int n);
double powerpower(F func, double x, int n, int m);

int main(int argc, char *argv[]) {
    // Check if there are enough command-line arguments
    if (argc != 4) {
        printf("Usage: %s <x> <n> <m>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    double x = atof(argv[1]);
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);

    // Use function pointers to choose the operation
    F operations[] = {power, multiply, divide};
    char* operation_names[] = {"power", "multiply", "divide"};

    // Perform the calculations and display the results
    for (int i = 0; i < 3; i++) {
        double result = powerpower(operations[i], x, n, m);
        printf("(%s(%f, %d))^%d = %f\n", operation_names[i], x, n, m, result);
    }

    return 0;
}

// Function definitions
double power(double x, int n) {
    return pow(x, n);
}

double multiply(double x, int n) {
    return x * n;
}

double divide(double x, int n) {
    if (n != 0) {
        return x / n;
    } else {
        printf("Error: Division by zero.\n");
        exit(1);
    }
}

double powerpower(F func, double x, int n, int m) {
    // Use the provided function pointer to calculate (x^n)^m
    return pow(func(x, n), m);
}
