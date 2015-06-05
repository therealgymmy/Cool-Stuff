#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getListOfMinOperations(const vector<string> &words) {
    vector<int> opList;
    for (auto word : words) {
        int op = 0;
        for (int i = 0, j = word.size() - 1;
             i < j;
             ++i, --j) {
            int word_i = static_cast<int>(word[i]);
            int word_j = static_cast<int>(word[j]);
            op += abs(word_i - word_j);
        }
        opList.push_back(op);
    }

    return opList;
}

int main() {
    int numInput;
    vector<string> words;

    cin >> numInput;
    while (numInput--) {
        string input;
        cin >> input;
        words.push_back(input);
    }

    auto minOpList = getListOfMinOperations(words);
    for (auto op : minOpList) {
        cout << op << endl;
    }
}
