# Recitation 2 #

## Makefiles ##

Make is a UNIX utility that follows a blueprint you create for compiling
programs. Calling `make` will automatically search your current directory for a
file called "Makefile" and use it to call various compiler commands according to
the rules outlined therein. 

### Jae's myadd Makefile ###

Take Jae's Makefile piece by piece. It can be found in this git repository as
`sample-makefile`

```make
CC  = gcc
CXX = g++
```

Make has a some pre-configured rules for how to compile programs. For example it
knows how to specify files as arguments to a compiler. However, you should tell
it what compiler to use for C files and C++ files. Here, we set the
special make variables CC and CXX to gcc, the C-compiler, and g++, the c++
compiler.

```make
INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)
```

Here we define our own variable, INCLUDES, which we can use for directories that
we wish to include at the compilation step. An example value for INCLUDES could
be `-I/home/jae/cs3157` which would tell the compiler to look in
/home/jae/cs3157 during the compilation step for missing header files and other
sorts of relevant files.

After defining INCLUDES, we define the flags that we want each compiler to be
run with. In this case we include the `-g` flag for debugging and `-Wall` flag
to display all warnings. Lastly, we reference our variable INCLUDES to add those
flags as well.

```make
LDFLAGS = -g
```

LDFLAGS are the flags that are appended to the compiler when using it for
linking. In this case we just want the debugging info to be included.

```make
LDLIBS =
```

LDLIBS will automatically be appended to the linker commands. These are flags
like `-lm` and function similarly to our INCLUDES variable but are added at a
different step. `m` denotes the math library.

That's about it for our variable declarations. The next step is to define
compile order and dependencies. The very first "target" or rule in your makefile
gets built when you type `make` in this case the first target is:

```make
main: main.o myadd.o
```

Note that we did not specify the linking rule, because make follows an implied
linking rule:

    $(CC) $(LDFLAGS) <all-dependent-.o-files> $(LDLIBS)

Also note that make assumes that main depends on main.o, so we could omit it:

    main: myadd.o 

Basically what this rule says is make should produce an executable called "main"
by linking myadd.o and main.o. This declares main.o and myadd.o as dependencies
of main, meaning that if any of the dependencies (or their dependencies) change 
between the last time this target was run, it should re-run the outdated targets
as well as this one.

The next target we declare is main.o:

```make
main.o: main.c myadd.h
```

This says that main.o depends on main.c (assumed) as well as myadd.h. See last
week's recitation notes to understand why main.o depends on myadd.h. We could
omit main.c as follows:

  main.o: myadd.h

Either way, we do not specify a rule here because make assumes the implicit
rule:

    $(CC) -c $(CFLAGS) <the-.c-file>

Lastly, we specify the target for myadd.o:

```make
myadd.o: myadd.c myadd.h
```

We'll include two phony targets. We tell make that they're "phony" so that it
doesn't attempt to use implicit rules or try to compile them. The first target
we make is "clean" which should remove all intermediate files. *Always include a
clean* so that `make clean` can be used to remove intermediate files like object
files, compiled code, etc. This should return your directory to just its source
code that can generate all the other files. *Be careful:* Using `rm -f` will not
prompt you to remove files. This is customary for `make clean` but it also means
if you make a mistake in designing your rule it could remove files that you
didn't want to. There is no "trash" in UNIX - they'll be gone forever.

Lastly, we define a phony "all" target that just depends on the main and clean
targets. This will always remove all intermediate files and compiled files,
forcing make to recompile everything when main is called.

```make
.PHONY: clean
clean:
        rm -f *.o a.out core main

.PHONY: all
all: clean main
```

## C data types ##

While C provides many basic data types, the one's that you'll mostly be concerned about are char, short, int, and long. The memory sizes for each type is system specific (different from Java where primitive memory sizes are language defined). 

### Binary numbers ###

All data is represented in binary, so let's take a quick review of it. The binary number system is just a base-2 number system as opposed to the base-10 decimal system we are all so used to. 

Compared to the base-10 number system every digit in a binary number reflects 2 to some power. So 1010 will be (1 * 2^3 + 1 * 2^1) just as 304 is (3 * 10^2 + 4 * 10^0).

```c
1010 = 1 * 2^3 + 1 * 2^1 = 10
0110 = 1 * 2^2 + 1 * 2^1 = 5
```

### 2's complement system ###

2's complement is used to represent signed integers in binary. Why is this? Well we don't have a negative sign when everything is just 1's and 0's, so we need to think of another way to represent negative numbers.

Let's first start by explaining what each bit represents within 2's complement. Actually, every bit is the same except for the first bit which now represents the NEGATIVE value of the value of that bit.

```c
0101 = 4 + 1 = 5
1101 = -8 + 4 + 1 = -3
```

Looking closely, we see that the only difference in 2's complement is that the first binary digit represents a negative value now! 

A quick way to get the value of a 2's complement binary number is as follows.

	1. If given a 2's complement number with a leading 1 such as 1010 we will first flip every bit to get 0101

	2. Now evaluate the value of the resulting binary number normally i.e. 0101 = 5

	3. Now add 1 to that value i.e. 5 + 1 = 6, and make it negative i.e. 6 -> -6

A 2's complement number with a leading 0 should be evaluated the same as any other binary number.

### Hexadecimals ###

Hexidecimals is yet another common way of representing numbers. Except now it's base-16 and has letters to represent more digits!

Following the same layout as binary, we now have the following digit possibilites:
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A (equal to 10), B (equal to 11), C (equal to 12), D (equal to 13), E (equal to 14), F (equal to 15)

Each digit place now corresponds to 16 to some power i.e. AE = (10 * 16^1 + 14 * 16^0). Also it's really important to note that each hexidecimal digit corresponds to a 4 digit binary number!

```c
A = 1010 = 10
B = 1011 = 11
C = 1100 = 12
D = 1101 = 13
E = 1110 = 14
F = 1111 = 15
```

### Exercises ###

1. Evaluate the following

	a. 1001 in 2's complement

	b. 11111110 in 2's complement

	c. 0110 in 2's complement

2. What is the output of the following program?

```c
#include <stdio.h>

int main(int argc, char **argv) {
	int x = 0xffffffff;
	int y = 0xffffffff;
	printf("%d\n", x + y);
}
```

3. When I run make in my directory I get the following output.

```unix
 ˜/cs3157/lab1$ make 
    gcc -g -Wall    -c -o main.o main.c
    gcc -g -Wall    -c -o myadd.o myadd.c
    gcc -g  main.o myadd.o   -o main
```

The Makefile in that same directory is shown here, with the build rules
removed.  Fill in the missing lines, specifying targets and
dependencies that are consistent with the CLIC lab session shown
above.

Fill in only targets and dependencies.  That is, do not write the gcc
commands that come below the target/dependency lines.  Rely on the
implicit rules that make knows by default.

```make
    CC  = gcc
    CXX = g++
    INCLUDES =
    CFLAGS   = -g -Wall $(INCLUDES)
    CXXFLAGS = -g -Wall $(INCLUDES)
    LDFLAGS = -g
    LDLIBS =

    # Fill in the missing targets and dependencies here

    .PHONY: clean
    clean:
            rm -f *.o *˜ a.out core main
```