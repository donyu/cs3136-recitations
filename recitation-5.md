# Recitation 5 #

## Your Best Friend - Professor Debugger ##

Although not necessary, once your C programs start getting very complicated and long you should start relying on the debugger and less on print statements. 

*Note that you will need the -g when compiling if you want to debug your program later on (i.e. gcc -g or CFLAGS = -g in Makefile)

I have included a sample C program to copy an array over to another array of equal size. But the results are strange! The printout is
```
1 2 3 4 5 
6 7 8 9 10 
6 2 8 4 10 
```
when the last 2 lines should be equal! Let's ask professor debugger what the problem is.

(1) Start - After compiling to an executable, start the debugger on your program.
```
gdb ./debug_example
```

(2) Set Breakpoints - Place breakpoints at specific lines where you think the error could be occuring as follows.
```
(gdb) break <file name>:<line number>
```
When running the program through the debugger, the debugger will stop at that line you specified so that you can inspect variables at that point.
*Note that you can turn line numbers on in vim through the command "set nu" in command mode

You can also add a breakpoint to specific functions! The syntax for the command would be
```
(gdb) break <function name>
```
I expect you guys might want to debug your merge() or Jae's merge_sort() functions.
```
(gdb) break merge.c:merge
```
For this example there is only one file so we can forget about specifying the file name.
```
(gdb) break overwrite_array
```

(3) Run - Now run the program as follows
```
(gdb) run [args you would pass into program if any]
```
But since our example program doesn't take any args, we can just use
```
(gdb) run
```

(4) Inspect - The program will continue to run normally until it hits a breakpoint you specified earlier at which point you'll see a printout like the following. *Note that in this assignment you would have to give it user input before it reaches any break point
```
Breakpoint 1, overwrite_array (orig=0x7fff5fbff6b4, orig_size=5, copy=0x7fff5fbff6a0, copy_size=5) at debug_example.c:13
13    int i = 0;
(gdb) 
```
The last print from the debugger tells you what line you stopped at. Lets go on to the next line.
```
(gdb) next
14    while(i < orig_size) {
```
From here we can enter in commands to see what specific variables are at this stage of the program. I want to see what i is.
```
(gdb) print i
$1 = 0
```
Looks good so far. Let's continue on with the program.
```
(gdb) next
15      orig[i++] = copy[i++];
(gdb) break
Breakpoint 2 at 0x100000d1b: file debug_example.c, line 15.
```
*Note that here I see go to the next line and set a breakpoint at a more specific place where I think the error is occuring.

From there let's continue on to the next break by typing in "continue".
```
(gdb) continue
Continuing.

Breakpoint 2, overwrite_array (orig=0x7fff5fbff6b4, orig_size=5, copy=0x7fff5fbff6a0, copy_size=5) at debug_example.c:15
15      orig[i++] = copy[i++];
```
We are at the breakpoint we just set before (because of the while loop) and we can inspect that the program after one iteration of the loop.
```
(gdb) print i
$2 = 2
(gdb) print *orig@orig_size
$3 = {6, 2, 3, 4, 5}
(gdb) print *copy@copy_size
$4 = {6, 7, 8, 9, 10}
```
Everything seems to be working properly, though the value of i is off. 

Here we used the command "print" to print all of the elements of an array (very useful for your homework assignment!). Note that the deference * is needed to print an array and the @ is the syntax used to specify how many elements in that array to print.
```
print *<array name>@<number of elements to print>
```

Lets continue one more time to be find out what the error is.
```
(gdb) continue
Continuing.

Breakpoint 2, overwrite_array (orig=0x7fff5fbff6b4, orig_size=5, copy=0x7fff5fbff6a0, copy_size=5) at debug_example.c:15
15      orig[i++] = copy[i++];
(gdb) print i
$5 = 4
(gdb) print *orig@orig_size
$6 = {6, 2, 8, 4, 5}
(gdb) print *copy@copy_size
$7 = {6, 7, 8, 9, 10}
```

Doh! We see here that we are incrementing i twice rather than just once and the only ever other element is copied from the copy array to the original array.

(5) Quit and Fix - Now quit gdb and go back to revising your program with newfound knowledge of what was wrong!
```
(gdb) quit
``` 

There is a lot more that the debugger can do, and I encourage you to research online for more tips/tricks ond debugging your programs.

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

C comes with a <string.h> library of functions for string literal manipulation. You can find more details here: http://www.cs.cf.ac.uk/Dave/C/node19.html

Because there is no string data type, there is no == operator for string literals.  Below is the strncmp function.  It is used to evaluate whether the first n characters of 2 strings are the same.
It returns 0 if the first n characters of the strings are the same (or if the first string has less than n characters and they all match up).  It returns -1 or 1 otherwise depending on the first character mismatch.
```c
int strncmp(const char *s1, const char *s2, int n)
{
	int i;
	for (i = 0; n > 0; i++)
  		if (*(s1 + i) != *(s2 + i))				// dereference pointers
  		{
  			if (*(unsigned char *)(s1 + i) < *(unsigned char *)(s2 + i)) //the cast is to get rid of warnings
  				return -1;
  			else
  				return 1;
  		}
		else if (*s1 == '\0')
	    	return 0;
  	return 0;
}
```
