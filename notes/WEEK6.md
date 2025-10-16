## Intro to C

- Most system software including OS kernels are written in C/C++
- We will be using C in Linux on the x86-64 architecture

### imperative programming

- c is an imperative language
- Every C program starts with the function `main()`

```c
int main(int argc, char **argv) {
return 0;
}
```

## Compiling and Running Programs from the Command Line

`gcc –g –Wall –std=c11 –o example example.c`

## Data Representation

### char

it's always 1 byte

- unsigned v signed: use unsigned char if you want positive only value

```c
#include <stdio.h>

int main()
{
    // Because c is an unsigned char, it can only hold values from 0 to 255.
    unsigned char c;
    int i;
    c='A';
    for (i=0;i<300;i++) {
            printf("%d\t",c);
            printf("%c\n",c);
            c++;
    }
    return 0;
}
```

### int

- **unsigned integers follow base 2 system**
- signed integers
- long integers

### sign-and-magintude

There are 2 major problems

1. two zeors

```
 0000 0000 (+0)
 1000 0000 (-0)
```

2. complicated arithmetic

the rules for addition and subtraction change depending on the signs of the numbers. For example, `5 + (-3)` is really a subtraction, while `(-5) + (-3)` is an addition where you have to ignore the signs and then add the sign back at the end. This would require the CPU to have separate, more complex circuits for adding and subtracting.

#### Two's complement

Two's complement fixes both issues.

1.  It Has Only One Zero: In two's complement, 0000 0000 is the only representation for zero. The bit pattern that would have been "-0" (1000 0000) is used to represent the most negative number, giving the system an extra negative value.

2.  It Radically Simplifies Arithmetic: This is the most important benefit. With two's complement, subtraction becomes addition. To calculate A - B, the computer just calculates A + (-B). The same hardware circuit (the adder) can be used for both addition and subtraction, which makes the CPU simpler, smaller, and faster.

### Shortcut to convert from "two's complement":

- if the leading bit is zero, no need to convert
- if the leading bit is one, invert the number and add 1
- with 2's complement we can represent numbers from -2^N-1 to 2^N-1 - 1 using N bits

**In summary, two's complement is used because it eliminates the ambiguity of having two zeros and, most importantly, it simplifies computer**

##### All possible values in a 4-bit system

| Binary | Unsigned | Binary | Signed |
| ------ | -------- | ------ | ------ |
| 0000   | 0        | 1111   | -1     |
| 0001   | 1        | 1110   | -2     |
| 0010   | 2        | 1101   | -3     |
| 0011   | 3        | 1100   | -4     |
| 0100   | 4        | 1011   | -5     |
| 0101   | 5        | 1010   | -6     |
| 0110   | 6        | 1001   | -7     |
| 0111   | 7        | 1000   | -8     |

### float

#### IEEE floating point standards

The IEEE 754 Single-Precision Floating-Point standard is the most common way computers represent real numbers (like 3.14 or -0.0025) in a compact, 32-bit format.

[A detailed explanation can be found here](./IEEE-floating-point-standards.md)

- float vs double
