#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct Input {
    unsigned int money;
    vector<unsigned int> prices;
};

tuple<unsigned int, unsigned int> findPair_bruteforce(const Input &test);
tuple<unsigned int, unsigned int> findPair_twosum(const Input &test);

tuple<unsigned int, unsigned int> findPair(const Input &test) {
    // return findPair_bruteforce(test);
    return findPair_twosum(test);
}

int main(){
    unsigned int numTests;
    cin >> numTests;

    vector<Input> testCases;
    while (numTests--) {
        unsigned int money;
        unsigned int numFlavor;
        vector<unsigned int> prices;

        cin >> money;
        cin >> numFlavor;
        while (numFlavor--) {
            unsigned int price;
            cin >> price;
            prices.push_back(price);
        }

        testCases.push_back( Input { money, prices } );
    }

    for (auto test : testCases) {
        unsigned int first;
        unsigned int second;
        tie(first, second) = findPair(test);
        cout << first << " " << second << endl;
    }
}

tuple<unsigned int, unsigned int> findPair_bruteforce(const Input &test) {
    const vector<unsigned int> &prices = test.prices;
    unsigned int i, j;
    for (i = 0; i < prices.size() - 1; ++i) {
        for (j = i + 1; j < prices.size(); ++j) {
            if (test.money == prices[i] + prices[j]) {
                return make_pair(i + 1, j + 1);
            }
        }
    }

    return make_pair(0, 0);
}

tuple<unsigned int, unsigned int> findPair_twosum(const Input &test) {
    unsigned int money = test.money;
    vector<tuple<unsigned int, unsigned int>> prices;
    for (unsigned int i = 0; i < test.prices.size(); ++i) {
        prices.push_back(make_tuple(i + 1, test.prices[i]));
    }

    // remove all prices >= sum
    prices.erase(
        remove_if(prices.begin(), prices.end(),
            [money] (auto p) { return get<1>(p) >= money; }),
        prices.end());

    // sort remaining prices
    sort(prices.begin(), prices.end(),
        [] (auto p1, auto p2) { return get<1>(p1) < get<1>(p2); });

    for (unsigned int i = 0, j = prices.size() - 1;
         i < j;) {
        unsigned int sum = get<1>(prices[i]) + get<1>(prices[j]);
        if (sum == money) {
            return make_pair(get<0>(prices[i]), get<0>(prices[j]));
        }
        else if (sum < money) {
            ++i;
        }
        else {
            --j;
        }
    }

    return make_pair(0, 0);
}
