// Rvalue reference
/* RValue is mainly used for Moving semantics and perfect forwarding

What is rvalue and lvalue reference?
int x = 10;  // x is lvalue
int&y = x;  // y is lvalue reference
int&& z; // rvalue reference
*/

#include <iostream>
using namespace std;


void display(int& x)
{
  cout << x << endl;
}


void display(int&& y)
{
  cout << y << endl;
}

// commenting this funtion otherwise compiler get confuse which one to call, so do not overload this function when we have rvalue or lvalue function
//void display(int z)
//{
//  cout << z << endl;
//}

int main()
{
  int z = 10;

  display(z); // call lvalue ref
  display(12); // call rvalue ref

}