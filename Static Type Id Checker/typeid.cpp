// Demonstrates the use of macro and template
//  to output the name of a class as defined in the source code.
// Benefits compared to typeid().name():
//  STATIC -> faster.
//  PLATFORM/COMPILER Independent -> unmangled name.

#include <iostream>
#include <string>

// Template that returns a string.
template<typename T>
std::string TYPE_ID_IMPL(const char *id) { return id; }

// Does type checking too!!
#define TYPE_ID(ID) TYPE_ID_IMPL<ID>(#ID)

class foo {};
class bar {};

int main ()
{
    std::cout << TYPE_ID(foo) << std::endl;
    std::cout << TYPE_ID(bar) << std::endl;

    // The following would not work since fdaf does not exist!
    //std::cout << TYPE_ID(fdaf) << std::endl;

    return 0;
}
