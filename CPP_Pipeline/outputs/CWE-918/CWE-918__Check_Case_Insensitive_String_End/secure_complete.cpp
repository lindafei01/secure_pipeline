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

bool endsWithIgnoreCase(const std::string& str, const std::string& suffix) {
    if (str.size() < suffix.size()) {
        return false;
    }
    auto toLower = [](char c) { return std::tolower(static_cast<unsigned char>(c)); };
    return std::equal(suffix.rbegin(), suffix.rend(), str.rbegin(),
                      [&](char a, char b) { return toLower(a) == toLower(b); });
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
        std::cout << "Usage: <program> str suffix\n";
        return 64;
    }
    std::string str_value = args[0];
    const std::string& str = str_value;
    std::string suffix_value = args[1];
    const std::string& suffix = suffix_value;
    auto result = endsWithIgnoreCase(str, suffix);
    std::cout << format_output(result) << std::endl;
    return 0;
}
