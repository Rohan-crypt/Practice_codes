#include <stdio.h>

int main()
{
    int num1, num2, sum;

    // Input two integers
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Calculate the sum
    sum = num1 + num2;

    // Print the result
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);

    return 0;
}
