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
#include <set>

bool hasPathTraversal(const std::string& argument) {
    if (argument.empty()) {
        return false;
    }

    // Check for any instances of path traversal patterns
    if (argument.find("..") != std::string::npos) {
        return true;
    }

    // Check for absolute paths
    #ifdef _WIN32
    // Windows absolute paths
    if ((argument.length() > 1 && argument[1] == ':' && (argument[0] >= 'A' && argument[0] <= 'Z' || argument[0] >= 'a' && argument[0] <= 'z')) ||
        (argument.substr(0, 2) == "\\\\")) {
        return true;
    }
    #else
    // Unix/Linux absolute path
    if (argument[0] == '/') {
        return true;
    }
    #endif

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
        std::cout << "Usage: <program> argument\n";
        return 64;
    }
    std::string argument_value = args[0];
    const std::string& argument = argument_value;
    auto result = hasPathTraversal(argument);
    std::cout << format_output(result) << std::endl;
    return 0;
}
