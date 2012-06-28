// This is undefined as pointer to integer i is uninitialized and could point to any
// arbitrary address.
// So, if you're lucky that you end up in a writeable memory address, you can assign it
// with an value and cout it
// But, if not so lucky, you will end up in a non-writeable memory address, and your
// program will segfault.

#include <iostream>

using namespace std;

int main()
{
    int *i;
    *i = 12;
    cout << *i << endl;
    return 0;
}
