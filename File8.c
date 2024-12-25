#include <stdio.h>
int avg(int *);
int sum(int *, int *);
int main()
{
    int i, j;
    printf("Enter two number\n");
    scanf("%d", &i);
    scanf("%d", &j);
    int s = sum(&i, &j);
    int average = avg(&s);
    printf("The sum of numbers %d & %d is %d\n", i, j, s);
    printf("The average is %d\n", average);
    return 0;
}
int sum(int *a, int *b)
{
    return (*a) + (*b);
}
int avg(int *a)
{
    return (*a) / 2;
}