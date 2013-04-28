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
Remember making our linked list in hw 2?  Here's what would happen if we modified Jae's stack code
and used a list container instead of a deque container to write it in c++:
```c
/*
 * list.h
 */

#ifndef __LIST_H__
#define __LIST_H__

#include <list>
#include <algorithm>
#include <iostream>

 using namespace std;

template <typename T>
class List;
template <typename T>
ostream& operator<<(ostream& os, const List<T>& rhs);


template <typename T>
class List
{
    public:
    bool empty() const { return q.empty(); }
    void addFront(const T& t) { q.push_front(t); }
    T removeEnd();
    void reverse();
    void sortList();
    friend ostream& operator<< <T>(ostream& os, const List<T>& rhs);
  private:
    list<T> q;
};

template <typename T>
T List<T>::removeEnd()
{
    T t = q.back();
    q.pop_back();
    return t;
}
template <typename T>
void List<T>::reverse()
{
    ::reverse(q.begin(), q.end());
}

template <typename T>
void List<T>::sortList()
{
	q.sort(); //note, T must have comp function
}

template <typename T>
ostream& operator<<(ostream& os, const List<T>& rhs)
{
    os << "[ ";
    typename list<T>::const_iterator i;
    for (i = rhs.q.begin(); i != rhs.q.end(); ++i)
        os << *i << " ";
    os << "]";
return os; }

#endif

/*
 * test.cpp
 */
#include "list.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    List<string> myList;
	myList.addFront("hey");
	myList.addFront("there");
	myList.addFront("class");
	cout << myList << endl;
	myList.sortList();
	cout << myList << endl;
	myList.reverse();
	cout << myList << endl;
	while (!myList.empty())
	{
		myList.removeEnd();
	}
	cout << myList << endl;
	return 0;
}
```
### Using sort ###
In order for the above to work, the class T must have a built-in comp method.  In our case, the string class has
one.  The comp method should return true when the first element being compared is less than or equal to the second 
element being compared.
