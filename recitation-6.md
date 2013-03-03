# Recitation 6 #

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

## Malloc ##
Sometimes you want a bit more than a local variable, but less than a static variable.  
Sometimes, you want a dynamic AND persistant array.  Who you gonna call? -> Heap allocation.
How you gonna call it? -> with malloc().
A variable allocated on the heap will stay there until free() is called.  Wow!
Example:
```c
#include <stdio.h> // look!  a new library for malloc and free!
#include <stdlib.h>

int *allocateIntArray()
{
  int *p = (int *)malloc(3 * sizeof(int));
  return p;
}

void callNumber(int *p)
{
  printf("Calling ");
  int i;
  for (i = 0; i < (sizeof(p)/sizeof(int)) + 1; i++)
  {
    printf("%d", *(p + i));
  }
  printf("\n");
}

void freeIntArray(int *p)
{
  free(p);
}

int main(int argc, char **argv)
{
  int *emergency = allocateIntArray();
  *(emergency) = 9;
  *(emergency + 1) = 1;
  *(emergency + 2) = 1;
  callNumber(emergency);
  freeIntArray(emergency);
  return 0;
}
```
## Structs ##
### What's a struct? ###
A struct is a collection of variables.  Some may say "it's like a class in C".
No!  There were structs well before there were classes in C++ and Java.  A class is an expansion of a struct.
One of the key differences between a struct and a class is that the variables in a struct are inherently public while the variables in a class are inherently private.
But you don't have to worry about classes for the time being, cause we're still in C.

Contact Example:
typedef
