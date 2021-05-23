/* Find element in unordered_set usimg find method */

/*Searches the container for an element with n as value and returns an iterator to it if found,
otherwise it returns an iterator to unordered_set::end(the element past the end of the container).

All iterators in an unordered_set have const access to the elements(even those whose type is not prefixed with const_) :
Elements can be inserted or removed, but not modified while in the container*/

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
  unordered_set<int> mySet{1, 3, 5, 3, 7, 9, 20};
  auto itr = mySet.find(3);

  if (itr != mySet.end())
    cout << "Found";

  itr = mySet.find(15);
  if (itr != mySet.end())
    cout << "Not Found";

  return 0;
}