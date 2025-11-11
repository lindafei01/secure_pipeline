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

std::string canonicalizePath(const std::string& path) {
    std::vector<std::string> stack;
    std::string component;
    size_t i = 0;

    // Disallow empty path or non-absolute paths
    if (path.empty() || path[0] != '/') {
        return "";
    }

    for (size_t j = 0; j <= path.length(); ++j) {
        if (j == path.length() || path[j] == '/') {
            if (component == "..") {
                if (stack.empty()) {
                    return ""; // Attempt to move outside of root
                }
                stack.pop_back();
            } else if (!component.empty() && component != ".") {
                stack.push_back(component);
            }
            component.clear();
        } else {
            component += path[j];
        }
    }

    std::string canonicalPath;
    for (const std::string& part : stack) {
        canonicalPath += "/" + part;
    }

    return canonicalPath.empty() ? "/" : canonicalPath;
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
    auto result = canonicalizePath(path);
    std::cout << format_output(result) << std::endl;
    return 0;
}
