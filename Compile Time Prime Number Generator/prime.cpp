// This does not work as intended...
//
// Instead of giving only prime numbers, prime<> gives arbitrary number of 1's in between
//  each prime number it outputs.
// This is in accordance to the recurrence formula by Rowland.
//
// Formula:
//  First -> a_{n} = a_{n-1} + gcd(n, a_{n-1}), a_{1} = 7
//  Then  -> 1 or prime == a_{n+1} - a_{n}

#include <iostream>

typedef const long long Big;

template <long long A, long long B>
struct GCD {
    static Big val = GCD<B, A%B>::val;
};

template <long long A>
struct GCD<A,0> {
    static Big val = A;
};

template <long long stage>
struct prime {
    static Big num = prime<stage-1>::num + GCD<stage, prime<stage-1>::num>::val;
    static Big val = num - prime<stage-1>::num;
};

// we start with 7
template <>
struct prime<0> {
    static Big num = 7;
    static Big val = 0;
};

int main ()
{
    std::cout << GCD<100, 20>::val << std::endl;
    std::cout << prime<5>::val << std::endl;
    return 0;
}
