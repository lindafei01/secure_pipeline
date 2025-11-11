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

int safeVectorAccess(const std::vector<int>& vec, int index, int defaultValue) {
    if (index >= 0 && index < vec.size()) {
        return vec[index];
    }
    return defaultValue;
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
    if (args.size() < 3) {
        std::cout << "Usage: <program> vec index defaultValue\n";
        return 64;
    }
    auto vec_value = std::stoi(args[0]);
    const std::vector<int>& vec = static_cast<std::vector<int>>(vec_value);
    auto index_value = std::stoi(args[1]);
    int index = static_cast<int>(index_value);
    auto defaultValue_value = std::stoi(args[2]);
    int defaultValue = static_cast<int>(defaultValue_value);
    auto result = safeVectorAccess(vec, index, defaultValue);
    std::cout << format_output(result) << std::endl;
    return 0;
}
