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

    // Default comparator
     bool operator == (const Student& obj) const
    {
      if (Id == obj.Id)
        return 1;
      else
        return 0;
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

  namespace std
  {
   template<>  // specialize template use
    struct hash<Student>
    {
      size_t operator()(const Student& obj) const
      {
        return hash<int>()(obj.GetId());
      }
    };
  }

int main()
{
  std::unordered_set<Student> mySet;

  mySet.insert(Student(1, "Tejas"));
  mySet.insert(Student(2, "Sonu"));
  mySet.insert(Student(3, "Suyog"));
  mySet.insert(Student(4, "Deepak"));

  // mySet contains above entry

  // if we insert same ID then it will not insert
  mySet.insert(Student(1, "Jaywant"));

  for (auto val : mySet)
    val.DisplayInfo();

  return 0;
}