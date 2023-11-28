#include <string>
#include <iostream>

class Variant {
public:
    Variant(int value) : m_value(value) {}

    std::string to_string() const {
        return std::to_string(m_value);
    }

private:
    int m_value;
};

int main() {
    Variant v(42);
    std::string str = v.to_string();
    std::cout << str << std::endl;
    return 0;
}
