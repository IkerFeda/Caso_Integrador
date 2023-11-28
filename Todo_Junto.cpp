#include <iostream>
#include <string>
#include <vector>
#include <map>

class Variant {
public:
    enum class Type {
        Symbol,
        Number,
        List,
        Procedure
    };

    Variant() : type(Type::Symbol), symbol("") {}
    Variant(int number) : type(Type::Number), number(number) {}
    Variant(const std::vector<Variant>& list) : type(Type::List), list(list) {}
    Variant(const std::string& procedure) : type(Type::Procedure), procedure(procedure) {}

    std::string to_string() const {
        switch (type) {
            case Type::Symbol:
                return symbol;
            case Type::Number:
                return std::to_string(number);
            case Type::List: {
                std::string result = "[";
                for (const auto& item : list) {
                    result += item.to_string() + ", ";
                }
                if (!list.empty()) {
                    result.pop_back();
                    result.pop_back();
                }
                result += "]";
                return result;
            }
            case Type::Procedure:
                return procedure;
        }
        return "";
    }

    std::string to_json_string() const {
        switch (type) {
            case Type::Symbol:
                return "\"" + symbol + "\"";
            case Type::Number:
                return std::to_string(number);
            case Type::List: {
                std::string result = "[";
                for (const auto& item : list) {
                    result += item.to_json_string() + ", ";
                }
                if (!list.empty()) {
                    result.pop_back();
                    result.pop_back();
                }
                result += "]";
                return result;
            }
            case Type::Procedure:
                return "\"" + procedure + "\"";
        }
        return "";
    }

    static Variant from_json_string(const std::string& json) {

    }

    static Variant parse_json(const std::string& json) {

    }

private:
    Type type;
    std::string symbol;
    int number;
    std::vector<Variant> list;
    std::string procedure;
};

int main() {
    Variant symbol("x");
    Variant number(42);
    Variant list({Variant("a"), Variant("b"), Variant("c")});
    Variant procedure("print");

    std::cout << symbol.to_string() << std::endl;
    std::cout << number.to_string() << std::endl;
    std::cout << list.to_string() << std::endl;
    std::cout << procedure.to_string() << std::endl;

    std::cout << symbol.to_json_string() << std::endl;
    std::cout << number.to_json_string() << std::endl;
    std::cout << list.to_json_string() << std::endl;
    std::cout << procedure.to_json_string() << std::endl;

    return 0;
}

