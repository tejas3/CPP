/* Move() is used to move one object to another without a copy */

#include <iostream>
#include <memory> // for unique pointer

using namespace std;

template<typename T>
typename remove_reference<T>::type&& move1(T&& arg)
{
  return static_cast<typename remove_reference<T>::type&&>(arg);
}

int main()
{
  unique_ptr<int> p1{ new int(10) };
  unique_ptr<int> p2 = move1(p1);
  cout << p2.get() << endl;
}