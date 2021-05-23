// Variadic Template

/*
way to write functions that take an arbitrary number of arguments
and have all the argument handling logic resolved at compile-time, 
rather than run-time.
Variadic templates can be used for much more than just functions that take an arbitrary number of arguments.
*/

#include <iostream> 
#include <string>
using namespace std;

// To handle base case of below recursive 
// Variadic function Template 
void display()
{
}

// Variadic function Template that takes variable number of arguments 
template <typename T, typename... Types>
void display(T var1, Types... var2)
{
	cout << var1 << '\n';
	display(var2...);
}
 
int main()
{
	display(1, 2, 3.14, "Hello", 'T');//
	return 0;
}
