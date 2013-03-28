# Recitation 7 #

## C++ ##

### What's so cool about C++ anyway? ###
```
  1. Object Oriented (like JAVA!)
    a) We can create our own data types with classes!
    b) Variables and functions can be polymorphic and we can use inheritance when creating classes.
  2. Use templates to for more generic programming!
  3. Built-in Goodies
    a) containers like list, vector, que
    b) functions like qsort (which you already had, but there's more good stuff like that)
  4. A STRING CLASS!!!!
```
### String in C ###
#### Allocated on stack ####
```c
char buf[100]
```
#### Allocated on heap ####
```c
char *buf = (char *)malloc(100)
```
#### Using as struct ####
```c
typedef struct {
  char *s;
  int len;
} String;
String *buf = allocString("hello");
```
#### What we want: ####
```c
String s = "hello";
```
