// https://www.hackerrank.com/challenges/connected-cell-in-a-grid

#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned int m, n;
    cin >> m;
    cin >> n;

    vector<vector<char>> grid;
    while (m--) {
        vector<char> row;
        while (n--) {
            char cell;
            cin >> cell;
            row.push_back(cell);
        }
        grid.push_back(row);
    }
}
