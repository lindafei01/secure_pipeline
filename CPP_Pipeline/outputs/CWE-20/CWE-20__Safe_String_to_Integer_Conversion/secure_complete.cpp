#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
#include <sstream>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <limits>
#include <sstream>
#include <regex>
#include <stdexcept>

int safeStoi(const std::string& inputStr) {
    if (inputStr.empty()) {
        return 0;
    }

    size_t index = 0;
    bool isNegative = false;

    if (inputStr[index] == '+' || inputStr[index] == '-') {
        isNegative = (inputStr[index] == '-');
        index++;
    }

    if (index >= inputStr.size()) {
        return 0;
    }

    int result = 0;

    while (index < inputStr.size()) {
        char currentChar = inputStr[index];
        if (currentChar < '0' || currentChar > '9') {
            return 0;
        }

        int digit = currentChar - '0';

        if (result > (INT_MAX - digit) / 10) {
            return 0;
        }

        result = result * 10 + digit;
        index++;
    }

    return isNegative ? -result : result;
}

std::string format_output(const std::string& value) {
    return value;
}

template <typename T>
std::string format_output(const T& value) {
    using Decayed = std::decay_t<T>;
    if constexpr (std::is_same_v<Decayed, bool>) {
        return value ? "true" : "false";
    }
    if constexpr (std::is_arithmetic_v<Decayed>) {
        return std::to_string(value);
    }
    if constexpr (std::is_convertible_v<Decayed, std::string>) {
        return static_cast<std::string>(value);
    }
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string format_output(const char* value) {
    if (value == nullptr) {
        return "null";
    }
    return std::string(value);
}

std::string format_output(std::nullptr_t) {
    return "null";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv + 1, argv + argc);
    if (args.size() < 1) {
        std::cout << "Usage: <program> inputStr\n";
        return 64;
    }
    std::string inputStr_value = args[0];
    const std::string& inputStr = inputStr_value;
    auto result = safeStoi(inputStr);
    std::cout << format_output(result) << std::endl;
    return 0;
}
