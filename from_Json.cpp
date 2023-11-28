#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <map>
#include "Clase_variant.cpp"

using Variant = variant<int, double, std::string, bool>;

class JSONConverter {
public:
    static Variant from_json_string(const std::string& jsonStr) {
    }

private:
    static Variant parse_json(const std::map<std::string, Variant>& jsonObj) {

};

int main() {
    std::string jsonString = R"(
        {
            "name": "John",
            "age": 30,
            "isStudent": true,
            "grades": [90, 85, 95],
            "address": {
                "street": "123 Main St",
                "city": "New York"
            }
        }
    )";

    Variant variantObj = JSONConverter::from_json_string(jsonString) {

        std::cout << std::get<std::string>(std::get<std::map<std::string, Variant>>(variantObj)["name"]) << std::endl;
        std::cout << std::get<int>(std::get<std::map<std::string, Variant>>(variantObj)["age"]) << std::endl;
        std::cout << std::boolalpha << std::get<bool>(std::get<std::map<std::string, Variant>>(variantObj)["isStudent"])
                  << std::endl;
        std::cout << std::get<int>(
                std::get<std::vector<Variant>>(std::get<std::map<std::string, Variant>>(variantObj)["grades"])[0])
                  << std::endl;
        std::cout << std::get<std::string>(std::get<std::map<std::string, Variant>>(
                std::get<std::map<std::string, Variant>>(variantObj)["address"])["street"]) << std::endl;

        return 0;
    }
}