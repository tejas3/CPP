// Structure Bindings

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, string> fav_lang{
		{ "A", "Math" },
		{ "B", "Chemistry" },
	};
  
  // structure binding
	auto[x, y] = fav_lang.insert({ "C", "Physics" });

	if (y) {
		cout << "Insertion done" << endl;
	}
  
	for (const auto & [ name, lang ] : fav_lang) {

		cout << name << ":" << lang << endl;
	}
	return 0;
}
