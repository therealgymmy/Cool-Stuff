#include <iostream>

class SafeVault {
public:
    SafeVault () : foo_(100) {}
protected:
    // Protected? Safe? Not so much...
    int foo_;
};

int main ()
{
    SafeVault safe;

    // The following would not work,
    //  since foo_ is protected member of SafeVault.
    // std::cout << safe.foo_ << std::endl;

    // However, we can do the following...
    struct BreakSafeVault : public SafeVault {
        // Making protected member name PUBLIC!!
        using SafeVault::foo_;
    };
    // Now we can access it however we want to.
    std::cout << safe.*(&BreakSafeVault::foo_) << std::endl;

    return 0;
}
