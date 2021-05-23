/* array container */

#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
  array<int, 5> arr = { 1,2,3,4,5 };

  sort(arr.begin(), arr.end());

  for (auto& x : arr)
  {
    x = x * 2;
    cout << x << endl;
  }    // 2, 4, 6, 8, 10

  cout << arr.size() << endl;  // 5
  cout << arr.max_size() << endl; // 5
  cout << *(arr.data()) << endl; // 2 first element


  arr.assign(15);  //all become 15


  for (auto& x : arr)
  {
    cout << x << endl;
  }  // 15, 15, 15, 15, 15

  return 0;
}