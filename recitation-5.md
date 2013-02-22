# Recitation 5 #

## Pointers on Pointers on Pointers ##

### What's a pointer again? ###
A pointer is a data type whose value is an address in memory. The value "points" to another value stored in that memory location.

### NULL Pointer ###
A NULL pointer holds the memory address 0.

It cannot be dereferenced.

It can be initialized with `NULL` or `0` as done in the below example.
```c
  char *c = NULL;
  int *p = 0;
  if (p)  // same as "if (p != 0)" or "if (p != NULL)"
    printf("p is not a NULL pointer.\n");
  if (!p) // same as "if (p == 0)" or "if (p == NULL)"
    printf("p is a NULL pointer.\n");
```

### Pass-by-pointer ###
