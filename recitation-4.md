# Recitation 4 #

## 'Git' er Done ##

### What's git? ###

Git is a distributed revision control and source code management system with an emphasis on speed.
    
### Make a Data Structures Directory ###

If you haven't already, please make a 3136 directory on your clic account with the following command in your home directory:

    mkdir cs3136
    
Set the permission to 700 with the command:

    chmod cs3136 700
    
Set up the command line email configuration with the command:

    cp /home/jae/cs3136-pub/conf/.muttrc ./

Change into the directory with the command:

    cd cs3136
    
### Configuring git ###

So in order to use git, you must first let it know who you are.  Do this by telling git your name and email:

    git config --global user.name "First Last" 
    git config --global user.email fml1234@columbia.edu

Now, put the directory under git revision control with the command:

    git init

### Repositories and Retrieving Assignments ###

A git repository is a place to store fun stuff like code, projects, and in our case recitation notes, homework skeleton code, or homework solutions for you!  Github.com is a website where users make repositories to share and update code with one another.

Once Jae has added the skeleton code for your assignment, you will be able to clone his skeleton code from his repository with the following command from within the cs3136 directory:

    git clone /home/jae/cs3136-pub/lab1 lab1
    
Once the labs have all been submitted, Jae will post the solutions to his repository.  You can retrieve them with the command:

    git pull
    
from with in the lab1 subdirectory. Here you are literally "pulling" all of the changes Jae has made to his git directory.

### The 4 levels of Commitment ###

A file in a directory under git revision control is part of one of four "levels of commitment".  They are:

    untracked
    tracked and unmodified
    tracked, modified, and unstaged
    tracked, modified, and staged

You can check the level of commitment of the files in a directory under git revision control with the command:

    git status

An untracked file is a file that is not being watched for modifications by git revision control.
To track a file, enter the following command:

    git add filename

Keep in mind that you only want to be tracking files that you will be editing again or submitting.  For most programming labs in this course, it will include the .h, .c, Makefile and README.txt files in the directory.  The executable and .o files need not be tracked.

A tracked and unmodified is a file that has been tracked and not modified since its inception or since the last commit.

A tracked, modified, and unstaged file is a file that had been tracked, edited since the last commit, but not staged for commit since the last commit.
To stage the file for commit, again enter the command:

    git add filename

A tracked, modified, and staged file is a file that has been tracked, edited since the last commit, and stage for commit.

### Committing Changes ###

To commit changes to your files that are tracked, modified, and staged, enter the command:

    git commit -m "a message with notes about the commit"
    
from your lab1 directory.
To see your detailed commit history, enter the command:

    git log -p --color

### Submitting labs ###

You can submit a lab with the submit-lab script:

    /home/w3136/submit/submit-lab  lab1

from the lab1 directory.

### More useful git ###

It is a good idea to commit often! One reason is that if you make a mistake and accidentally deleted files or made a bad modification then you can revert to an earlier commit. This and more can be done with git tricks like below.

(a) If you want to unmodify a file that you changed for the worse, you can checkout the file from your last commit. In example

    git add README.txt
    git commit -m "I spent forever on this README"
    rm -f README.txt

OH NO!! Evil friend removed my awesome README.txt. Good thing I use git.

    git checkout README.txt

And now you have your README.txt back to where it was when you last committed it.

(b) Stage all files in directory with
    
    git add ./

(c) I accidentally added in the *.o object files to be staged. What do I do?

    git reset *.o 

## Lab 1 ##

(a) Writing selection sort code and create a Makefile for the relevant code.

In a nutshell, your selection sort should do the following.

```
Given an array you will loop through each element. 
Find the minimum element seen past the element you are at in the loop.
Replace the element you are at in the loop with the minimum found.
```

Be sure to look back at Jae's code if you are stuck. For the Makefile, I highly encourage you to use the example one used by Jae (refer to recitation #2 for Makefile explanations).

(b) Write merge() function for mergesort().

