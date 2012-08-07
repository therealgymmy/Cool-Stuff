// Some convenient things you can do with STL.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main ()
{
    // Attaches an istream_iterator to cin.
    std::istream_iterator<int> cin_it(std::cin);
    std::istream_iterator<int> eos;

    // Copy inputs into vector until the end of file.
    std::vector<int> vec(cin_it, eos);
    std::reverse(vec.begin(), vec.end());

    // Attaches an ostream_iterator to cout.
    // The second parameter " " is a nice separator to separate output.
    std::ostream_iterator<int> cout_it(std::cout, " ");

    // Copy all content from vector into cout.
    std::copy(vec.begin(), vec.end(), cout_it);

    return 0;
}
