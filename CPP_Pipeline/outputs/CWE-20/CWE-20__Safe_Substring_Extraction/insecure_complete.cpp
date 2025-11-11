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

std::string safeSubstring(const std::string& s, size_t start, size_t len) {
    if (start > s.size() || len > s.size() - start) {
        return "";
    }
    return s.substr(start, len);
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
        std::cout << "Usage: <program> s start len\n";
        return 64;
    }
    std::string s_value = args[0];
    const std::string& s = s_value;
    auto start_value = std::stoull(args[1]);
    size_t start = static_cast<size_t>(start_value);
    auto len_value = std::stoull(args[2]);
    size_t len = static_cast<size_t>(len_value);
    auto result = safeSubstring(s, start, len);
    std::cout << format_output(result) << std::endl;
    return 0;
}
