### Overview of the memory space of a program

Not covered in thr exam.

### Pointers

```c
int arr[] = {10, 20, 30, 40};
int *p = arr; // p points to arr[0]
p = p + 2;    // p now points to arr[2] (address moved by 2 * sizeof(int))

int arr[] = {10, 20, 30, 40}; // starts from memory address 1000, 1004, 1008, 1012

int *p1 = &arr[3];
int *p2 = &arr[0];
// 1012-1000 = 12
// 12 / sizeof(int)
ptrdiff_t diff = p1 - p2; // diff will be 3
```

### Strings, i.e., char arrays, and the string library functions

### Structs and Unions

### Function pointers

we can pass functoins as parameters, store functions in variables, etc.
`float (*p) (int, int) a;` where `float (*p) (int, int)` is a **type**

```c
// reduce.c
int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int (*reduceFunction)(int, int) ; // how you use function pointer
    reduceFunction = sum;
    printf("reduce value = %d", reduce(a, 10, reduceFunction));
}
```

p+1 is not necessary the next byte in memory

```c
void *p;
*(int*p);
// perform arithmatic on pointer (add datatype) so we need to know what datatype p is
(int)p+1
```

- character pointer
