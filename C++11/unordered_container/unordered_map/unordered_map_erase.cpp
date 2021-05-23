/* ERASE ELEMENT FROM MAP */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
  unordered_map<int, string> myMap{ {1, "Tejas"}, {2, "Sonu"} };

  for (const auto& val : myMap)
    cout << val.first<<"---"<<val.second << endl;

  // erase id 1
  auto itr = myMap.find(1);
  myMap.erase(itr);

  for (const auto& val : myMap)
    cout << "After Erase: "<<val.first << "---" << val.second << endl;

  return 0;
}