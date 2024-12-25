#include<stdio.h>
int tentimes(int*);
int main()
{
    int i;
    printf("Enter a number\n");
    scanf("%d", &i);
    int a = tentimes(&i);
    printf("Then times the value at address %d is %d\n", &i,a);
    return 0;
}
int tentimes(int *a)
{
    return (*a)*10;
}