#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}
int product(int a, int b) { return a * b; }

int reduce(int *list, int n, int (*f)(int, int))
{
    if (n == 1)
        return list[0];
    return f(list[0], reduce(list + 1, n - 1, f));
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int (*reduceFunction)(int, int);
    reduceFunction = sum;
    printf("reduced value = %d\n", reduce(a, 10, reduceFunction));
    reduceFunction = product;
    printf("reduced value = %d\n", reduce(a, 10, reduceFunction));
}