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

bool pathsEqualNormalized(const std::string& path1, const std::string& path2) {
    auto normalizePath = [](const std::string& path) {
        std::vector<std::string> parts;
        std::string token;
        for (size_t i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (!token.empty()) {
                    if (token == "..") {
                        if (!parts.empty())
                            parts.pop_back();
                    } else if (token != ".") {
                        parts.push_back(token);
                    }
                    token.clear();
                }
            } else {
                token += path[i];
            }
        }
        if (!token.empty() && token != "." && token != "..")
            parts.push_back(token);
        std::string normalized;
        for (const auto& part : parts) {
            normalized += "/" + part;
        }
        return normalized.empty() ? "/" : normalized;
    };

    return normalizePath(path1) == normalizePath(path2);
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
        std::cout << "Usage: <program> path1 path2\n";
        return 64;
    }
    std::string path1_value = args[0];
    const std::string& path1 = path1_value;
    std::string path2_value = args[1];
    const std::string& path2 = path2_value;
    auto result = pathsEqualNormalized(path1, path2);
    std::cout << format_output(result) << std::endl;
    return 0;
}
