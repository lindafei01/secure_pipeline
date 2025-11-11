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

std::string normalizePath(const std::string& path) {
    std::vector<std::string> components;
    size_t start = 0, end;

    while ((end = path.find('/', start)) != std::string::npos) {
        std::string part = path.substr(start, end - start);
        if (!part.empty() && part != "." && part != "..") {
            components.push_back(part);
        } else if (part == "..") {
            if (!components.empty()) {
                components.pop_back();
            } else {
                return "";
            }
        }
        start = end + 1;
    }

    std::string lastPart = path.substr(start);
    if (!lastPart.empty() && lastPart != "." && lastPart != "..") {
        components.push_back(lastPart);
    } else if (lastPart == ".." && !components.empty()) {
        components.pop_back();
    } else if (lastPart == "..") {
        return "";
    }

    std::string result;
    for (const auto& comp : components) {
        result += comp + '/';
    }
    if (!result.empty()) {
        result.pop_back(); // Remove the last '/'
    }

    return result;
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
        std::cout << "Usage: <program> path\n";
        return 64;
    }
    std::string path_value = args[0];
    const std::string& path = path_value;
    auto result = normalizePath(path);
    std::cout << format_output(result) << std::endl;
    return 0;
}
