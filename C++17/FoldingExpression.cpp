//Before c++17
auto C11_sum()
{
    return 0;
}
 
// Template Class
template<typename T1, typename... T>
auto C11_sum(T1 s, T... ts)
{
    return s + C11_sum(ts...);
}

//##########################################################################
//After C++
//##########################################################################
// Template Class
template<typename... Args>
auto sum(Args... args)
{
    return (args + ... + 0);
}
 
template <typename... Args>
auto sum2(Args... args)
{
    return (args + ...);
}
 
// Driver Code
int main()
{
    // Function Calls
    cout << sum(11, 22, 33, 44, 55)
         << "\n";
     
    cout << sum2(11, 22, 33, 44, 55)
         << "\n";
 
    return 0;
}
