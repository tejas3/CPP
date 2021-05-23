/*
When Inserting into unordered_set: two things happens:
 1]---It calls the hasher function on passed element and compute the hash code.
   ---Now on the basis of this hash code it selects the appropriate bucket for the element.

 2]---Then compares the passed element with all the elements in bucket to check if similar element is already present, 
      if not then stores the element into the bucket.
*/

/*
std::hash<T>() Hasher
std::equal_to<T> Comparator
*/

/*
Therefore, If two elements are equal then there hashcode should always be same. Otherwise it will impossible to search for correct element in unordered_set.
*/

/*
While declaring an unordered_set we provides the type of element that can be stored in set. 
Along with that we can also provide the type of custom hasher and comparison functions.
*/


#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

// custom comparator
// depending on hash it compares two string
struct equalLength
{
  bool operator()(const string& str1, const string& str2) const
  {
    cout << str1 << " " << str2 << endl;
    if (str1.length() == str2.length())
    {
      return true;
    }
    else
     return false;
  }
};

// custom Hasher
struct CustomHash
{
  size_t operator()(const string& str) const
  {
    int size = str.length();
    return hash<int>()(size);
  }
};


int main()
{
  unordered_set<int> mySet;
  // which is equivalent to 
  // unordered_set<int, hash<int>, std::equal_to<int> > mySet;
  //--------------------------------------------------------------------------------

  // std::hash calculates the hash of primitive data types and 
  // std::equals_to internally calls == function on the passed elements for comparison. 
  // Let’s see an example of  custom hasher and comparision function.

  // If want custom comparision then we have to create it and then we also need custom hash
  // for eg: suppose I want comparison for same length string then 

//-----------------------------------------------------------------------------------
/*
Suppose, we want to create an std::unordered_set of std::string and want to store strings of unique lengths only. 
As, the default equals_to<>() function uses the == operator to compare the elements. 
But in our scenario we want to compare elements based on length i.e. two elements should be considered equal if they have the same length. 
For that we need to create our custom Comparison Function
*/
  //struct equalLength
  //{

  //};
  //----------------------------------------------------------------------------------

/*
above comparator returns true for abc and def, but there hash is different for abc and def
 So we need to create custom hasher
*/

  // struct customHash
  //{
      /// ...
  //}

  // Declare set with custom comparators and hash
  unordered_set<string, CustomHash, equalLength> setHash;

  // insert
  setHash.insert("Tejas");
  setHash.insert("Sonu");
  setHash.insert("Suyog");
  setHash.insert("Deepak");
  setHash.insert("Monu");

  for (auto& x : setHash)
  {
    cout << x;     // op: Tejas Sonu Deepak
  }

  return 0;
}