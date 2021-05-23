# constexpr
* compute expressions at compile time

* constexpr: 
They serve different purposes. constexpr is mainly for optimization while const is for practically const objects like value of Pi.
Both of them can be applied to member methods. Member methods are made const to make sure that there are no accidental changes
by the method. 
On the other hand, the idea of using constexpr is to compute expressions at compile time so that time can be saved when code is run.

```
#include<iostream> 
using namespace std; 
  
constexpr long int fib(int n) 
{ 
    return (n <= 1)? n : fib(n-1) + fib(n-2); 
} 
  
int main () 
{ 
    // value of res is computed at compile time.  
    const long int res = fib(30); 
    cout << res; 
    return 0; 
} 
```

* constexpr vs inline functions: 
Both are for performance improvements, inline functions are request to compiler to expand at compile time and save time of function call
overheads. 
In inline functions, expressions are always evaluated at run time. constexpr is different, here expressions are evaluated at compile time.

```
class Rectangle 
{ 
    int _h, _w; 
public: 
    // A constexpr constructor 
    constexpr Rectangle (int h, int w) : _h(h), _w(w) {} 
      
    constexpr int getArea ()  {   return _h * _w; } 
}; 
  
//  driver program to test function 
int main() 
{ 
    // Below object is initialized at compile time 
    constexpr Rectangle obj(10, 20); 
    cout << obj.getArea(); 
    return 0; 
} 
```
