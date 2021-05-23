#include <iostream>
using namespace std;

struct main_lambda_0
{
    auto operator()() const
    {
        return 5;
    }
}

int main()
{
    auto p = []{ return 5;};
    cout << p << endl; 

    // auto p = main_lambda_0{}; similar to auto p = []{ return 10;};
}
