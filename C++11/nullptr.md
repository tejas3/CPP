# C++11 introduces a new null pointer type designed to replace C's NULL macro. 
# nullptr itself is of type std::nullptr_t and can be implicitly converted into pointer types

```
void foo(int);
void foo(char*);
foo(NULL); // error -- ambiguous
foo(nullptr); // calls foo(char*)
```
