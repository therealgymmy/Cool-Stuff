#include <cmath>
#include <iostream>

using namespace std;

//
// Because l xor r will determine the first bit that differs between l and
// r, we can extrapolate from there. we can adjust every bit after (and
// including) the first bit after they differ, so the answer for the
// maximum xor would be the next power of 2 from l xor r, minus one. 
//
// To simplify that view, you could instead say that every bit can be made
// to be 1 after the first bit that differs. So, you can take l xor r, and
// every bit after the first 1 we can replace with more 1s to get our
// answer.
//
unsigned int maxXor(unsigned int l, unsigned int r) {
    unsigned max = l ^ r;

    int i = 0;
    while (true) {
        unsigned power = pow(2, i);
        if (power > max) {
            return power - 1;
        }
        ++i;
    }
}

int main() {
    unsigned int res;
    unsigned int _l;
    cin >> _l;

    unsigned int _r;
    cin >> _r;

    res = maxXor(_l, _r);
    cout << res;

    return 0;
}
