/* How to use Shared Pointer efficiently */

#include <iostream>
#include <memory>
using namespace std;

class City
{
public:
  City() {}
  ~City() {}

  void getMap()
  {
    cout << "Get Map details" << endl;
  }
};

int main()
{

  // 1st Approach
  City* ptr = new City();

  // creating shared pointer
  shared_ptr<City> p1(ptr); // p1 pointing to ptr    count is 1 == p1.use_count()
  shared_ptr<City> p2(ptr); // p1 pointing to ptr    count is 1 == p2.use_count()
  
  p1->getMap();
  p2->getMap();

  // 2nd Approach
  shared_ptr<City> p3(new City());  // city get created and then p3 ---- two steps involved, count becomes 1, not exception safe

  p3->getMap();

  // 3rd Approach
  shared_ptr<City> p4 = make_shared<City>(); // only one step required, exception safe
  p4->getMap();
}


// Advantages:
   // no need to delete explicitly, deleted when it goes out of scope

// Disadvantage
   // need to maintain count