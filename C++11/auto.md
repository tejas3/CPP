# auto-typed variables are deduced by the compiler according to the type of their initializer.
* auto a = 3.14; // double
* auto b = 1; // int
* auto& c = b; // int&
* auto d = { 0 }; // std::initializer_list<int>
* auto&& e = 1; // int&&
* auto&& f = b; // int&
* auto g = new auto(123); // int*
* const auto h = 1; // const int
* auto i = 1, j = 2, k = 3; // int, int, int
* auto l = 1, m = true, n = 1.61; // error -- `l` deduced to be int, `m` is bool
* auto o; // error -- `o` requires initializer


# Extremely useful for readability, especially for complicated types:
* std::vector<int> v = ...;
* std::vector<int>::const_iterator cit = v.cbegin();
  // vs.
* auto cit = v.cbegin();

# Functions can also deduce the return type using auto. In C++11, a return type must be specified either explicitly, 
# or using decltype like so:

```
template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) 
{
  return x + y;
}
add(1, 2); // == 3
add(1, 2.0); // == 3.0
add(1.5, 1.5); // == 3.0
```
# Range based for-loops
```
#include <iostream>
#include <vector>
 
int main() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5};
 
    for (auto i : v) // access by value, the type of i is int
        std::cout << i << ' ';
    std::cout << '\n'; 
}


# NOTE

The auto keyword can’t be used with function parameters

```
void addAndPrint(auto x, auto y)
{
    std::cout << x + y;
}
```

