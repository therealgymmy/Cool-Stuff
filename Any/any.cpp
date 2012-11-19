// Any
//
// A class that can contain any object.
// Similar to boost::any

#include <iostream>

class AnyVal {
public:
    virtual ~AnyVal () {}
    virtual void* value () = 0;
};

template <typename T>
class AnyValImpl : public AnyVal {
public:
    typedef T ValueType;

    AnyValImpl (const ValueType &t) : value_(t) {}

    virtual void* value () { return &value_; }

private:
    ValueType value_;
};

class Any {
public:
    template <typename T>
    Any (const T &t);
    ~Any ();

    template <typename T>
    auto
    get () -> T*
    {
        return static_cast<T*>(impl_->value());
    }

private:
    AnyVal *impl_;
};

template <typename T>
Any::Any(const T &t)
{
    impl_ = new AnyValImpl<T>(t);
}

Any::~Any ()
{
    delete impl_;
}

int main ()
{
    Any any(5);

    int *val;

    val = any.get<int>();

    std::cout << *val << std::endl;
}
