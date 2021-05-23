**all_of()**:
This STL algorithm is useful when you have a range/array of element and you want to check if all elements in given range satisfies a given condition. It’s just opposite to std::any_of().

Example:
std::vector<std::string> wordList = { "Hi", "Hello", "Test", "First", "Second", "Third", "Fourth" };

bool result = std::all_of(wordList.begin(), wordList.end(), [](const std::string & str) {
																return str.size() == 4;
																});
																

output: result is 0
all_of() iterates over all the elements in given range and for each elements calls the given callback i.e. Unary Predicate.
If for any element then given predicate returns false then it stops the further iteration and return false, else it returns true

---------------------------------------------------------------------------------------------------------------------------------------

Example2:
int arr[] = {3,9,75,15,12};
bool result = std::all_of(arr, arr + sizeof(arr)/ sizeof(int), [](const int & i){ return i%3 == 0; });

---------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------

**any_of()**:
This STL algorithm is useful when you have a range of element and you want to check if any of the given elements in range satisfies a given condition.

Example:
std::vector<std::string> vecOfStrs =
	{ "Hi", "Hello", "test", "first", "second", "third", "fourth" };
	
bool result = std::any_of(vecOfStrs.begin(), vecOfStrs.end(), [](const std::string & str){
														return str.size() == 4;
														});
														
output: true

any_of() will iterate through all the strings in vector and for each string in vector it calls the passed lambda function, that checks if size of string is 4. If for any string the lambda function returns true, std::any_of() will stop the further iteration and returns true else it returns false.														--fsda-fsda-jkl;\jkl;\fsda-