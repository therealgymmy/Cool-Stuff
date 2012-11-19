// Demonstrates the different behaviors of different calling (Different binding).

#include <iostream>

class Base {
public:
    void aMethod() { std::cout << "Base::aMethod" << std::endl; }
    virtual void bMethod() { std::cout << "Base::bMethod" << std::endl; }
    virtual void cMethod() { std::cout << "Base::cMethod" << std::endl; }
};

class Derived : public Base {
public:
    int i;
    void aMethod() { std::cout << "Derived::aMethod" << std::endl; }
    virtual void bMethod() { std::cout << "Derived::bMethod " << i << std::endl; }
    virtual void dMethod() { std::cout << "Derived::dMethod" << std::endl; }
private:
    virtual void cMethod() { std::cout << "Derived::cMethod" << std::endl; }
};

void foo (Base &b)
{
    b.cMethod();
}

void foo2 (Derived d)
{
    d.bMethod();
}

int main ()
{
    Base *b = new Derived();
    b->aMethod();       // Base::aMethod()
    b->bMethod();       // Derived::bMethod()
    b->cMethod();       // Derived::cMethod()
    //b->dMethod();     // Compiler Error

    Derived d;
    d.aMethod();        // Derived::aMethod()
    //d.cMethod();      // Compiler Error
    d.dMethod();        // Derived::dMethod()

    d.i = 5;
    Base b1 = d;
    b1.aMethod();       // Base::aMethod()
    b1.bMethod();       // Base::bMethod()
    b1.cMethod();       // Base::cMethod()

    Base &b1_r = d;
    b1_r.aMethod();     // Derived::aMethod()
    b1_r.bMethod();     // Derived::bMethod()
    b1_r.cMethod();     // Derived::cMethod()

    Base *b2 = new Derived();
    b2->cMethod();      // Derived::cMethod()
    (*b2).cMethod();    // Derived::cMethod()

    // Highlight..
    b2->Base::cMethod();// Base::cMethod()
    (b2->*(&Base::cMethod))();  // Derived::cMethod()
    void (Base::*func)() = &Base::cMethod;
    (b2->*func)();      // Derived::cMethod()
    //

    foo(*b2);           // Derived::cMethod()
    foo(b1);            // Base::cMethod()

    foo2(d);            // Derived::bMethod()
    foo2(*((Derived*)&b1));   // Undefined due to object slicing
    return 0;
}
