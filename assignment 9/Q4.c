#include <stdio.h>

// User-defined functions
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

// Master function accepting two integers and a function pointer as parameters
int compute(int a, int b, int (*op)(int, int)) {
    return op(a, b);
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Call compute() three times passing functions directly as arguments
    int sumResult = compute(num1, num2, add);
    int productResult = compute(num1, num2, multiply);
    int maxResult = compute(num1, num2, findMax);

    printf("\n--- Results ---\n");
    printf("Sum: %d\n", sumResult);
    printf("Product: %d\n", productResult);
    printf("Maximum: %d\n", maxResult);

    return 0;
}