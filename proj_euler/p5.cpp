// 2520 is the smallest number that can be divided by each of the numbers from
// 1 to 10 without any remainder.
//
// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?

#include <iostream>

using namespace std;

bool isEvenlyDivisble(int num) {
    for (int i = 1; i <= 20; ++i)
        if (num % i != 0)
            return false;
    return true;
}

int main() {
    int num = 1;
    while (true) {
        if (isEvenlyDivisble(num)) {
            cout << num << endl;
            return 0;
        }
        ++num;
    }
}
