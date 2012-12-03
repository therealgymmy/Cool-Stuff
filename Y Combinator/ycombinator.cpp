// A demonstration of Applicative Order Y Combinator
// Otherwise known as Z Combinator or Fixpoint Combinator

#include <functional>
#include <iostream>

auto error (int) -> int
{
    std::cout << "error: ";
    return -1;
}

auto fact_improver (std::function<int(int)> x) -> std::function<int(int)>
{
    return [x] (int n) { return n == 0 ? 1 : n * x(n-1); };
}

void lambdaExample ()
{
    auto factX = fact_improver(     // handles 0
                 fact_improver(     // handles 1
                 fact_improver(     // handles 2
                 fact_improver(     // handles 3
                 fact_improver(     // handles 4
                 fact_improver(     // handles 5
                     error
                 ))))));

    std::cout << factX(0) << std::endl;
    std::cout << factX(1) << std::endl;
    std::cout << factX(2) << std::endl;
    std::cout << factX(3) << std::endl;
    std::cout << factX(4) << std::endl;
    std::cout << factX(5) << std::endl;
    std::cout << factX(6) << std::endl; // 6 is out of reach!
}


// Y Combinator starts here

using Improver = std::function<int(int, std::function<int(int)>)>;

auto fact_base (int v, std::function<int(int)> f) -> int
{
    return v == 0 ? 1 : v * f(v - 1);
}

auto y (Improver f) -> std::function<int(int)>
{
    return std::bind(f, std::placeholders::_1, std::bind(&y, f));
}

void yCombinatorExample ()
{
    auto fact = y(fact_base);
    std::cout << fact(5) << std::endl;
    std::cout << fact(10) << std::endl;

    // This shows that fact is a fixpoint of fact_base.
    auto factFixpoint = std::bind(fact_base, std::placeholders::_1, fact);
    std::cout << factFixpoint(5) << std::endl;
}

int main ()
{
    lambdaExample();
    yCombinatorExample();
    return 0;
}
