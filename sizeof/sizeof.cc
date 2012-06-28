// sizeof evaluates the size of an object based on its type deduced at compile time.

#include <cstdlib>
#include <iostream>

unsigned long size(double *t)
{
    // does not work because void is not a type
    // and sizeof() works at compile time.
    return sizeof(*t);
}

int main ()
{
    double *k;
    std::cout << sizeof(k) << " " << size(k) << std::endl;
    return 0;
}
