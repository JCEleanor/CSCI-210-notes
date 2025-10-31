p+1 is not necessary the next byte in memory

```c
void *p;
*(int*p);
// perform arithmatic on pointer (add datatype) so we need to know what datatype p is
(int)p+1
```

- character pointer
