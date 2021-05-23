/* 
unordered_set: with user defined data with default comparator and hash
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

//*****************************************************************************

  class Student
  {
  private:
    int Id;
    std::string Name;
  public:
    Student(int x, string val) :Id(x), Name(val)
    {
    }

    string GetName() const
    {
      return Name;
    }

    int GetId() const
    {
      return Id;
    }

    void DisplayInfo()
    {
      std::cout << Id << "         " << Name << endl;
    }
  };

  // Custome Hasher
    struct hasher
    {
      size_t operator()(const Student& obj) const
      {
        return std::hash<string>()(obj.GetName());
      }
    };

    // Custom comparator
    struct Comparator
    {
      bool operator()(const Student& obj1, const Student& obj2) const
      {
        if (obj1.GetName() == obj2.GetName())
        {
          return true;
        }
        else
          return false;
      }
    };

int main()
{
  std::unordered_set<Student, hasher, Comparator> mySet;

  mySet.insert(Student(1, "Tejas"));
  mySet.insert(Student(2, "Sonu"));
  mySet.insert(Student(3, "Suyog"));
  mySet.insert(Student(4, "Deepak"));

  mySet.insert(Student(9, "Tejas"));
  mySet.insert(Student(10, "Sonu"));

  for (auto val : mySet)
    val.DisplayInfo();    //op: Tejas, Sonu, Suyog, Deepak, will not insert Tejas with Id 9 and Sonu with Id 10

  return 0;
}