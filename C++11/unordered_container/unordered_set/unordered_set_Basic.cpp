/* unordered_set is an STL container.
It provides a functionality of a Set i.e. it can contains the unique elements only.
unordered_set stores the elements internally using a Hash Table.*/
//----------------------------------------------------------------------------------------------------------
/* std::unordered_set<T> setOfTypeT;
   Elements of Type with which an unoredered_set is declared can only be added in it. Also, all elements of Type T should be,
          Copyable or Movable
          Comparable

Above requirements are because of the reason that element added in unordered_set will act as both key and value for internal Hash Table. 
As it’s a key therefore it should be comparable and copy-able.

Also, all elements in the unordered_set are immutable i.e. they can not be modified once inserted. 
They can only be deleted after the insertion.*/
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
  unordered_set<int> mySet;

  // insert
  mySet.insert(3);
  mySet.insert(2);
  mySet.insert(1);

  // don't take duplicate
  mySet.insert(3);

  for (const int& val : mySet)
    cout << val << endl;  // 3, 2, 1

  return 0;
}