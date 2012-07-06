// Showcases an object that is capable of holding multiple function pointers,
//  and behave accordingly to the inputs.
// eg. string input do something,
//     int    input do something else.

#include <iostream>

template <typename Fcn1, typename Fcn2>
class Surrogate {
public:
    Surrogate(Fcn1 *f1, Fcn2 *f2) : f1_(f1), f2_(f2) {}

    // Implicit conversion operators
    operator Fcn1*() { return f1_; }
    operator Fcn2*() { return f2_; }

private:
    Fcn1 *f1_;
    Fcn2 *f2_;
};

void foo (int i)
{
    std::cout << "foo: " << i << std::endl;
}

void bar (double i)
{
    std::cout << "bar: " << i << std::endl;
}

int main ()
{
    Surrogate<void(int), void(double)> callable(foo, bar);

    callable(10);       // calls foo
    callable(10.1);     // calls bar

    return 0;
}
