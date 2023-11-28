#include <iostream>
#include <string>
#include <sstream>
#include <iostream>

class Variant {
public:
    int property1;
    int property2;
    int property3;

    std::string to_json_string() const {
        std::stringstream ss;
        ss << "{";

        ss << "\"property1\": " << property1 << ",";
        ss << "\"property2\": " << property2 << ",";
        ss << "\"property3\": " << property3;

        ss << "}";

        return ss.str();
    }
};

int main() {
    Variant variant;
    variant.property1 = 10;
    variant.property2 = 20;
    variant.property3 = 30;

    std::string json = variant.to_json_string();
    std::cout << json << std::endl;

    return 0;
}


