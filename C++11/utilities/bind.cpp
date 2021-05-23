/*
**std::bind**
It is a function object that acts as a function adapter.
It takes function as an input and returns function object as an output.

for example:
*/

#include <iostream>
#include <functional>    // required for bind

using namespace std;

int sum(int x, int y)
{
  return x + y;
}

int main()
{

  auto add_sum = std::bind(&sum, std::placeholders::_1, std::placeholders::_2);

  int x = add_sum(2, 4);

  cout << x;

  // keeping first argument as fix
  auto add_sum1 = std::bind(&sum, 12, std::placeholders::_1);

  int y = add_sum1(4);

  cout << y;

  return 0;
}