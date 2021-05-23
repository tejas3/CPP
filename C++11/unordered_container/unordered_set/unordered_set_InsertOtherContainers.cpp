/* Initialize un*_set with array, vector and Initializer List */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  // with array
  int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 9, 10};
  unordered_set<int> mySet{ arr, arr + (sizeof(arr) / sizeof(int)) };

  for (const int& val : mySet)
    cout << val << endl;  // 9, 1, 10, 2, 3, 4, 5

  // sort(mySet.begin(), mySet.end()); 
      // unordered containers store internally hashed data and thus it's not possible to order them after the hash has been generated.

  // If want to sort data then use store unordered_set data into vector(non-hashed container) then perform sort(..) or set(non-hashed container)

  //-------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------


  // insert vector into un*_set
  vector<string> myVec{"tron", "geek", "drum"};
  unordered_set<string> mySet2{ myVec.begin(), myVec.end()};

  for (const string& val : mySet2)
    cout << val << endl;  //

  return 0;
}