#include<stdio.h>
int print(int*);
int main()
{
    int i;
    printf("Enter a number\n");
    scanf("%d", &i);
    printf("Address of this number is %d\n",&i);
    print(&i);
    return 0;
}
int print(int *a)
{
    printf("Address after passing the value if i in another function is %d\n", a);
    return 0;
}