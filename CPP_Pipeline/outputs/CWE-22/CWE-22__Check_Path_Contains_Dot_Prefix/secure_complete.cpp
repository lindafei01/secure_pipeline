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

bool hasDotPrefix(const std::string& path) {
    std::size_t start = 0;
    std::size_t length = path.length();

    if (length == 0) {
        // Handle empty string safely
        return false;
    }

    while (start < length) {
        std::size_t end = path.find('/', start);
        if (end == std::string::npos) {
            end = length; // move to the end if no more slashes
        }

        if (end > start && path[start] == '.') {
            return true;
        }

        start = end + 1; // move to the next component
    }

    return false;
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
    auto result = hasDotPrefix(path);
    std::cout << format_output(result) << std::endl;
    return 0;
}
