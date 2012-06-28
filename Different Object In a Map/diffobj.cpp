// SUPER HACKY! :_p

// This is a demonstration that by using a static function as wrapper,
//  you can store distinct object's addresses in a map as keys and
//  their corresponding static functions as values, so that you can operate
//  on their member functions.

#include <iostream>
#include <map>

class A {
public:
    void print () { std::cout << "A" << std::endl; }
    static void p (void *me) { ((A*)me)->print(); }
};

class B {
public:
    void print () { std::cout << "B" << std::endl; }
    static void p (void *me) { ((B*)me)->print(); }
};

class C {
public:
    void print () { std::cout << "C" << std::endl; }
    static void p (void *me) { ((C*)me)->print(); }
};

int main ()
{
    A a;
    B b;
    C c;

    std::map<void*, void(*)(void*)> hacky;

    // Hacky!!!
    // Address to an object as key, address to function as value.
    hacky[(void*)&a] = &A::p;
    hacky[(void*)&b] = &B::p;
    hacky[(void*)&c] = &C::p;

    // Run through every object and call its function.
    for (auto &i : hacky) {
        i.second(i.first);
    }

    return 0;
}
