// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>

using namespace std;

list<uint64_t> prime_factors(uint64_t n) {
    list<uint64_t> factors;

    uint64_t d = 2;
    while (n > 1) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
        d += 1;

        if (d * d > n) {
            factors.push_back(n);
            break;
        }
    }

    return factors;
}

int main() {
    list<uint64_t> pfs = prime_factors(600851475143);
    cout << *max_element(pfs.begin(), pfs.end()) << endl;
}
