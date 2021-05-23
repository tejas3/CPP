/* UNORDERED MAP */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
  unordered_map<int, string> myMap;
  myMap.insert(make_pair(1, "Tejas"));
  myMap.insert(make_pair(2, "Sonu"));
  myMap.insert(make_pair(3, "Deepak"));
  myMap.insert(make_pair(4, "Suyog"));

  // equivalent to
  myMap.insert({ 4, "Suyog"});

  // if want to override
  //myMap.insert(make_pair(1, "Jay"));  will not override Jay in this case, here this checks ID 1 which is already exists so it will not insert, so not update value as well
  myMap[1] = "Jay"; // override Jay

  for (const auto& val : myMap)
    cout << val.first << "----" << val.second << endl;


  // Initialize map
  unordered_map<int, string> myMap1 = { { 1, "Tejas" },{ 2, "Sonu" },{ 3, "Deepak" } };
  cout << myMap1.size();

  return 0;
}


/*
**Advantage**:
The basic advantage of using unordered_map instead of associative map is the searching efficiency.
In an unordered_map complexity to search for an element is O(1) if hash code are chosen efficiently.
*/