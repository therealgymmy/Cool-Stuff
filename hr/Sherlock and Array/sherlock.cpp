// https://www.hackerrank.com/challenges/sherlock-and-array

#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned int numTests;
    cin >> numTests;

    while (numTests--) {
        vector<int> numbers;

        int numNumbers;
        cin >> numNumbers;
        while (numNumbers--) {
            int num;
            cin >> num;
            numbers.push_back(num);
        }

        if (numbers.size() == 1) {
            cout << "YES" << endl;
            continue;
        }
        else if (numbers.size() == 2) {
            cout << "NO" << endl;
            continue;
        }

        int lSum = numbers[0];
        int rSum = 0;

        for (unsigned int middle = 1, right = 2;
             right < numbers.size();
             ++right) {
            rSum += numbers[right];

            while (lSum < rSum) {
                lSum += numbers[middle];
                middle += 1;
                rSum -= numbers[middle];
            }
        }

        if (lSum == rSum) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
