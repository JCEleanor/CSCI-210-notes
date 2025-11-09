### Overview of the memory space of a program

Not covered in thr exam.

#### Stack & Heaps

##### Heaps

A memory region allocated via `malloc(size)` and `free`. Access the memory via pointers. Use a static cast to tell C what type of data your region will hold.
**initialization is very important**

#### `malloc`

There are issues with the code below:

```c
int *p;
p = (int *)malloc(sizeof(int)*5);
*p = 8;
p[4] = 9;
```

Corrected version:

```c
int *p;
p = (int *)malloc(sizeof(int) * 5);

// 2. CHECK if allocation was successful
if (p == NULL) {
    // Handle the error, e.g., print a message and exit
    fprintf(stderr, "Memory allocation failed\n");
    // exit(1); // Would need <stdlib.h>
} else {
    // 3. Use the memory (only if p is not NULL)
    *p = 8;     // Same as p[0] = 8
    p[4] = 9;

    // ... do other work with p ...

    // 4. Free the memory when done
    free(p);
}

// After freeing, p is a "dangling pointer"
// Good practice is to set it to NULL.
p = NULL;
```

- `malloc` doesn't zero or initialize the region.
- you can zero a memory region "by hand"

#### `memset`

memset is a standard C function that fills a block of memory with a specific byte value. It takes three arguments:

1.  A pointer to the start of the memory block.
2.  The byte value to fill with.
3.  The number of bytes to fill.

```c
// if ptr points to a memory of 1000 bytes, use
memset(ptr, 0, 1000);
```

- `memset` is a function that sets a specified amount of bytes at one address to a certain value.

```c
// fills n byte starting at memory location s with the byte c
void *memset(void *s, int c, size_t n);

// another example
int counts[5];
memset(counts, 0, 3) // zero out first 3 bytes at counts
memset(counts + 3, 0xff, 4) // set 3rd entry's byte to 11111111 (255 in decimal)
```

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

A string in C is a null-terminated array of characters.

String constants (also called string literals) are enclosed in double quotes (e.g., "hello"). Single quotes (e.g., 'a') are used for single character constants.

The strlen() function counts the number of characters up to, but not including, the null terminator. For example, strlen("hello") returns 5.

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
