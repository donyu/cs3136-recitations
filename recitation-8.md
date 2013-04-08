# Recitation 8 #

## Lab 3 ##

### Part 1 ###

BASIC4TRACE: (0xbffff9a0)->MyString(const char *)

0xbffff9a0 = memory address of variable   
MyString(const char *) = basic 4 function called

### Part 2 ###

int strcmp(const char *s1, const char *s2);

returns an integer greater than 0 if s1 > s2, less than 0 if s1 < s2, or equal to 0 if s1 == s2

### Friend Functions ###

In order for a method to access your private parts, it must be declared as a friend function under your class declaration.

Would you let someone you didn't explicitly list as your friend touch your private parts?

So now there are 2 ways to be able to touch or modify an Objects private parts (at least for the purposes of this class).

1. Member functions (you can always touch your own privates)
2. friend functions (she's my "friend" so it's okay)

Example

```c

  class Dog {
    public:
      Dog();
      Dog(int m) { this->m = m; }
      friend int friend_dog(const Dog& d1, const Dog& d2);
    private:
      int m;
  };

  int not_friend(const Dog& d1, const Dog& d2) {
    return d1.m + d2.m;
  }

  int friend_dog(const Dog& d1, const Dog& d2) {
    return d1.m + d2.m;
  }
```

## Practice Time ##

1. Consider a C++ program, jaes-club.cpp:

```c
  #include <iostream>
  #include <string>
  #include "mystring.h"
  using namespace std;

  // possibilities will go here

  int main(int argc, char **argv)
  {
    MyString s("jae");
    cout << *(f(s)) << endl;
    return 0;
  }
```

For each of the following questions, determine if it is one of the 
following results and write out the output of the program if it is GOOD. You do not have to write any output if the program is broken or bad.

- GOOD: The program runs valgrind-clean
- BAD: Valgrind repors memory error or leak
- BROKEN: Does not compile

a)  

```c
  MyString *f(MyString &s) {
    MyString *p = new MyString(s);
    return p;
  }
```

b)  

```c
  MyString *f(MyString s) {
    MyString p(s);
    return &p;  
  }
```

c)  

```c
    MyString *f(MyString s) {
    MyString *p = new MyString(s);
    return p;
    delete p;
  }
```

Consider another C++ program, dons-club.cpp:

```c
  #include <iostream>
  #include <string>
  #include "mystring.h"
  using namespace std;

  // possibilities will go here

  int main(int argc, char **argv)
  {
    MyString s("jae");
    cout << f(s) << endl;
    return 0;
  }
```

For each of the following questions, determine if it is one of the 
following results and write out the output of the program if it is GOOD. You do not have to write any output if the program is broken or bad.

- GOOD: The program runs valgrind-clean
- BAD: Valgrind repors memory error or leak
- BROKEN: Does not compile

d)  
```c
  class Mystery {
    public:
      Mystery();
      Mystery(int m) { this->m = m; }
      int mystery(const Mystery& m1, const Mystery& m2);
    private:
      int m;
  };

  int mystery(const Mystery& m1, const Mystery& m2) {
    return m1.m + m2.m;
  }

  MyString f(MyString &s) {
    Mystery m(3);
    Mystery t(2);
    if (mystery(m, t) == 5) {
      return MyString("hi there");
    }
    return s;
  }
```