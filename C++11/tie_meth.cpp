/* packing/unpacking tuple using tie */

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main()
{
  auto values = make_tuple(1, "T", "IN", "123456789"); // packing

  int x;
  string y;

  tie(x, y, ignore, ignore) = values;  // unpacking tuple into variables, use std::ignore keyword if you dont want to catch values

  cout << x;
  cout << y;
  
  
  //************************************************//
  std::string yes, no;
  std::tie(yes, no) = std::make_pair("yes", "no");

  cout << yes;
  cout << no;
  
  return 0;
}