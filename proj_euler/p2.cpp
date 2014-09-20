// Problem 2
// ---------
//
// Each new term in the Fibonacci sequence is generated by adding the previous
// two terms. By starting with 1 and 2, the first 10 terms will be:
//
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
// By considering the terms in the Fibonacci sequence whose values do not exceed
// four million, find the sum of the even-valued terms.

#include <cassert>
#include <cmath>
#include <iostream>
#include <map>

using namespace std;

constexpr int INT_4_MILLION = 4000000;

int fib(const int n) {
    assert(n > 0);

    static map<int, int> fibCache;

    auto &cachedVal = fibCache[n];

    if (cachedVal != 0)
        return cachedVal;

    cachedVal = n == 1 ? 1
        :       n == 2 ? 2
        :       fib(n - 1) + fib(n - 2);

    return cachedVal;
}

int even_sum() {
    int sum = 0;

    for (int i = 0, val = 0; val < INT_4_MILLION;
            ++i, val = fib(i)) {
        if (!(val & 1))
            sum += val;
    }

    return sum;
}

int main() {
    cout << even_sum() << endl;
}