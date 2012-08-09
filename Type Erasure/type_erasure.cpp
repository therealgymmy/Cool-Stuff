#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

class Holder {
public:
    virtual const std::type_info& getTypeid () = 0;
};

template <typename T>
class HolderImpl : public Holder {
public:
    HolderImpl (T type);
    virtual const std::type_info& getTypeid ();
private:
    T type_;
};

template <typename T>
HolderImpl<T>::HolderImpl (T type)
: type_(type)
{
    // Do nothing.
}

template <typename T>
const std::type_info& HolderImpl<T>::getTypeid ()
{
    return typeid(type_);
}

/*
vector<
LinkedList<int>
LinkedList<string>
*/

int main ()
{
    Holder *integer = new HolderImpl<int>(5);
    Holder *text = new HolderImpl<std::string>("hello");

    std::vector<Holder*> holder;
    holder.push_back(integer);
    holder.push_back(text);

    return 0;
}
