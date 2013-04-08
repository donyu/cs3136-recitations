# Recitation 8 #

## Lab 3 ##

BASIC4TRACE: (0xbffff9a0)->MyString(const char *)

0xbffff9a0 = memory address of variable   
MyString(const char *) = basic 4 function called



## Practice Time ##

1. Consider a C++ program, jaes-club.cpp:

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

For each of the following questions, determine if it is one of the 
following results and write out the output of the program if it is GOOD. You do not have to write any output if the program is broken or bad.

- GOOD: The program runs valgrind-clean
- BAD: Valgrind repors memory error or leak
- BROKEN: Does not compile

a)  MyString *f(MyString &s) {
    MyString *p = new MyString(s);
    return p;
  }

b)  MyString *f(MyString s) {
    MyString p(s);
    return &p;  
  }

c)  MyString *f(MyString s) {
    MyString *p = new MyString(s);
    return p;
    delete p;
  }

Consider another C++ program, dons-club.cpp:

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

For each of the following questions, determine if it is one of the 
following results and write out the output of the program if it is GOOD. You do not have to write any output if the program is broken or bad.

- GOOD: The program runs valgrind-clean
- BAD: Valgrind repors memory error or leak
- BROKEN: Does not compile

d)  class Mystery {
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