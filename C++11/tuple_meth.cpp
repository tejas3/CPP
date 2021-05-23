/* Tuples are fixed size collection of hetrogenous values */
/* can returns multiple values from function using tuple */

#include <iostream>
#include <tuple>

using namespace std;

int main()
{
  auto values = make_tuple(1, "T", "IN", "123456789");
  auto x1 = get<0>(values);
  auto x2 = get<1>(values);
  auto x3 = get<2>(values);
  auto x4 = get<3>(values);

  return 0;
}