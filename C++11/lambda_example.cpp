#include <iostream>
#include <vector>
#include <algorithm>

/////////////////////////////////////////////////////////////////////////
// BEFORE C++11
/////////////////////////////////////////////////////////////////////////

// Generic functor used for comparison
struct islessthan
{
	islessthan(int threshold) : _threshold(threshold) {}

	bool operator()(int value) const
	{
		return value < _threshold;
	}
private:
	int _threshold;
};
///////////////////////////////////////////////////////////////////////

int main()
{
	// Declare a vector
	std::vector<int> vec1{ 1, 2, 3, 4, 5 };

	// Find a number that's less than a given input (assume this would have been function input)
	int threshold1 = 10;
	auto it1 = std::find_if(vec1.begin(), vec1.end(), islessthan(threshold1));



	//////////////////////////////////////////////////////////////////
	// AFTER C++
	/////////////////////////////////////////////////////////////////
	std::vector<int> vec2{ 1, 2, 3, 4, 5 };

	// Find a number that's less than a given input (assume this would have been function input)
	int threshold2 = 10;
	auto it2 = std::find_if(vec2.begin(), vec2.end(), [threshold2](int value) { return value < threshold2; });
  
  return 0;
}
