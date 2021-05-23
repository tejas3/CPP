# Performance benefits
**Reason 1**:
* Move semantics is way to optimize copying. 
Sometimes copying is obviously wasteful. If you’re copying from a temporary string object, 
simply copying the pointer to the character buffer would be much more efficient than creating a new buffer and copying the character. 
It would work because the source object is about to go out of scope.

* Move semantics provide this mechanism by allowing you to have a move constructor and a move assignment operator
in addition to the copy operations.

* By implementing move semantics in your own classes you can get additional performance improvements,
for example when you store them in STL containers.
Also, keep in mind that move semantics can be applied not only to constructors, but also to methods (such as vector’s push_back).


**Reason 2**:
* The hash tables which have now become standard provide faster insertion, deletion and lookup than their ordered counterparts, 
which can be very useful when handling large amounts of data. 
You now have unordered_map, unordered_multimap, unordered_set and unordered_multiset at your disposal.


# Improve your productivity
**Reson 3**: 
* It’s not all about the performance of your code though. Developer time is valuable too, 
and C++11 can make you more productive by making your code shorter, clearer and easier to read.

* Before C++11:
vector<vector<MyType>>::const_iterator it = v.begin();

* After C++11:
auto it = v.cbegin(); // will return a const_iterator unconditionally.

**Reson 4**:
* Lambda provides several helpers to create nameless functions. Code is written where it should be executed, 
without needing to be wrapped in a function and without having to call a function explicitly.
