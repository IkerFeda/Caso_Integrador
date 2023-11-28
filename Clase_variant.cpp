#include <iostream>
#include <vector>
#include <functional>

class Variant {
public:
    enum class Type {
        Symbol,
        Number,
        List,
        Procedure
    };

    Variant() : type(Type::Symbol), symbol("") {}

    Variant(const std::string& symbol) : type(Type::Symbol), symbol(symbol) {}

    Variant(double number) : type(Type::Number), number(number) {}

    Variant(const std::vector<Variant>& list) : type(Type::List), list(list) {}

    Variant(const std::function<void()>& procedure) : type(Type::Procedure), procedure(procedure) {}

    Type getType() const {
        return type;
    }

    std::string getSymbol() const {
        return symbol;
    }

    double getNumber() const {
        return number;
    }

    std::vector<Variant> getList() const {
        return list;
    }

    std::function<void()> getProcedure() const {
        return procedure;
    }

private:
    Type type;
    std::string symbol;
    double number;
    std::vector<Variant> list;
    std::function<void()> procedure;
};

int main() {
    Variant symbolVariant("hello");
    Variant numberVariant(42.0);
    Variant listVariant({Variant("foo"), Variant("bar"), Variant("baz")});
    Variant procedureVariant([]() { std::cout << "Hello, world!" << std::endl; });

    std::cout << "Symbol: " << symbolVariant.getSymbol() << std::endl;
    std::cout << "Number: " << numberVariant.getNumber() << std::endl;
    std::cout << "List: ";
    for (const auto& variant : listVariant.getList()) {
        std::cout << variant.getSymbol() << " ";
    }
    std::cout << std::endl;

    procedureVariant.getProcedure()();

    return 0;
}