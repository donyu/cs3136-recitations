# Recitation 11 #

## Iterators ##

### What are iterators? ###
A generalization of pointers for containers.
An iterator can behave like a pointer (++it, *it) and can sometimes ACTUALLY be a pointer as seen with the vector case.
When we deal with the list container, we can see how it would be more complicated.
Therefore, iterators must be “type members” (a typedef defined inside a class).

### Difference btwn iterator and const_iterator ###
Dereferencing an iterator gives you a T&, and dereferencing a
    const_iterator gives you a const T&.

### Iterators and Container Algorithms ###
The standard C++ library provides many useful template functions that
implement common algorithms such as sorting, finding an element,
reversing container contents, etc.

### Linked List Example ###
Remember making our linked list in hw 2?  Let’s make one using the list container!
