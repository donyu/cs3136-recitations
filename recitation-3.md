# Recitation 3 #

## More C Data Types ##

### Booleans ###

There is no special boolean type in C, and as a result integers serve as booleans. For example, let's look at this `if ... else ...` statement.

```c
int i = 10;
if (i) {
  printf("true!\n");
}
else {
  printf("false!\n");
}
```

This will print out `"true!"` for any value of `i` other than zero.

### More about `char`s ###

It's important for us to think about what we're representing when we store a value in a `char`. The character we store does not equal the underlying integer value. `\`1\` != 1`, and equally, `\`0\` != 0`. Let's look at an example.

```c
int i = 97;
char j = (char) i;
printf("value of i: %d\n", i); // %d prints ints
printf("value of j: %c\n", j); // %c prints chars
```

First, the notation `(char)` means "cast the `int` 5 as a `char`" or convert a variable of one type to another type. You can safetly perform this action if you are converting from smaller to larger data types since we know there will be room for all the bits in the original variable. However, when casting from a larger data type to a smaller one, you have to be careful or else you'll lose information.

Now, what does this program do? It print's out two lines:

    value of i: 97
    value of j: a

Huh? What just happened? We are seeing the difference between the underlying value of `j` and the character that that value signifies. So now we know that in ASCII (a character encoding), 97 = a.

### Arrays ###

All an array is a fixed size list of a particular type. We can have an array of `int`s just as easily as an array of `floats`.

Arrays are delcared by writing `int my_array[10]`. We then can assign `int`s to any slot in the array by writing `my_array[6] = 10`.

In java or python when you declare an array all the elements of the array are set to some default value, for an `int` array it would be zero. However, in C depending on how you declare the array there could be different values in the array. If you declared the array `static` then you can safetly assume only zeros in an `int` array. On the other hand, if you declare the array on the stack or heap (more about this later) you can't assume anything about the values in the array and have to treat them as garbage until you modify them.

There is a nice sytax to set the contents of the array on initialization. You can intialize all elements to `0` by writing:

    int my_array[10] = { 0 };

Also, if you want to set some elements to specific values you can write:

```c
int my_array[10] = { 1, 2, 3 } // the first three elements will be set to 1, 2, 3 respectively
                               // and the rest will be set to 0 
```

### Strings, or lack thereof ###

C is an interesting language in that there is no built-in data type for strings. But, that doesn't stop us, we can just represent a string as an array of `char`s terminated by the `NULL` character. It would be a little cumbersome to have to work with strings as an array, so once we learn about pointers in more detail we'll discuss special string syntax and how to use them.

### Automatic Variables ###

Automatic variables are variables that have a scope of a block, like local variables in Java.

### Static Variables ###

Static variables are useful when you would like to be able to access a variable in a certain scope during the entire lifetime of a program.
As mentioned in the class notes, the scope of a static variable depends on where it is declared (global, file, or block).

A static variable would come in handy in a bank account program to ensure that every account number was unique:

```c
int getNewAccountNumber()
{
  static int acctCount = 0; // acctCount is declared and defined as 0 the first time the function is called
  acctCount++;
  return acctCount;
}
```
### Recursion ###

In recursive programming, a function calls upon itself.
Typically, a recursive function consists of a base case(s) and recursive steps.

The fibonacci sequence is a sequence of numbers where the 0th number is 0, the first number is 1, and every number after that is equal to the sum of the previous two.
The following recursive function can be used to obtain the nth number of the fibonacci sequence:

```c
int getFib(int n)
{
   if (n == 0)         // base case 1
      return 0;
   else if (n == 1)    // base case 2
      return 1;
   else                // recursive step
      return (getFib(n-1) + Fibonacci(n-2));
} 
```
Bonus: Now that you've learned about arrays, can you think of another way to implement the recursive getFib() function with a faster runtime?

