/* Before C++11

std::vector v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);

After C++11:

std::vector v = { 1, 2, 3, 4 };
*/

/* Before C++11

std::vector v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);  // not efficient at all

After C++11:

std::vector v = { 1, 2, 3, 4 };
*/

// All C++ STL container supports initializer_list

/*
int sum(const std::initializer_list<int>& list) 
{
  int total = 0;
  for (auto& e : list)
  {
    total += e;
  }

  return total;
}

auto list = { 1, 2, 3 };
sum(list); // == 6
sum({ 1, 2, 3 }); // == 6
sum({}); // == 0
*/

// Example: 
#include <iostream>
#include <vector>

class MyClass
{
public:
	MyClass(const std::initializer_list<int> &v) 
	{
		for (auto itm : v) 
		{
			mVec.push_back(itm);
		}
	}

	void print() 
	{
		for (auto itm : mVec) 
		{
			std::cout << itm << " ";
		}
	}
private:
	std::vector<int> mVec;
};

int main()
{
	MyClass m = { 1, 2, 3, 4 };
  // equivelent to MyClass m {1, 2, 3, 4}
	m.print();

	return 0;
}
