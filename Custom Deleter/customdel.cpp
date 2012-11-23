// Demonstrate the uses of a custom deleter with std::unique_ptr
// to achieve lightweight RAII resource management.

#include <memory>

// Dummy for illustration purposes.
class Output { char buffer_[1000]; };

// Dummy for illustration purposes.
class Input { public: Input(bool arg) { if (!arg) throw "Exception"; } };

// Gets RAII without the rule of three.
class Notification {
public:
    explicit Notification (bool arg)
    : outputHandler_(new Output(), &freeOutput),
      inputHandler_(new Input(arg), &freeInput) {}

private:
    static auto freeOutput (Output *output) -> void { delete output; }
    static auto freeInput  (Input  *input)  -> void { delete input;  }

    using OutputHandler = std::unique_ptr<Output, decltype(&freeOutput)>;
    using InputHandler  = std::unique_ptr<Input,  decltype(&freeInput)>;

    OutputHandler outputHandler_;
    InputHandler  inputHandler_;
};

int main ()
{
    Notification notify(true);

    // Exception safe - Output will be cleaned properly.
    Notification notify2(false);

    return 0;
}
