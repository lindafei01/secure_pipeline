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

bool isSafeMultiply(int a, int b) {
    if (a > 0 && b > 0) {
        return (a <= INT_MAX / b);
    }
    if (a < 0 && b < 0) {
        return (a >= INT_MAX / b);
    }
    if (a > 0 && b < 0) {
        return (b >= INT_MIN / a);
    }
    if (a < 0 && b > 0) {
        return (a >= INT_MIN / b);
    }
    return true; // When either a or b is zero
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
    if (args.size() < 2) {
        std::cout << "Usage: <program> a b\n";
        return 64;
    }
    auto a_value = std::stoi(args[0]);
    int a = static_cast<int>(a_value);
    auto b_value = std::stoi(args[1]);
    int b = static_cast<int>(b_value);
    auto result = isSafeMultiply(a, b);
    std::cout << format_output(result) << std::endl;
    return 0;
}
