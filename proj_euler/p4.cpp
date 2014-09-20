// A palindromic number reads the same both ways. The largest palindrome made
// from the product of two 2-digit numbers is 9009 = 91 × 99.
//
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <tuple>

using namespace std;

bool isPalindromic(int num) {
    string chars = to_string(num);
    for (unsigned i = 0; i < chars.size() / 2; ++i) {
        if (chars[i] != chars[chars.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    set<int> pal;
    set<tuple<int, int, int>> pal_group;
    for (int i = 999; i >= 100; --i) {
        for (int j = 999; j >= 100; --j) {
            int prod = i * j;
            if (isPalindromic(prod)) {
                pal.insert(prod);
                pal_group.insert(make_tuple(prod, i, j));
            }
        }
    }

    int i, j;
    auto itr_pal = max_element(pal.begin(), pal.end());
    auto itr_pal_group =
        find_if(
            pal_group.begin(), pal_group.end(), [&itr_pal] (auto pal_tuple) {
                int pal;
                tie(pal, ignore, ignore) = pal_tuple;
                return pal == *itr_pal;
            }
        );
    tie(ignore, i, j) = *itr_pal_group;
    cout << "Palindrome = " << *itr_pal
         << ", i = " << i
         << ", j = " << j
         << endl;
}
