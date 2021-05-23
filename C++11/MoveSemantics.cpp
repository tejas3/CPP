// Move Semantics

/* eliminate many unnecessary copy operations, thereby improving performance significantly */

#include <iostream>
#include <string>

using namespace std;


//---------------------------------------------------------------------------------------------------------------
string create()
{
  string s("Hello");
  return s;
}

int main()
{
  string str = create(); // temporary object, copy constructor get called, not efficicent at all
}

//--------------------------------------------------------------------------------------------------------------


class A
{
};

// in c++11 will get 6 methods by default
 /* 
  1. Constructor
  2. Destructor
  3  Copy Constr
  4  Copy assignment operator
  5  Move Constructor
  6  Move assignment operator
 */