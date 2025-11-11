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
#include <utility>

std::pair<std::string, std::string> parseOption(const std::string& arg) {
    if (arg.size() < 4 || arg[0] != '-' || arg[1] != '-' || arg.find('=') == std::string::npos) {
        return {};
    }
    size_t equalPos = arg.find('=');
    std::string key = arg.substr(2, equalPos - 2);
    std::string value = arg.substr(equalPos + 1);
    if (key.empty() || value.empty()) {
        return {};
    }
    return {key, value};
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
        std::cout << "Usage: <program> arg\n";
        return 64;
    }
    std::string arg_value = args[0];
    const std::string& arg = arg_value;
    auto result = parseOption(arg);
    std::cout << format_output(result) << std::endl;
    return 0;
}
