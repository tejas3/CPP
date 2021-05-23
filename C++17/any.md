@Tejas Sarode

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@Description: 
1) An object of class any stores an instance of any type that satisfies the constructor requirements or is empty,
and this is referred to as the state of the class any object.
The stored instance is called the contained object. 
Two states are equivalent if they are either both empty or if both are not empty and if the contained objects are equivalent.

2) The non-member any_cast functions provide type-safe access to the contained object.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <any>
#include <functional>
#include <vector>

using namespace std;

struct Store
{
   Store() = delete;
   Store(const Store& obj) = default;
}

int main() {
	
	// simple
	std::any an = 5;
	cout << std::any_cast<int>(an) <<endl;
	
	// make_any
	std::any val = make_any<int>(10);
	cout << std::any_cast<int&>(val) <<endl;

	// put lambda into any
        std::any value = [] { cout << "Hello Lambda" << endl;};
        std::any_cast<lambda>(value)();  // gcc=11.1
	
	// put lambda directly into any
	auto a3 = std::make_any<lambda>([] { std::cout << "Lambda #2.\n"; });
        std::cout << "a3.type() = \"" << a3.type().name() << "\"\n";
        std::any_cast<lambda>(a3)();     // gcc=11.1

        // putting into container
        vector<any> v = {1, 3.1, "Hello", Store()};  // Instance of Store should be copy-constructable
        cout << any_cast<int>(v[0]) <<endl;
     
	return 0;
}
