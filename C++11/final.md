# final
* Sometimes you don’t want to allow derived class to override the base class’ virtual function.
C++ 11 allows built-in facility to prevent overriding of virtual function using final specifier.
Consider the following example which shows use of final specifier. This program fails in compilation.

// Example 1
```
#include <iostream>
using namespace std;

class A
{
  public:
  virtual void display() final
  {
     cout << "A" << endl;
  }
};

class B: public A
{
  public:
  void display()
  {
     cout << "B" << endl;
  }
};

int main()
{
  A* ptr = new B();
  ptr->display();
  delete ptr;
  return 0;
}
```

* final specifier in C++ 11 can also be used to prevent inheritance of class / struct. If a class or struct is marked as final then it becomes non inheritable
  and it cannot be used as base class/struct.

Example 2:

```
class A final
{

};

class B: public A
{
};

int main()
{
  B obj;
  return 0;
}
```
