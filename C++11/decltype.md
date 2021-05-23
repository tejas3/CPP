# decltype

* Inspects the declared type of an entity or the type of an expression.


```
int a = 1; // `a` is declared as type `int`
decltype(a) b = a; // `decltype(a)` is `int`
const int& c = a; // `c` is declared as type `const int&`
decltype(c) d = a; // `decltype(c)` is `const int&`
decltype(123) e = 123; // `decltype(123)` is `int`
int&& f = 1; // `f` is declared as type `int&&`
decltype(f) g = 1; // `decltype(f) is `int&&`
decltype((a)) h = g; // `decltype((a))` is int&
template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) {
  return x + y;
}
add(1, 2.0); // `decltype(x + y)` => `decltype(3.0)` => `double`
```

# Example

```
#include <iostream> 
using namespace std; 
  
int fun1() { return 10; } 
  
int main() 
{ 
    decltype(fun1()) x;  // x will become int type
    cout << typeid(x).name() << endl; 
  
    return 0; 
}
```
