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


### Review ###
#### Declaration vs. Definition ####
A declaration tells the compiler the name and type/return type of a variable/function/class
which is defined somewhere else.  For our purposes, the definition could be somewhere else in 
the same file or in a .c file of the same name.

The definition defines. Simple as that.  Defining could happen in the assignment of a variable or
in the associated body of a function, struct, or class.

#### Stack vs. Heap allocations ####
Stack allocations go away after the scope of the function has passed.  Heap allocations persist
beyond the scope of the function.
```c
struct Pt {
  int x;
  int y;
};
In C:
        // stack allocation
        struct Pt p1;
        // p1 goes away at the end of its scope
        // heap allocation
        struct Pt *p2 = malloc(sizeof(struct Pt));
        ...
        free(p2);
In C++:
        // stack allocation
        struct Pt p3(0,0);
        // p3 gets destructed at the end of its scope
        // heap allocation
        struct Pt *p4 = new Pt(0,0);
        ...
        delete p4;
```
#### Pass by.... ####
##### Pass by value #####
Available in both c and c++
```c
  f(struct Pt p)
```
##### Pass by pointer #####
Available in both c and c++
```c
  f(struct Pt *p)
```
##### Pass by reference #####
Available only in c++
```c
  f(struct Pt &p)
```


### C++ Basic 4 ###
Four functions that make up the core of any class.  If you do not write them, the compiler will generate them
and they may not do what you want!  I will write them as they appear in our MyString class.
Our MyString class has two private variables: char *data and int len.
#### The Constructor ####
Initialize all variables of class.  No return type.  Can take any number of arguments to initialize the variables.
```c
// In mystring.h:
        // default constructor.  Has no arguments.
        MyString();
        // constructor 1.  Takes in a char * to be assigned to data
        MyString(const char* p);
        
// In mystring.cpp
  // default constructor.  Allocate memory for empty string (just '\0' char).
  MyString::MyString()
  {
      data = new char[1];
      data[0] = '\0';
      len = 0;
  }
  // constructor 1
  MyString::MyString(const char* p)
  {
     if (p) {
          len = strlen(p);
         data = new char[len+1];
         strcpy(data, p);
     } else {
         data = new char[1];
         data[0] = '\0';
         len = 0;
     }
  }
```
#### The Destructor ####
Deallocates all memory allocated in the construction of the object.
Should be a mirror image of sorts of the constructor.
```c
// In mystring.h:
  ~MyString();
  
// In mystring.cpp:
  MyString::~MyString()
  {
    delete[] data; deallocate memory allocated in the constructor.
  }
```
#### Copy Constructor ####
The copy constructor is called automatically in certain situations.
It is called when an object is returned by value.
It is also called when an object is passed into a function by value.
```c
// In mystring.h:
  MyString(const MyString& s);

// In mystring.cpp:
  MyString::MyString(const MyString& s)
  {
    len = s.len;
    data = new char[len+1];
    strcpy(data, s.data);
  }
```
#### Assignment Operator ####
Called in assignment operations.
```c
// In mystring.h:
  MyString& operator=(const MyString& s);

// In mystring.cpp:
  MyString& MyString::operator=(const MyString& rhs)
  {
    if (this == &rhs) {
        return *this;
    }
    // first, deallocate memory that 'this' used to hold
    delete[] data;
    // now copy from rhs
    len = rhs.len;
    data = new char[len+1];
    strcpy(data, rhs.data);
    return *this;
  }
```
