#include <stdio.h> // must include this because printf is defined here

int power(int a, int b);

int globalA;
int main()
{

    int i;
    i = 5;

    printf("Hello World! %d\n", power(i, globalA));
    return 0;
}