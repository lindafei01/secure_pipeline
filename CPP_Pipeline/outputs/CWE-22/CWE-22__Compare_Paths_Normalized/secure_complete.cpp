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
    auto normalizePath = [](const std::string& path) -> std::string {
        std::vector<std::string> components;
        size_t len = path.length();
        size_t i = 0;

        while (i < len) {
            size_t start = i;
            while (i < len && path[i] != '/') i++;
            std::string component = path.substr(start, i - start);

            if (component == "" || component == ".") {
                // No operation needed for empty components or '.'
            } else if (component == "..") {
                if (!components.empty()) {
                    components.pop_back();
                }
            } else {
                components.push_back(component);
            }

            while (i < len && path[i] == '/') i++;
        }

        std::string normalized;
        for (const auto& comp : components) {
            normalized += "/" + comp;
        }
        return normalized.empty() ? "/" : normalized;
    };

    std::string normPath1 = normalizePath(path1);
    std::string normPath2 = normalizePath(path2);

    return normPath1 == normPath2;
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
