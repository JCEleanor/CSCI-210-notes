#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*func_ptr)(int, int) = add;
    printf("%d\n", func_ptr(2, 3));
    return 0;
}