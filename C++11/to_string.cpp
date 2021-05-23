
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// basic template function
template <typename T>
void display(const T& val)
{
  cout << val << endl;
}

// implementing to_string class
template <typename T>
string to_string_impl(const T& str)
{
  stringstream ss;
  ss << str;
  return ss.str();
}

int main()
{
  display(1);
  display("Hello");
  display(2.3);

  cout << to_string_impl(2) << endl;

  return 0;
}
