// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see 
// that the 6th prime is 13.
//
// What is the 10 001st prime number?

#include <cstdint>
#include <iostream>

using namespace std;

bool isPrime(uint64_t n) {
    for (uint64_t i = 2; i <= n / 2; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    uint64_t i = 1;
    uint64_t counter = 0;
    while (++i) {
        if (isPrime(i))
            ++counter;
        if (counter == 10001) {
            cout << i << endl;
            return 0;
        }
    }
}
