// https://www.hackerrank.com/challenges/connected-cell-in-a-grid

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

unsigned int largestArea(const vector<vector<char>> &grid);

void printGrid(const vector<vector<char>> &grid) {
    for (auto row : grid) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    unsigned int m, n;
    cin >> m;
    cin >> n;

    vector<vector<char>> grid;
    while (m--) {
        vector<char> row;
        unsigned int rowLength = n;
        while (rowLength--) {
            char cell;
            cin >> cell;
            row.push_back(cell);
        }
        grid.push_back(row);
    }

    cout << largestArea(grid) << endl;
}

struct Cell {
    bool filled;
    bool isVisited;
    unsigned int x;
    unsigned int y;
};

unsigned int largestArea(const vector<vector<char>> &gridInput) {

    vector<vector<Cell>> grid;
    {
        unsigned int i = 1;
        for (auto rowInput : gridInput) {
            vector<Cell> row;
            unsigned int j = 1;
            for (auto cellInput : rowInput) {
                row.push_back(Cell { cellInput - '0', false, i, j });
                ++j;
            }
            grid.push_back(row);
            ++i;
        }
    }

    auto dfsSearch =
        [&grid] (Cell &cell, unsigned int m, unsigned int n) -> int {

        unsigned int area = 0;
        deque<Cell*> filo = { &cell };
        while (!filo.empty()) {
            Cell &cell = *filo.back();
            filo.pop_back();

            if (cell.isVisited) {
                continue;
            }

            cell.isVisited = true;

            if (!cell.filled) {
                continue;
            }

            // Add all neighbours to filo
            auto addEntry =
                [&grid, &filo, m, n] (Cell &center, int x, int y) {

                x += center.x;
                y += center.y;
                if (x && x <= m && y && y <= n) {
                    filo.push_back(&grid[x - 1][y - 1]);
                }
            };

            // 1 2 3
            // 4 % 5
            // 6 7 8
            addEntry(cell, -1, -1);     // 1
            addEntry(cell, -1,  0);     // 2
            addEntry(cell, -1,  1);     // 3
            addEntry(cell,  0, -1);     // 4
            addEntry(cell,  0,  1);     // 5
            addEntry(cell,  1, -1);     // 6
            addEntry(cell,  1,  0);     // 7
            addEntry(cell,  1,  1);     // 8

            ++area;
        }

        return area;
    };

    const unsigned int m = grid.size();          // rows
    const unsigned int n = grid.front().size();  // columns
    unsigned int maxArea = 0;
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (!grid[i][j].isVisited) {
                unsigned int area = dfsSearch(grid[i][j], m, n);
                if (maxArea < area) {
                    maxArea = area;
                }
            }
        }
    }

    return maxArea;
}
