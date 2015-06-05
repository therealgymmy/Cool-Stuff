//
// The Utopian Tree goes through 2 cycles of growth every year. The first
// growth cycle occurs during the spring, when it doubles in height. The
// second growth cycle occurs during the summer, when its height increases
// by 1 meter.
//
// Now, a new Utopian Tree sapling is planted at the onset of spring. Its
// height is 1 meter. Can you find the height of the tree after N
// growth cycles?
//

#include <iostream>
#include <map>

using namespace std;

map<int, int> g_height_cache;
const int g_initial_height = 1;

int height(int n) {
    int h = g_height_cache[n];

    if (!h) {
        if (n > 0) {
            if (n & 1) {
                h = height(n - 1) * 2;
            }
            else {
                h = height(n - 1) + 1;
            }
        }
        else {
            h = 1;
        }

        g_height_cache[n] = h;
    }

    return h;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
