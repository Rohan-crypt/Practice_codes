#include<stdio.h>
int main()
{
    int a;
    printf("Enter a number\n");
    scanf("%d", &a);
    int *b=&a;
    printf("Address of this number is %d\n",b);
    printf("Value at address %d is %d\n", b,*b);
    return 0;
}