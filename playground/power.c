#include <stdio.h>

extern int globalA;

int power(int a, int b)
{
    int i = 0;
    int result = 1;
    printf("globalA is = %d\n", globalA);
    for (i = 0; i < b; i++)
    {
        result = result * a;
    }
    return result;
}