// The sum of the squares of the first ten natural numbers is,
//   1^2 + 2^2 + ... + 10^2 = 385
//
// The square of the sum of the first ten natural numbers is,
//   (1 + 2 + ... + 10)^2 = 55^2 = 3025
//   
// Hence the difference between the sum of the squares of the first ten natural
// numbers and the square of the sum is 3025 − 385 = 2640.
//
// Find the difference between the sum of the squares of the first one hundred
// natural numbers and the square of the sum.

#include <iostream>

using namespace std;

constexpr int square(int n) {
    return n * n;
}

int main() {
    int a = 0;
    for (int i = 1; i <= 100; ++i) {
        a += square(i);
    }

    int b = 0;
    for (int i = 1; i <= 100; ++i) {
        b += i;
    }
    b = square(b);

    cout << b - a << endl;
}
