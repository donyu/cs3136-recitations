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

### Simulating call-by-reference ###
When you pass a parameter into a function by value, any changes made to the parameter inside the body of the function do not affect the parameter outside the scope of the function.

To address this, C++ has a "call-by-reference" where the changes made to a parameter hold after the function's execution.

C does not allow for call-by-reference, but it can simulate it by passing values by pointers.
By passing by pointers, the address of the value is passed into the function and thus the actual value can be changed.

See how this is done in the following program which features pass-by-value and pass-by-pointer double functions.
```c
#include <stdio.h>

/* A function that doubles an integer where a is the value of the actual integer */
void doubleItV(int a);
/* A function that doubles an integer where a is the pointer to an integer */
void doubleItP(int *a);

int main(int argc, char **argv)
{
  int a = 2;
  printf("The value of a is originally %d.\n", a); // a is 2
  
  doubleItV(a);
  printf("The value of a after passing by value to the double function is %d.\n", a); // should still be 2
  
  doubleItP(&a); //passing the address of a to the function
  printf("The value of a after passing by pointer (address) to the double function is %d.\n", a); // should be 4
  
  return 0;
}

/* A function that doubles an integer where a is the value of the actual integer */
void doubleItV(int a)
{
  a = 2 * a;
}

/* A function that doubles an integer where a is the pointer to an integer */
void doubleItP(int *a)
{
  *a = *a * 2;
}
```
