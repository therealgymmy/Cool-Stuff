#include <iostream>

template<int n>
struct fibonacci {
    static const long long value = fibonacci<n-1>::value + fibonacci<n-2>::value;
};

// base case f0 = 0
template<>
struct fibonacci<0> {
    static const long long value = 0;
};

// base case f1 = 1
template<>
struct fibonacci<1> {
    static const long long value = 1;
};

int main ()
{
    const long long i = fibonacci<46>::value;
    std::cout << i << std::endl;
    return 0;
}
