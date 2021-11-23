# lambda
**A lambda is an unnamed function object capable of capturing variables in scope. It features: a capture list;
  an optional set of parameters with an optional trailing return type; and a body. Examples of capture lists:**

**[]** - captures nothing.<br />
**[=]** - capture local objects (local variables, parameters) in scope by value.<br />
**[&]** - capture local objects (local variables, parameters) in scope by reference.<br />
**[this]** - capture this pointer by value.<br />
**[a, &b]** - capture objects a by value, b by reference.<br />

A lambda consists typically of three parts: a capture list [], an optional parameter list () and a body {}, all of which can be empty.

``` 
int x = 1;
auto getX = [=] { return x; };
getX(); // == 1 

auto addX = [=](int y) { return x + y; };
addX(1); // == 2

auto getXRef = [&]() -> int& { return x; };
getXRef(); // int& to `x`
By default, value-captures cannot be modified inside the lambda because the compiler-generated method is marked as const.
The mutable keyword allows modifying captured variables. The keyword is placed after the parameter-list 
(which must be present even if it is empty).

int x = 1;

auto f1 = [&x] { x = 2; }; // OK: x is a reference and modifies the original

auto f2 = [x] { x = 2; }; // ERROR: the lambda can only perform const-operations on the captured value
// vs.
auto f3 = [x]() mutable { x = 2; }; // OK: the lambda can perform any operations on the captured value ```


##Reference
https://thispointer.com/designing-callbacks-in-c-part-3-c11-lambda-functions/
