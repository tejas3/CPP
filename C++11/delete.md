# delete


Suppose we have a class with a constructor taking an integer:

```
class A
{
public:
    A(int a){};
};
```

Then, the following three operations will be successful:

A a(10);     // OK
A b(3.14);   // OK  3.14 will be converted to 3
a = b;       // OK  We have a compiler generated assignment operator
However, what if that was not we wanted. We do not want the constructor allow double type parameter nor the assignment to work.

C++11 allows us to disable certain features by using delete:

```
class A
{
public:
    A(int a){};
    A(double) = delete;         // conversion disabled
    A& operator=(const A&) = delete;  // assignment operator disabled
};
```

Then, if we write the code as below:

A a(10);     // OK
A b(3.14);   // Error: conversion from double to int disabled
a = b;       // Error: assignment operator disabled
