#include <iostream>
#include <vector>

// Check if a data type is a STL container
//  by checking if there exists an iterator type inside.
// If yes, value set to true;
// Otherwise, false.
template <typename T>
class IsContainer
{
private:
    typedef struct dummy {} true_type;
    struct false_type{ true_type _[2]; };

    template <typename U>
    static true_type has_iterator_checker(typename U::iterator *);

    template <typename U>
    static false_type has_iterator_checker(...);
public:
    static const bool value = (sizeof(has_iterator_checker<T>(NULL)) ==
                               sizeof(true_type));

};

// A function Conditional Enabler leveraging IsContainer.
template <bool Cond, typename T>
class EnableIf {
public:
    typedef T ValueType;
};

template <typename T>
struct EnableIf <false, T> {};




// Below are example uses.
typename EnableIf<true, int>::ValueType foo ()
{
    return 5;
}

template <typename T>
typename EnableIf<IsContainer<T>::value, std::string>::ValueType test (T &&t)
{
    return "this is a container";
}

template <typename T>
typename EnableIf<!IsContainer<T>::value, std::string>::ValueType test (T &&t)
{
    return "this is NOT a container";
}


int main ()
{
    typedef std::vector<int> t1;
    typedef int t2;

    std::cout << IsContainer<t1>::value << std::endl;
    std::cout << IsContainer<t2>::value << std::endl;

    std::cout << foo() << std::endl;

    std::cout << test(std::vector<int>()) << std::endl;
    std::cout << test(5) << std::endl;

    return 0;
}
