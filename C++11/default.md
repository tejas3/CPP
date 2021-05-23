# default

* If a class is defined with any constructors, the compiler will not generate a default constructor.
  This is useful in many cases, but it is some times vexing. 
  For example, we defined the class as below:

```
class A
{
public:
    A(int a){};
};

```
Then, if we do:

A a;

The compiler complains that we have no default constructor. That's because compiler did not make the one for us because we've already had one that we defined.

We can force the compiler make the one for us by using default specifier:

```
class A
{
public:
    A(int a){};
    A() = default;
};
```
Then, compiler won't complain for this any more:

A a;

NOTE: add default move constr and move assignment operator
