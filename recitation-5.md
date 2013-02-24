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

### sizeof() and pointers ###
`sizeof()` is a built-in function in c that returns the size of a given variable or type in bytes as a long unsigned integer.

The size of a `char` is 1 byte.
The size of an `int` is 4 bytes.
The size of a pointer is 8 bytes.
The size of an array is equal to the array size times the size of the data inside of it.
If you are taking the sizeof() of a dereferenced pointer, the size is the size of the type after dereferencing.

```c
#include <stdio.h>

int main(int argc, char **argv)
{
  int x;
  char *c;
  int a[20];
  
  printf("%lu\n", sizeof(x));        // should be 4.  note the %lu for long unsigned int
  printf("%lu\n", sizeof(c));        // should be 8
  printf("%lu\n", sizeof(a));        // should be 80 (4 * 20)
  printf("%lu\n", sizeof(*c));       // should be 1
  printf("%lu\n", sizeof(a[1]));     // should be 4
  
  return 0;
}
```

### Arrays and Pointers ###
An array is pretty much a glorified pointer.  You can do very similar things with both of them.

In the following example, we move pointers around the array to access elements.

```c
#include <stdio.h>

int main(int argc, char **argv)
{
  int a[] = {23, 5, 4, 20, 39, 88, 6, 25, 92, 1};
  int *p = a;

  printf("%d is the same as %d\n", *p, a[0]);
  printf("%d is the same as %d\n", *(p + 4), a[4]);
  printf("%d is the same as %d is the same as %d\n", *(p + 6), a[6], *(a + 6));
  printf("%d is the same as %d is the same as %d is the same as %d\n", *(p + 9), a[9], *(a + 9), *(9 + a));

  /* you can also increment a pointer with p++! */
  int i;
  for (i = 0; i < 10; i++)
    printf("element number %d: %d\n", i, *p++);
  /* but you can't do this with an array :( */

  /* observe that now p points to one past the last element of the array */
  printf("last element: %d\nwhat p points to (not defined by us): %d\n", *(p - 1), *p);

  return 0;
}
```

### char * (strings in C) ###
As you have heard by now, C does not come with a string data type like java, python, and c++.

Instead, strings are represented as an array of chars.

You can set a char pointer or char array to a string literal, or characters surrounded by ""'s like "boat".  It is important to note that you cannot manipulate string literals like you can a normal array of characters.

C comes with a <string.h> library of functions for character array manipulation. You can find more details here: http://www.cs.cf.ac.uk/Dave/C/node19.html

```c
int strncmp(const char *s1, const char *s2, size_t n)
{
    for ( ; n > 0; s1++, s2++, --n)
  if (*s1 != *s2)
	    return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
	else if (*s1 == '\0')
	    return 0;
    return 0;
}
```