```c
/*
 * Merge-sort an array a, which contains n elements.
 */
void merge_sort(char a[], int n)
{
    // BASIS: if a has only 1 element, there is nothing to do.
    if (n <= 1) {
        return;
    }

    // INDUCTION: merge_sort the 1st half and merge_sort the 2nd half 
    // so that we have 2 half-size sorted arrays, and then merge them 
    // into a single sorted list.

    int m = n / 2;

    // merge_sort the 1st m elements of a
    merge_sort(a, m);

    // merge_sort the remaining n - m elements of the array "a + m",
    // which is a way to take a sub-array of "a" where a[m] is the new 
    // 0th element (i.e., (a+m)[0] is the same as a[m]).
    merge_sort(a + m, n - m);

    // allocated a temporary array into which the merge function will 
    // put the merged array.
    char temp[n];

    // merge a (for which we are looking at only the 1st m elements)
    // and a+m (which has n-m elements from (a+m)[0] to (a+m)[n-m-1],
    //          which are really the same as a[m] to a[n-1])
    // into the temp array.
    merge(a, m, a + m, n - m, temp);

    // copy the temp array back into a.
    int i;
    for (i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}
```
A mergesort() function has 3 sections

    a base case (an array of 1 or 0 elements is already sorted)
    a split step (split unsorted array into two unsorted arrays)
    call mergesort() on both unsorted sub arrays step
    a merge() step (merges the now sorted sub arrays into one array)
    (in our example, we have a 5th step, setting the values of array a to the values of the sorted array temp)

You will only be coding up the merge() step which is in fact not recursive. The basis for merge() is explained below in my own pseudocode. *Note merge() is such a common function that you can find pseudocode for it everywhere online. (but the below should be sufficient)

```c
define function merge (array1, array2) {
    array1_index = 0
    array2_index = 0
    return_array = array of size (array1.size + array2.size)

    for i from (0, return_array.size) {
        if array1_index >= array1.size {
            return_array[i] = array2[array2_index++]
            continue on with loop
        }
        if array2_index >= array2.size {
            return_array[i] = array2[array2_index++]
            continue on with loop
        }
        return_array[i] = lesser of array1[array1_index] and array2[array2_index]
        increment index of lesser of array1[array1_index] and array2[array2_index]
    }

    return return_array
}
```
    
Merge() is actually exactly what you would reasonably do if you were given two sorted decks and asked to combine it into one sorted deck.

(c) Add a print stack trace to mergesort_main.c

The main trick to this part is understanding where to put each distinct print statement and how to keep track of indentation. It is a lot easier if you use Jae's already included print_array() function to print the array, and you may decide to use multiple printf statements to get a single line to print out.

## Pointers ##

### What's a pointer anyway? ###

A pointer is a data type whose value is an address in memory.  The value "points" to another value stored in that memory location.

Here is an example of a declaration of a pointer c which points to a char.
```c
    char *c;
```
The * in the declaration lets us know that we are working with a pointer.
The data type before the * indicates the data type or structure that the pointer points to.

We also use a * when accessing the data that the pointer points to.
```c
    char b;
    b = *c;
```
Here, b would take on the value on what ever was pointed to by the char pointer c.

To access the address of a variable, we use an &.
```c
    int x = 5;
    int *y;
    y = &5;
```    
This tells y to point to the address of the int x.

### I still don't get it ###

Legendary Professor Alfred Aho once compared data types to people and pointers to where they live. Hopefully the analogy will make pointers easier to understand for you as well!

Imagine that I have a person named Joe who is represented by an int. Let's say his value is 13.

```c
    int person = 13;
```

He lives somewhere (in this case in your computer) and you can ask him for his address in the computer (just like you could ask a person his home address) and store it somewhere. *Note we use & to ask a variable for its address.

```c
    int *persons_address = &person;
```

It's been a while and I want to vist Joe again and see how he's doing. Good thing I have his address.

```c
    printf("%d", *persons_address);
```

*Note that here we use * to travel to a pointers address and get the contents. It's kind of like traveling to Joe's house and asking for him.
    
And that's pointers in a nutshell.

### Pointer Example ###

What do you think will be printed in the following example?
```c
#include <stdio.h>

int main(int argc, char **argv)
{
    int i,j;
    int *x;
    int *y;
    char a,b;
    char *k;

    i = 7;
    j = 97;
    x = i;
    y = &j;
    a = 'a';
    *k = a;
    b = *k;
    a = 'c';
    a = (char)j;

    if (a == b)
    {
        printf("a and b are equal!\n");
    }

    printf("i equals %d\n", i);
    printf("j equals %d\n", j);
    printf("the value stored in y equals %d\n", *y);
    printf("a equals %c\n", a);
    printf("b equals %c\n", b);
    printf("the value stored in k equals %c\n", *k);
    printf("the value of x equals %d\n", x);
    printf("the value stored in x equals %d\n", *x);

    return 0;
}
```
