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

bool isSafeAdd(int a, int b) {
    if (b > 0 && a > INT32_MAX - b) {
        return false;
    }
    if (b < 0 && a < INT32_MIN - b) {
        return false;
    }
    return true;
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
    auto result = isSafeAdd(a, b);
    std::cout << format_output(result) << std::endl;
    return 0;
}
